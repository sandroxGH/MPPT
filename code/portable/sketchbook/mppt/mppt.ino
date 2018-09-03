/*
  Solar Panel Perfornmance Logger 
  This project is a combination between a MPPT and a data Logger.
  The power stage and the Sw management come from the solar battery charger  http://www.timnolan.com/.
  The controller charge a battery to run the data logger also during the night, all the power genereate
  from the solar panel is waste on a resistence of 10H in downstream of the power stage.
  This test is to log th eperformance of the solar panel during the day, 
  all the data are writhe on Sd card in csv format 
*/

#include <SPI.h>
#include <SD.h>
#include <Wire.h>   //SDA=A4 SCL=A5
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include <TimerOne.h>

//-------Alarm Led Blink Pattern-------
#define Pattern_No_All  2500
#define Pattern_All1  1000
#define Pattern_All2  500
#define Pattern_All3  200

//-----------Timer Setting-------------
#define EepromWipe    0     // init procedure for new eeprom
#define EepromRead    0     // all the eprom data is print on serial port in startup
#define SystemLog   1   //Enable of System Log on external eprom
#define FDebug      0   // Enable Fast Debug
#define SDebug      0   // Eneble Time Debug
#define TDebug      1000  // Time of debug 
#define TLcd      1000  // Time Lcd Refresh 
#define TTwl      2000  // Time for LDR value calculation
#define TMotMan     61000 // Time 
#define TPatAll     30000 // Time of led alarm indication 
#define TExitMenu   30000 // Time for auto-exit menu 
#define TI2cTest    30000 // Time for bus test 
#define TSvTShDw    300 // Time to Save and Shutdown , power off the PerPwr enable


#define SelPatt     50    // Selection minimal time 
#define EntPatt     1500  // Enter
#define TPulButt    100   // Time for auto toogles button  
#define MenuPage    3   // Number of page in Menu 
#define VisuPageMax   3
#define VisuPageMin   0 
#define AvgNum      8


#define UpLimVOTH	1400
#define DwLimVOTH	300

//---------MPTT Parameter------------
#define MinSolVolt    8000
#define LowSolVolt    11000
#define MaxSolVolt    28000
#define MinSolWatt    20000
#define TCtrl     100
//#define VOutTH      500
#define AOffSet	     23 

//---------LCD I2C Addres and pinout---
#define EEPROM_ADDR   0x50
#define LCD_I2C_ADDR  0x20
#define DS1307_ADDR   0x68
#define BACKLIGHT_PIN 3
#define En_pin      2
#define Rw_pin      1
#define Rs_pin      0
#define D4_pin      4
#define D5_pin      5
#define D6_pin      6
#define D7_pin      7



//----------Arduino PinOut-------------
#define EdButt      2
#define UpButt      3
#define DwButt      5
#define LedR      6
#define LedY      7
#define LedG      8 
#define LedR_BIn    A7
#define chipSelect    4
#define PwmConv     9
#define PwmConvEn   10
#define PanelVoltag   A0
#define PanelCurrent  A1
#define OutConvVoltage  A2

//----------EEPROM Data storage----
#define M_PowreOnEn 1
#define M_VOutThrHold 2
#define M_VOutThrHold1  3

String Filename = "MPTT.csv";

long TimeLcd    = 0;      //Update LCD Time
long TimeDeb  = 0;      //Debug Time
//long TimeTwl    = 0;    //
// long TimeMotMan = 0;   // Time to update the Mechanical time
// long TimeMotEn   = 0;
long TimeBlink  = 0;
long TimePatt = 0;
long TimeEdButt = 0;
long TimeUpButt = 0;
long TimeDwButt = 0;

long TimeMenu   = 0;
// long TimeI2cTest = 0;
// long TimeSvTShDw = 0;
long TimePulseUp = 0;
long TimePulseDw  = 0;
long TimeCtrl =0;

byte DataTime[7];
byte SetDataTime[7];
//byte AllBuff[10];
char buffer[30];
byte SerAll[3];
//byte EpromPageOffset = 0;
//byte NotAligLengt  = 0;

//int EpromAdd;
int Pattern = 0;
int SetData, SetDataOld;
int VIn, AIn, PIn, VOut;
int PWM, Test;
int VOutTH;

//int HMec, MMec ;
// int MotEnable;
// int TwlR_On, TwlR_Off, TwlAve, TwlVal;
// int VSensVal;
// int VSensValOld;
// int VSensLim;
int j;
// int SumMinMec = 0;
// int SumMinRtc = 0;

char EditState = 0;
char Menu = 0;
char MenuOld = 0;
char i = 0;
char Cursor, OldCursor;
char Sample;
char UpButtState, DwButtState;
char SerCount;
char VisuPage, VisuPageOld;
// byte Char10[8] = {
  // B00010, B00100, B01000, B10000, B01011, B11011, B01011, B01011
// };
// byte CharV[8] = {
  // B10001, B10001, B01010, B01010, B00100, B00001, B00010, B00100
// };

bool AllReady  = 0;
bool MClAdAll  = 0;
bool MClDlAll  = 0;
bool MClWaAll = 0;
bool LcdAll    = 0;
bool RtcAll    = 0;
bool EpromAll  = 0;
bool PattAllOn = 0;
//bool MoveMot   = 0;
bool EditMode  = 0;
bool InitEdit  = 0;
//bool SvTShDw  = 0;
bool PulseMem = 0;
bool PowerOnEn =0;

LiquidCrystal_I2C lcd(LCD_I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);


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
  
  Serial.begin(115200);
  //Serial.println("MPPT Msystem");
  
  Wire.begin();
  lcd.begin(16, 2);
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.setCursor(4, 0);
  lcd.print("Msystem");
  lcd.setCursor(6, 1);
  lcd.print("MPPT");
  
  for (i=1;i<=16;i=i<<1){				//LampTest
	digitalWrite(LedR, bitRead(i, 0));
	digitalWrite(LedY, bitRead(i, 1));
	digitalWrite(LedG, bitRead(i, 2));
	digitalWrite(LedR_BIn, bitRead(i, 3));
	delay(500); 
  }
  //delay(1500);
  lcd.clear();
  lcd.setBacklight(LOW);
  PowerOnEn =  bitRead(EEPROM.read(M_PowreOnEn), 0);
  VOutTH = EEPROM.read(M_VOutThrHold1);
  VOutTH = (VOutTH <<8)+ EEPROM.read(M_VOutThrHold);



  Serial.print("Init SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("Sd Inti Error");
    Pattern = Pattern_All3;
  }
  else Serial.println("Done");
  
  //Controllo nome  e generazione di unnuovo file
  for (i = 0; SD.exists(Filename); i++)Filename = ("MPPT" + String(i, DEC) + ".csv");
  Serial.println(Filename);
  File dataFile = SD.open(Filename, FILE_WRITE);
  if (dataFile) {
    dataFile.println("MPPT Msytem");
    dataFile.close();
  }
 
  if (! GetDateTime(&DataTime[0], 6)) {
    Serial.println("RTC Fault");
    // for (i = 0; i <= 6; i++) AllBuff[i] = 99;
    // AllBuff[7] =  ALARM;
    // AllBuff[8] = RTC_NOT_RUN;
    // AllReady = 1;
	Pattern = Pattern_All3;
  }
  else {
    // for (i = 0; i <= 6; i++) AllBuff[i] = DataTime[i];
    // AllBuff[7] = EVENT;
    // AllBuff[8] = START_UP;
    // AllReady = 1;
    Serial.print("RTC Running");
    //Pattern = Pattern_No_All;
  }
  
  
  Timer1.initialize(20);               // initialize timer1, and set a 20uS period
  Timer1.pwm(PwmConv, 500);              // setup pwm on pin 9, 0% duty cycle
  digitalWrite(PwmConvEn, PowerOnEn);    
}

char ButtonState(char PinN, long *Time, bool Pulse = 0 , long *Time1 = 0) {
  if ((*Time == 0) && !digitalRead(PinN))  *Time = millis();
  if (Pulse && !digitalRead(PinN) && (millis() > (*Time + (EntPatt * 3 ))))  {
    if (*Time1 == 0 ) *Time1 = millis();
    if (millis() > *Time1) {
      *Time1 = (millis() + TPulButt);
#if defined FDebug
      Serial.print("3 ");
#endif
      return 1;
    }
  }
  if (Pulse && digitalRead(PinN)) *Time1 = 0;
  if (digitalRead(PinN) && (*Time)) {
    if (millis() >= EntPatt  + *Time) {
#if defined FDebug 
      Serial.println("2");
#endif
      *Time = 0;
      return 2;
    }
    if (millis() >= SelPatt  + *Time) {
      *Time = 0;
#if defined FDebug
      Serial.println("1");
#endif
      return 1;
    }
  }
  else  return 0;
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

void Debug() {
  digitalWrite(LedG, !(digitalRead(LedG)));
}

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

void loop() {

  //------------Time Debug Mng---------
  if ((millis() > TimeDeb) && SDebug) {
    TimeDeb = (millis() + TDebug);
    Debug();
  }
  
	if (millis() > TimeCtrl){
   TimeCtrl = (millis()+TCtrl);
   VIn = map(ReadAdc(PanelVoltag),0,1023,0, 3000);
   AIn = map((ReadAdc(PanelCurrent)- AOffSet),0,1023,0,3401);
   //AIn = (ReadAdc(PanelCurrent));
   VOut = map(ReadAdc(OutConvVoltage),0,1023,0,3000);
   if(PowerOnEn){
		if((VOut < (VOutTH - 5)) && (PWM < 1023)) PWM +=1;
		if((VOut > (VOutTH + 5)) && (PWM > 1)) PWM -=1;
		  // Timer1.setPwmDuty(PwmConv,100);              
		}

  }
  //------------Main LCD Mng-----------

  if ((Menu == 0) && ((millis() > TimeLcd) || (VisuPage != VisuPageOld))) {
    TimeLcd = (millis() + TLcd);
    GetDateTime(&DataTime[0], 6);
    if (VisuPage > VisuPageMax) VisuPage = VisuPageMin;
    VisuPageOld = VisuPage;
    lcd.clear();
    	
    switch(VisuPage){
case 0:
    sprintf(buffer,"VI=%04d AI=%04d",VIn,AIn);
    lcd.setCursor(0, 0);
    lcd.print( buffer );
    sprintf(buffer,"PWM=%03d VO=%04d",map(PWM,0,1023,0,100),VOut);
    lcd.setCursor(0, 1);
    lcd.print( buffer );
break;

case 1:	

break;

case 2:

break;

case 3:
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

  //---------Red Led Program State-----

  if (millis() >= TimeBlink) {
    digitalWrite(LedR, (digitalRead(LedR ) ^ 1));
    if ((Pattern != Pattern_No_All) && !PattAllOn) {
      TimePatt = (millis() + TPatAll);
      PattAllOn = 1;
    }
    else TimeBlink = (millis() + Pattern);

    if (millis() > TimePatt) {
      Pattern = Pattern_No_All;
      PattAllOn = 0;
    }
  }
  
  
   //---------Menu Mng Edit Mode---------

  EditState = ButtonState(EdButt, &TimeEdButt);
  UpButtState = ButtonState(UpButt, &TimeUpButt , 1 , &TimePulseUp);
  DwButtState = ButtonState(DwButt, &TimeDwButt , 1, &TimePulseDw);

  if (( EditState) || (UpButtState) || (DwButtState)) {
    TimeMenu =  (millis() + TExitMenu);
    lcd.setBacklight(HIGH);
  }
  if (millis() > TimeMenu )  {
    Menu = 0;
    EditMode = 0;
    InitEdit = 0;
    Cursor = 0;
    lcd.noBlink();
    lcd.setBacklight(LOW);
  }

  if ((EditState == 1) && (EditMode == 0)) Menu += 1;
  if ((Menu == 0) && (UpButtState )) VisuPage +=1;
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
    // if (Menu == 4) {
      // if (SetData > (TwlR_Off + TwlRDelta)) {
        // TwlR_On = SetData;
        // EEPROM.write(M_TwlR_On, TwlR_On);
        // goto SaveOk;
      // }
      // else {
        // goto SaveFault;
      // }
    // }
    // if (Menu == 5) {
      // if (SetData < (TwlR_On - TwlRDelta)) {
        // TwlR_Off = SetData;
        // EEPROM.write(M_TwlR_Off, TwlR_Off);
        // goto SaveOk;
      // }
      // else {
        // goto SaveFault;
      // }
    // }

    // if (Menu == 6) {
      // if (SetData < (VSensVal - 10)) {
        // VSensLim = SetData;
        // EEPROM.write(M_VSensLim, VSensLim);
        // goto SaveOk;
      // }
      // else {
        // goto SaveFault;
      // }
    // }

SaveOk:
    lcd.setCursor(14, 1);
    lcd.print("Ok");
#if defined FDebug
    Serial.print("OK");
#endif
    //delay(1000);
    TimeLcd = (millis() + 1000);       //delay the LCD refresh
    // for (i = 0; i <= 6; i++) AllBuff[i] = DataTime[i];
    // AllBuff[7] = EVENT;
    // AllBuff[8] = CHANGE_DATE;
    // AllBuff[9] = Menu;
    // AllReady = 1;
    goto Exit;
SaveFault:
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Errore Data");
#if defined FDebug
    Serial.print("Errore Data");
#endif
    //delay(1500);
    TimeLcd = (millis() + 1500);
    // for (i = 0; i <= 6; i++) AllBuff[i] = DataTime[i];
    // AllBuff[7] = ALARM;
    // AllBuff[8] = DATA_FAULT;
    // AllBuff[9] = Menu;
    // AllReady = 1;
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
      // case 4:
        // lcd.print("Crepuscolare On");
        // break;
      // case 5:
        // lcd.print("Crepuscolare Off");
        // break;
      // case 6:
        // lcd.print("CTRL Tensione");
        // break;
      // case 7:
        // lcd.print("System LOG");
        // break;
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
      //buffer[10] = "";
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
        //buffer[10] = "";
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
        //buffer[10] = "";
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
	  SetData = PowerOnEn;
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
        if(SetData)	lcd.print( "On");
		else lcd.print("Off");
      }
    }
  }
  
 if ((Menu == 3) && (EditMode)) {
    if (InitEdit == 0) {
	  SetData = VOutTH;
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
}
