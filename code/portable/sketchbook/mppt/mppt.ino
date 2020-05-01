/*
  Solar Panel Perfornmance Logger 
  This project is a combination between a MPPT and a data Logger.
  The power stage and the Sw management come from the solar battery charger  http://www.timnolan.com/.
  The controller charge a battery to run the data logger also during the night, all the power genereate
  from the solar panel is waste on a resistence of 10H in downstream of the power stage.
  This test is to log th eperformance of the solar panel during the day, 
  all the data are writhe on Sd card in csv format 
*/
#include <Arduino.h>
#include <SPI.h>
//#include <SD.h>
#include <Fat16.h>
//#include <Fat16util.h> // use functions to print strings from flash memory

#include <Wire.h>   //SDA=A4 SCL=A5
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include <TimerOne.h>

#include <main.h>

SdCard card;
Fat16 file;

//-------Alarm Led Blink Pattern-------
#define Pattern_No_All	2500
#define Pattern_All1    1000
#define Pattern_All2    500
#define Pattern_All3    200

//-----------Project Setting-------------
//#define SystemLog		  1     //Enable of System Log on external eprom
//#define FDebug           // Enable Fast Debug
//#define SDebug           // Eneble Time Debug

//-----------Timer Setting-------------
#define TDebug      1000  // Time of debug
#define TLcd        1000  // Time Lc 
#define TLog        5000       
#define TDelPw      20000
//------------Main LCD Mng-----------
#define TPatAll     30000 // Time of led alarm indication 
#define TExitMenu  	30000 // Time for auto-exit menu 

#define SelPatt		  	50      // Selection minimal time 
#define EntPatt			1500    // Enter
#define TPulButt		100     // Time for auto toogles button  
#define MenuPage		4       // Number of page in Menu 
#define VisuPageMax		2
#define VisuPageMin		0 
#define AvgNum			  8



//---------MPTT Parameter------------
#define MinSolVolt	8000
#define LowSolVolt	11000
#define MaxSolVolt	28000
#define MinSolWatt	20000
#define TCtrl	    20
#define AOffSet		0
#define UpLimVOTH	1500
#define DwLimVOTH	300
#define VInMin      1500

#define PwmMin      0
#define PwmMax      820
int TimeTS =0;
#define TTS         2000/TCtrl    //2 seconds


//---------LCD I2C Addres and pinout---
#define EEPROM_ADDR		0x50
#define LCD_I2C_ADDR	0x20
#define DS1307_ADDR		0x68
#define BACKLIGHT_PIN	3
#define En_pin			  2
#define Rw_pin			  1
#define Rs_pin			  0
#define D4_pin			  4
#define D5_pin			  5
#define D6_pin			  6
#define D7_pin			  7

//----------Arduino PinOut-------------
#define EdButt      	2
#define UpButt      	3
#define DwButt      	5
#define LedR      		6
#define LedY      		7
#define LedG      		8 
#define LedR_BIn    	A7
#define chipSelect		4
#define PwmConv			  9
#define PwmConvEn		  10
#define PanelVoltag		A0
#define PanelCurrent	A1
#define OutConvVoltage	A2

//----------EEPROM Data storage----
#define M_PowreOnEn     1
#define M_VOutThrHold   2 
#define M_VOutThrHold1  3
#define M_DynamicTH     4

String Filename = "MPTT.csv";

#if defined SDebug
unsigned long TimeDeb  = 0;      //Debug Time
#endif
unsigned long TimeLcd    = 0;      //Update LCD Time
unsigned long TimeBlink  = 0;
unsigned long TimePatt = 0;
unsigned long TimeEdButt = 0;
unsigned long TimeUpButt = 0;
unsigned long TimeDwButt = 0;

unsigned long TimeMenu=0;
unsigned long TimeLog=0;
unsigned long TimePulseUp = 0;
unsigned long TimePulseDw  = 0;
unsigned long TimeCtrl =0;
unsigned long TimeDelPw=0;

byte DataTime[7];
byte SetDataTime[7];
char buffer[40];
char FileName[14];
//byte SerAll[3];

unsigned int Pattern = Pattern_No_All;
int SetData, SetDataOld;
int VIn, AIn, PIn, VOut; 
int POut;
int PWM, Test, PwmDisp;
int VOutTH;

//int j;
char EditState = 0;
char Menu = 0;
char MenuOld = 0;
char i = 0;
char Cursor, OldCursor;
char Sample;
char UpButtState, DwButtState;
char SerCount;
char VisuPage, VisuPageOld;

bool AllReady  = 0;
bool PattAllOn = 0;
bool EditMode  = 0;
bool InitEdit  = 0;
bool PowerOnEn =0;
bool PwAutoStart =0;
bool DynamcTH   =0;


LiquidCrystal_I2C lcd(LCD_I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

void(* resetFunc) (void) = 0;   //Reset SW

char ButtonState(char PinN, unsigned long *Time, bool Pulse = 0 , unsigned long *Time1 = 0) {
  if ((*Time==0) && !digitalRead(PinN))  *Time = millis();
  if (Pulse && !digitalRead(PinN) && ((millis() -*Time) > (EntPatt * 3 )))  {
    if (*Time1 == 0 ) *Time1 = millis();
    if ((millis() - *Time1)>TPulButt) {
      *Time1 = millis();
#if defined FDebug
      Serial.print("3 ");
#endif
      return 1;
    }
  }
  if (Pulse && digitalRead(PinN)) *Time1 = 0;
  if (digitalRead(PinN) && (*Time)) {
    if ((millis() - *Time)> EntPatt) {
      *Time = 0;
#if defined FDebug 
      Serial.println("2");
#endif
      return 2;
    }
    if ((millis() - *Time)> SelPatt) {
      *Time = 0;
#if defined FDebug 
      Serial.println("1");
#endif
      return 1;
    }
    return 0;
  }  
  else return 0;
}

int ReadAdc(int channel){
  int sum = 0;
  i=0;
  for (i=0; i<AvgNum; i++) {            // loop through reading raw adc values AvgNum number of times  
    sum += analogRead(channel);          // read the input pin  store sum for averaging
    delayMicroseconds(50);              // pauses for 50 microseconds  
  }
  return(sum / AvgNum);                // divide sum by AvgNum to get average and return it
}

#if defined SDebug
void Debug() {
  //digitalWrite(LedG, !(digitalRead(LedG)));
  Serial.println("debug");
  //Serial.println(Pattern, DEC);
}
#endif

byte DecToBcd(byte val) {
  return (((val / 10) << 4) + (val % 10));
}

byte BcdToDec(byte val) {
  return (((val >> 4) * 10) + (val & 0b1111) );
}

boolean GetDateTime(uint8_t *Array, char Len) {
  Wire.beginTransmission(DS1307_ADDR);			// init the transmission starting from the address 0x00
  Wire.write(0x00);
  Wire.endTransmission();                // requires 7 bytes to the devicese with the address indicated the DS1307 uses 56 bits to record the date / time
  Wire.requestFrom(DS1307_ADDR, 7);
  if (Wire.available())
  {
    *(Array + 6) = BcdToDec(Wire.read());
    *(Array + 5) = BcdToDec(Wire.read());
    *(Array + 4) = BcdToDec(Wire.read() & 0b111111); 	// 24 hours mode I consider the first 6 bits
    *(Array + 3) = Wire.read(); 						// I do not need to convert (Range da 1 a 7 => 3 bit)
    *(Array + 2) = BcdToDec(Wire.read());
    *(Array + 1) = BcdToDec(Wire.read());
    *Array = BcdToDec(Wire.read());
    return true;
  }
  return false;
}


void SendDateTime(uint8_t *Array) {
  Wire.beginTransmission(DS1307_ADDR); 					// the first byte sent establishes the initial register on which to write
  Wire.write(0x00);
  for ( i = 7; i != 0; i--) {
    Wire.write(DecToBcd(*(Array + i - 1)));
  }
  Wire.write(0x00);
  Wire.endTransmission();
}

boolean CtrlData(byte dd, byte mm, byte yy) {
  uint8_t GGMese[12] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };
  if ((mm < 1) || (mm > 12)) return false;						 // Is not a mounth
  if (yy % 4 == 0) GGMese[1] = 29; 								 // leap year
  if (dd < 1 || dd > GGMese[mm - 1]) return false;
  return true;
  
}

void writeNumber(uint32_t n) {
  uint8_t buf[10];
  uint8_t i = 0;
  do {
    i++;
    buf[sizeof(buf) - i] = n%10 + '0';
    n /= 10;
  } while (n);
  file.write(&buf[sizeof(buf) - i], i); // write the part of buf with the number
} 

void InitSD(){
  //----------------Fat16-----------
   // initialize the SD card
  if (!card.begin(chipSelect)) {
   #if defined FDebug
    Serial.println("card.begin");
    #endif
    Pattern = Pattern_All3;
  }
  // initialize a FAT16 volume
  if (!Fat16::init(&card)) {
    #if defined FDebug
    Serial.println("Fat16::init");
     #endif
    Pattern = Pattern_All3;
  }
  // create a new file or append if just exist
  sprintf(FileName,"%02d%02d%d.txt", DataTime[0], DataTime[1], DataTime[2]);
  // O_CREAT - create the file if it does not exist
  // O_EXCL - fail if the file exists
  // O_WRITE - open for write
  // O_APPEND  - to continue to write existing file
  file.open(FileName, O_CREAT | O_APPEND | O_WRITE);
  
}

void setup() {
  pinMode(EdButt, INPUT_PULLUP);
  pinMode(UpButt, INPUT_PULLUP);
  pinMode(DwButt, INPUT_PULLUP);
  pinMode(LedR, OUTPUT);
  pinMode(LedY, OUTPUT);
  pinMode(LedG, OUTPUT);
  pinMode(PwmConv, OUTPUT);
  pinMode(PwmConvEn, OUTPUT);
  
  analogReference(DEFAULT);
  
  while(VIn < 800){
    delay(Pattern_All3);
    digitalWrite(LedR, (digitalRead(LedR ) ^ 1));
    VIn = map(ReadAdc(PanelVoltag),0,1023,0, 3000);
  }
  Serial.begin(115200);
#if defined FDebug
  Serial.println("MPPT Msystem");
#endif  
  Wire.begin();
  lcd.begin(16, 2);
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.setCursor(2, 0);
  lcd.print("Msystem MPPT");
  lcd.setCursor(1, 1);
  lcd.print(__DATE__);
  delay(1000);  

  for (i=1;i<=16;i=i<<1){				//LampTest
	digitalWrite(LedR, bitRead(i, 0));
	digitalWrite(LedY, bitRead(i, 1));
	digitalWrite(LedG, bitRead(i, 2));
	digitalWrite(LedR_BIn, bitRead(i, 3));
	delay(200); 
  }
  lcd.clear();
  lcd.setBacklight(LOW);
  PowerOnEn =  bitRead(EEPROM.read(M_PowreOnEn), 0);
  VOutTH = EEPROM.read(M_VOutThrHold1);
  VOutTH = (VOutTH <<8)+ EEPROM.read(M_VOutThrHold);
  DynamcTH= bitRead(EEPROM.read(M_DynamicTH), 0);
  if (! GetDateTime(&DataTime[0], 6)) {
#if defined FDebug
    Serial.println("RTC Fault");
#endif
    Pattern = Pattern_All3;
  }
  else {
#if defined FDebug
    Serial.println("RTC Running");
#endif
    //Pattern = Pattern_No_All;
  }
//---------------Fat32----------------
// #if defined FDebug
//   Serial.print("Init SD card...");
// #endif
//   if (!SD.begin(chipSelect)) {
// #if defined FDebug
//     Serial.println("Sd Inti Error");
// #endif
//     Pattern = Pattern_All3;
//   }
// #if defined  FDebug
//   else Serial.println("Done");
// #endif  
//   //Controllo nome  e generazione di unnuovo file
//   for (i = 0; SD.exists(Filename); i++)Filename = ("MPPT" + String(i, DEC) + ".csv");
// #if defined FDebug
//   Serial.println(Filename);
// #endif
  //File dataFile = SD.open(Filename, FILE_WRITE);
  // if (dataFile) {
  //   dataFile.println("MPPT Msytem");
  //   dataFile.close();
  // }

  InitSD();
  if (!file.isOpen()) Serial.println("file.open");
  #if defined FDebug
  Serial.println("Writing to: ");
  Serial.println(FileName);
  #endif
  sprintf(buffer,  "%02d:%02d:%02d-Init", DataTime[4], DataTime[5], DataTime[6]);
  file.println(buffer);
  //file.println("Init");
  file.close();
  #if defined FDebug
  Serial.println("Done");
  #endif
//  //registri TMR1 per pilotare i PWM a 16 MHz
//  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM11) | _BV(WGM10);
//  TCCR1B = _BV(CS12);
  Timer1.initialize(20);               // initialize timer1, and set a 20uS period
  Timer1.pwm(PwmConv, 0);              // setup pwm on pin 9, 0% duty cycle
  digitalWrite(PwmConvEn, LOW);    
      
}


void loop() {
#if defined SDebug
  //------------Time Debug Mng---------
  if ((millis()-TimeDeb)>TDebug) {
    TimeDeb = millis();
    Debug();
  }
#endif  

  if((millis() - TimeCtrl)>TCtrl){
     TimeCtrl = millis();
     VIn = map(ReadAdc(PanelVoltag),0,1023,0, 3000);
     AIn = map((ReadAdc(PanelCurrent)- AOffSet),0,1023,0,4450);
     //AIn = (ReadAdc(PanelCurrent));
     VOut = map(ReadAdc(OutConvVoltage),0,1023,0,3000);
     
    if(PowerOnEn){
       if(!digitalRead(PwmConvEn)) {
        digitalWrite(PwmConvEn, HIGH);
       //PWM = 300;
        PWM = map ((VOutTH/(VIn/100)),0,100,0,1023);
        digitalWrite(LedG, HIGH);
        InitSD();
        if (!file.isOpen()) Pattern = Pattern_All3;
        //Timer1.setPwmDuty(PwmConv,PWM);
        PwAutoStart =0; 
       }
      //  if(DynamcTH){
      //   if ((VIn < (VInMin + 50))&&(VOutTH > DwLimVOTH))  VOutTH -=1;	
      //   if ((VIn > (VInMin + 20))&&(VOutTH < UpLimVOTH))  VOutTH +=1;	
      //  }
      //if((VOut < (VOutTH-50)||(VOut > (VOutTH+50)))) PWM = map ((VOutTH/(VIn/100)),0,100,0,PwmMax); 
      if((VOut < (VOutTH - 2)) && (PWM < PwmMax)) PWM +=1;
      if((VOut > (VOutTH + 2)) && (PWM > 1)) PWM -=1;
      if (PWM>PwmMax) PWM = PwmMax;
      Timer1.setPwmDuty(PwmConv,PWM);
      if(PWM >= PwmMax){
        TimeTS++;
        if (TimeTS >= TTS){
          TimeDelPw= millis();
          PowerOnEn=0;
          PwAutoStart =1;
        }
      }else TimeTS =0;          

      //  if((VIn>VInMin)&&((millis()-TimeDelPw)>TDelPw)){
      //     Timer1.setPwmDuty(PwmConv,PWM); 
      //  }
      //  else{
      //    TimeDelPw= millis();
      //    PowerOnEn=0;
      //    PwAutoStart =1;
      //  }             
      }
  }
  if(!PowerOnEn){
     PWM = 0;
     digitalWrite(LedG, LOW);
     digitalWrite(PwmConvEn, LOW);    
     Timer1.setPwmDuty(PwmConv,0); 
     file.close();  
     TimeTS=0;           
  }  
  
  if(PwAutoStart && ((millis()-TimeDelPw)>TDelPw) && (VIn >VInMin))  PowerOnEn = 1;

   //----------SD logging------------
   if(PowerOnEn && ((millis()-TimeLog)>TLog)){
     TimeLog=millis();
     sprintf(buffer,"%02d:%02d:%02d;%04d;%04d;%03d;%04d;%04d",DataTime[4], DataTime[5], DataTime[6],VIn,AIn,PwmDisp,VOut,POut);
     file.println(buffer);
   }

   //---------Red Led Program State-----
  if ((millis()-TimeBlink)>Pattern) {
    digitalWrite(LedR, (digitalRead(LedR ) ^ 1));
    if ((Pattern != Pattern_No_All) && !PattAllOn) {
      TimePatt = millis();
      PattAllOn = 1;
      Serial.println("ALL");
    }
    else TimeBlink = millis();

    if ((millis()- TimePatt)>TPatAll) {
      Pattern = Pattern_No_All;
      PattAllOn = 0;
    }
  }
//------------Main LCD Mng-----------
  if ((Menu == 0) && (((millis()-TimeLcd)> TLcd) || (VisuPage != VisuPageOld))) {
    TimeLcd = millis();
    GetDateTime(&DataTime[0], 6);
    if (VisuPage > VisuPageMax) VisuPage = VisuPageMin;
    lcd.clear();
    VisuPageOld = VisuPage;
     
    int Dat= VOut/10;
    POut= ((Dat * Dat )/10);

    if(DynamcTH && PowerOnEn){
        if ((VIn < (VInMin + 50))&&(VOutTH > DwLimVOTH))  VOutTH -=1;	
        if ((VIn > (VInMin + 20))&&(VOutTH < UpLimVOTH))  VOutTH +=1;	
       }
    
    switch(VisuPage){
    case 0:
      sprintf(buffer,"VI=%04d AI=%04d",VIn,AIn);
      lcd.setCursor(0, 0);
      lcd.print( buffer );
      PwmDisp = map(PWM,0,PwmMax,0,100);
      sprintf(buffer,"PWM=%03d VO=%04d",PwmDisp, VOut);
      lcd.setCursor(0, 1);
      lcd.print( buffer );
    break;
    case 1:
      sprintf(buffer,"PO=%4d VOT=%4d",POut,VOutTH);
      lcd.setCursor(0, 0);
      lcd.print( buffer );
    break;
    case 2:
      sprintf(buffer,  "%02d/%02d/%d", DataTime[2], DataTime[1], DataTime[0]);
      lcd.setCursor(4, 0);
      lcd.print( buffer );
      //buffer[10] = 0;
      sprintf(buffer,  "%02d:%02d:%02d", DataTime[4], DataTime[5], DataTime[6]);
      lcd.setCursor(4, 1);
      lcd.print( buffer );
    break;
    }
}
   //---------Menu Mng Edit Mode---------

  EditState = ButtonState(EdButt, &TimeEdButt);
  UpButtState = ButtonState(UpButt, &TimeUpButt , 1 , &TimePulseUp);
  DwButtState = ButtonState(DwButt, &TimeDwButt , 1, &TimePulseDw);

  if (( EditState) || (UpButtState) || (DwButtState)) {
    TimeMenu = millis();
    lcd.setBacklight(HIGH);
  }
  if (TimeMenu && ((millis() - TimeMenu)>TExitMenu))  {
    TimeMenu=0;
    Menu = 0;
    EditMode = 0;
    InitEdit = 0;
    VisuPageOld=0;
    Cursor = 0;
    lcd.noBlink();
    lcd.setBacklight(LOW);
  }

  if ((EditState == 1) && (EditMode == 0)) Menu += 1;
  if ((Menu == 0) && (UpButtState )) VisuPage +=1;
  if ((Menu == 0) && (DwButtState)) PowerOnEn = !PowerOnEn;
  if ((EditState == 2) && Menu && (EditMode == 1)) {        //Parameter saving and date-time consistency check
    if (Menu == 1) {
      if (CtrlData(SetDataTime[2], SetDataTime[1], SetDataTime[0])) {  //Coherent date control
        SendDateTime(&SetDataTime[0]);
        goto SaveOk;
      }
      else goto SaveFault;
    }
     if (Menu == 2) {
       PowerOnEn = SetData;
       EEPROM.write(M_PowreOnEn, PowerOnEn);
       goto SaveOk;
     }
     if (Menu == 3) {
       VOutTH = SetData;
       EEPROM.write(M_VOutThrHold, VOutTH);
       EEPROM.write(M_VOutThrHold1,VOutTH>>8);
       goto SaveOk;
     }
     if (Menu == 4) {
       DynamcTH = SetData;
       EEPROM.write(M_DynamicTH, DynamcTH);
       goto SaveOk;
     }
    
SaveOk:
    lcd.setCursor(14, 1);
    lcd.print("Ok");
#if defined FDebug
    Serial.print("OK");
#endif
    TimeLcd = millis();       //delay the LCD refresh
     goto Exit;
SaveFault:
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Errore Data");
#if defined FDebug
    Serial.print("Errore Data");
#endif
    TimeLcd = millis();
    Pattern = Pattern_All1;
Exit:
    SetData = 0;
    SetDataOld = 0;
    EditMode = 0;
    Menu = 0;
    MenuOld = 0;
    InitEdit = 0;
    Cursor = 0;
    lcd.noBlink();
  }
  if ((EditState == 2) && Menu && (EditMode == 0)) EditMode = 1;
  if (Menu > MenuPage)Menu = 0;
  if ((Menu != MenuOld) && (EditMode == 0)) {       //Menu page update
    lcd.clear();
    lcd.setCursor(0, 0);
#if defined FDebug
    //Serial.println(Menu, DEC);
#endif
    switch (Menu) {
      case 1:
        lcd.print("Date and Time set");
        break;
      case 2:
        lcd.print("En on Power On");
        break;
      case 3:
        lcd.print("Out Threshold");
        break;
      case 4:
        lcd.print("Dynam Threshold");
        break;
    }
    MenuOld = Menu;
  }

  //--------Set Data Time--------------

  if ((Menu == 1) && (EditMode)) {
    if (InitEdit == 0) {
      lcd.clear();
      for (i = 7; i != 0; i--) SetDataTime[i - 1] = DataTime[i - 1];
      sprintf(buffer,  "%02d/%02d/%d", SetDataTime[2], SetDataTime[1], SetDataTime[0]);
      lcd.setCursor(4, 0);
      lcd.print( buffer );
      sprintf(buffer,  "%02d:%02d:%02d", SetDataTime[4], SetDataTime[5], SetDataTime[6]);
      lcd.setCursor(4, 1);
      lcd.print( buffer );
      Cursor = 0;
      lcd.setCursor(4, 0);
      lcd.blink();
      InitEdit = 1;
    }
    if (InitEdit) {
      if ( EditState == 1) Cursor += 1;
      if (Cursor != OldCursor) {
        if (Cursor > 5)      Cursor = 0;
        OldCursor = Cursor;
        switch (Cursor) {
          case 0:
            lcd.setCursor(4, 0);
            break;
          case 1:
            lcd.setCursor(7, 0);
            break;
          case 2:
            lcd.setCursor(10, 0);
            break;
          case 3:
            lcd.setCursor(4, 1);
            break;
          case 4:
            lcd.setCursor(7, 1);
            break;
          case 5:
            lcd.setCursor(10, 1);
            break;
        }
      }
      if (UpButtState) {
         switch (Cursor) {
          case 0:
            lcd.setCursor(4, 0);
            if (SetDataTime[2] <= 31) SetDataTime[2] += 1;
            if (SetDataTime[2] > 31) SetDataTime[2] = 0;
            sprintf(buffer,  "%02d" , SetDataTime[2]);
            lcd.print(buffer);
            lcd.setCursor(4, 0);
            break;
          case 1:
            lcd.setCursor(7, 0);
            if (SetDataTime[1] <= 12) SetDataTime[1] += 1;
            if (SetDataTime[1] > 12) SetDataTime[1] = 0;
            sprintf(buffer,  "%02d" , SetDataTime[1]);
            lcd.print(buffer);
            lcd.setCursor(7, 0);
            break;
          case 2:
            lcd.setCursor(10, 0);
            if (SetDataTime[0] <= 98)SetDataTime[0] += 1;
            if (SetDataTime[0] > 98)SetDataTime[0] = 0;
            sprintf(buffer,  "%02d" , SetDataTime[0]);
            lcd.print(buffer);
            lcd.setCursor(10, 0);
            break;
          case 3:
            lcd.setCursor(4, 1);
            if (SetDataTime[4] <= 23)SetDataTime[4] += 1;
            if (SetDataTime[4] > 23)SetDataTime[4] = 0;
            sprintf(buffer,  "%02d" , SetDataTime[4]);
            lcd.print(buffer);
            lcd.setCursor(4, 1);
            break;
          case 4:
            lcd.setCursor(7, 1);
            if (SetDataTime[5] <= 59)SetDataTime[5] += 1;
            if (SetDataTime[5] > 59)SetDataTime[5] = 0;
            sprintf(buffer,  "%02d" , SetDataTime[5]);
            lcd.print(buffer);
            lcd.setCursor(7, 1);
            break;
          case 5:
            lcd.setCursor(10, 1);
            if (SetDataTime[6] <= 59)SetDataTime[6] += 1;
            if (SetDataTime[6] > 59)SetDataTime[6] = 0;
            sprintf(buffer,  "%02d" , SetDataTime[6]);
            lcd.print(buffer);
            lcd.setCursor(10, 1);
            break;
        }
      }
      if (DwButtState) {
        switch (Cursor) {
          case 0:
            lcd.setCursor(4, 0);
            if (SetDataTime[2] >= 0) SetDataTime[2] -= 1;
            if (SetDataTime[2] > 31) SetDataTime[2] = 31;
            sprintf(buffer,  "%02d" , SetDataTime[2]);
            lcd.print(buffer);
            lcd.setCursor(4, 0);
            break;
          case 1:
            lcd.setCursor(7, 0);
            if (SetDataTime[1] >= 0) SetDataTime[1] -= 1;
            if (SetDataTime[1] > 12) SetDataTime[1] = 12;
            sprintf(buffer,  "%02d" , SetDataTime[1]);
            lcd.print(buffer);
            lcd.setCursor(7, 0);
            break;
          case 2:
            lcd.setCursor(10, 0);
            if (SetDataTime[0] >= 0) SetDataTime[0] -= 1;
            if (SetDataTime[0] > 98) SetDataTime[0] = 98;
            sprintf(buffer,  "%02d" , SetDataTime[0]);
            lcd.print(buffer);
            lcd.setCursor(10, 0);
            break;
          case 3:
            lcd.setCursor(4, 1);
            if (SetDataTime[4] >= 0) SetDataTime[4] -= 1;
            if (SetDataTime[4] > 23)SetDataTime[4] = 23;
            sprintf(buffer,  "%02d" , SetDataTime[4]);
            lcd.print(buffer);
            lcd.setCursor(4, 1);
            break;
          case 4:
            lcd.setCursor(7, 1);
            if (SetDataTime[5] >= 0)  SetDataTime[5] -= 1;
            if (SetDataTime[5] > 59)SetDataTime[5] = 59;
            sprintf(buffer,  "%02d" , SetDataTime[5]);
            lcd.print(buffer);
            lcd.setCursor(7, 1);
            break;
          case 5:
            lcd.setCursor(10, 1);
            if (SetDataTime[6] >= 0) SetDataTime[6] -= 1;
            if (SetDataTime[6] > 59)SetDataTime[6] = 59;
            sprintf(buffer,  "%02d" , SetDataTime[6]);
            lcd.print(buffer);
            lcd.setCursor(10, 1);
            break;
        }
      }
    }
  }
  
  if ((Menu == 2) && (EditMode)) {
	  
    if (InitEdit == 0) {
	  SetData = bitRead(EEPROM.read(M_PowreOnEn), 0);
      lcd.setCursor(0, 1);
      if(SetData)	lcd.print( "On");
		else lcd.print("Off");
      lcd.print(" ->");
      lcd.blink();
      InitEdit = 1;
      SetDataOld = 3; 
    }
    if (InitEdit) {
		if (UpButtState) {
        if (SetData < 1)SetData += 1;
        if (SetData > 1)SetData = 1;
      }
      if (DwButtState) {
        if (SetData > 0)SetData -= 1;
        if (SetData < 0)SetData = 0;
      }
      if (SetData != SetDataOld) {
        SetDataOld = SetData;
        lcd.setCursor(7, 1);
        if(SetData)	lcd.print( "On ");
		    else lcd.print("Off");
      }
    }
  }
  
 if ((Menu == 3) && (EditMode)) {
    if (InitEdit == 0) {
    SetData = EEPROM.read(M_VOutThrHold1);
    SetData = (SetData <<8)+ EEPROM.read(M_VOutThrHold);
	  lcd.setCursor(0, 1);
    lcd.print( SetData, DEC);
	  lcd.print(" ->");
    lcd.blink();
    InitEdit = 1;
    }
    if (InitEdit) {
		if (UpButtState) {
        if (SetData <= UpLimVOTH)SetData += 1;
        if (SetData >= UpLimVOTH)SetData = UpLimVOTH;
      }
      if (DwButtState) {
        if (SetData >= DwLimVOTH)SetData -= 1;
        if (SetData <= DwLimVOTH)SetData = DwLimVOTH;
      }
      if (SetData != SetDataOld) {
        SetDataOld = SetData;
        lcd.setCursor(7, 1);
        lcd.print( SetData, DEC);
      }
    } 
  }
  if ((Menu == 4) && (EditMode)) {
	  
    if (InitEdit == 0) {
	  SetData = bitRead(EEPROM.read(M_DynamicTH), 0);
      lcd.setCursor(0, 1);
      if(SetData)	lcd.print( "On");
		  else lcd.print("Off");
      lcd.print(" ->");
      lcd.blink();
      InitEdit = 1;
      SetDataOld = 3; 
    }
    if (InitEdit) {
		if (UpButtState) {
        if (SetData < 1)SetData += 1;
        if (SetData > 1)SetData = 1;
      }
      if (DwButtState) {
        if (SetData > 0)SetData -= 1;
        if (SetData < 0)SetData = 0;
      }
      if (SetData != SetDataOld) {
        SetDataOld = SetData;
        lcd.setCursor(7, 1);
        if(SetData)	lcd.print( "On ");
		    else lcd.print("Off");
      }
    }
  }
}
