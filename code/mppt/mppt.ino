// include the library code:
#include <Wire.h>
#include <I2cController.h>
#include <EEPROM.h>


//I2cController vars definition
I2cControllerLib contr(0x20); // Connect via i2c, default address #0 (A0-A2 not jumpered)
#define EN_A 1      // Encored scroll A0
#define EN_B 2      // Encoder scroll A1 
#define EN_C 0      // Encoder click  A2
#define POTDIVIDER 4    // Encoder tick divider for sensibilty regulation
#define BTN_NUM 5     // Number of buttons
#define BTN_1 3     // Single button A3
#define BTN_2 4     // Single button A4
#define BTN_3 5     // Single button A5
#define BTN_4 6     // Single button A6
#define BTN_5 7     // Single button A7
#define CONTR_NOEVENT  0  // No event detected
#define CONTR_SCROLL 1    // Encoder movement detected -Z > read Pot value
#define CONTR_CLICK  2    // Encoder click detected 
#define CONTR_BTN    3    // Button pressed


// Arduino Pin definition
#define ZEROCINTPIN 2 //Interrupt pin used by zero crossing detector circuit	DO NOT CHANGE
#define MCPINTPIN 3 //Interrupt pin used by I2C controller (MCP23107)    		DO NOT CHANGE

#define DEBUGLED      13 



//Interrupts vars
byte MCPIntPin = MCPINTPIN; // Interrupts from the MCP will be handled by this PIN on Arduino
byte arduinoMCPInterrupt = 1; // ... and this interrupt vector
byte ZeroCIntPin = ZEROCINTPIN; // Interrupts from zero crossing circuit
byte arduinoZeroCInterrupt = 0; // ... and this interrupt vector
volatile boolean awakenByMCPInterrupt   = false;  
unsigned long lastMillisInterrupt = 0;
uint8_t phaseCounter=0;   //increment at every phase zero crossing at 100 (=1 sec)  increment opTime




//Menu and display vars
#define MENU_HOME 0
#define MENU_TITLES 12 
int menu=MENU_HOME;
int menudec,menuunit;
int menuold=-1;
int Pot;
/*
   First char convention for menu voice handling:
   x=empty voice -> skip next level or (for last) home
   v=scroll -> next voice on right or left, click -> next voice down (default)
   h=goto home on click
   m=modify value, scroll adjust value, click save
   n=nothing used for home and menu titles used as spacer
   a=apply and go to home
 */
const char *menuvoice[MENU_TITLES][12]=
{
  {"nHome"},                          //00
  {"nSetMen1",	"vTest0",	"vTest1" ,	"vTest2"	"hExit"	},		//10,11,12..
  {"nSetMen2",	"vTest3",	"vTest4",	"hExit"},  					//40,41..
};
char menuDisplay[16] = "";



void handleMCPInterrupt() {
  detachInterrupt(arduinoMCPInterrupt);
  //  if (millis()>lastMillisInterrupt+5) {
  //A    |¯¯|__|¯¯|__|¯
  //B  - __|¯¯|__|¯¯|__  +
  // Nel canale A pin D3 condensatore ceramico 103K 10nF
  uint8_t ActEnc=0, OldEnc=0;
  uint8_t intPin=contr.getLastInterruptPin();
  uint8_t valPin=contr.getLastInterruptPinValue();
  //Switch che  decide come gestire interrupt in base al pin che lo ha generato se A0 o A1 uint8_terpreta encoder altrimenti uint8_terpretazione come pulsante
  switch(intPin) {
    case EN_A:
    case EN_B:
      Pot=0;
      bitWrite(ActEnc, 0,contr.digitalRead(EN_A)); //Read current value of pin and set ActEnc var
      bitWrite(ActEnc, 1,contr.digitalRead(EN_B)); //Read current value of pin and set ActEnc var
      switch(ActEnc) {
        case 0: //00
          if(OldEnc==2) ticPot++;  //10
          if(OldEnc==1) ticPot--;  //01
          break;
        case 1: //01
          if(OldEnc==0) ticPot++;  //00
          if(OldEnc==3 ) ticPot--;  //11
          break;
        case 2: //10
          if(OldEnc==3) ticPot++;  //11
          if(OldEnc==0 ) ticPot--;  //00
          break;
        case 3: // 11
          if(OldEnc==1) ticPot++;  //01
          if(OldEnc==2 ) ticPot--;  //10
          break;
      }
      OldEnc=ActEnc;
      if (ticPot >= PotDivider) {
        Pot++;
        ticPot=0;
      } else if (ticPot <= -PotDivider)  {
        Pot--;
        ticPot=0;
      } 
      controllerEvent=CONTR_SCROLL;
      break;
    case EN_C:
      if (valPin) {
        //Serial.print("click ");
        controllerEvent=CONTR_CLICK;
        clickcount++;
        //Serial.println(clickcount);
      }
      break;
    default:
      if (millis() > lastMillisInterrupt+10) {
        //Serial.print("Button: A");
        //Serial.println(intPin);
        controllerEvent=CONTR_BTN;
#ifndef STARTSTOP
        if (intPin==4) {  //Use button as start welding controller
          StartStop=1;
        }                    
        if (intPin==6) {  //Use button as stop welding controller
          StartStop=0;
        }                    
#endif
      }
      break;
  }

  //  }


  lastMillisInterrupt=millis();
  cleanMCPInterrupts();
  //we set callback for the arduino INT handler.
  attachInterrupt(arduinoMCPInterrupt, MCPintCallBack, FALLING);
}

