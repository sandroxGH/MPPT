//-------Alarm Led Blink Pattern-------
#define Pattern_No_All	2500
#define Pattern_All1    1000
#define Pattern_All2    500
#define Pattern_All3    200

//-----------Project Setting-------------
//#define SystemLog       //Enable of System Log on external eprom
#define FDebug          // Enable Fast Debug
//#define SDebug          // Eneble Time Debug

//-----------Timer Setting-------------
#define TDebug      1000  // Time of debug
#define TLcd        1000  // Time Lc 
#define TLog        10000       
#define TDelPw      20000
//------------Main LCD Mng-----------
#define TPatAll     30000 // Time of led alarm indication 
#define TExitMenu  	30000 // Time for auto-exit menu 

#define SelPatt		  	50      // Selection minimal time 
#define EntPatt			1500    // Enter
#define TPulButt		100     // Time for auto toogles button  
#define MenuPage		2//4       // Number of page in Menu 
#define VisuPageMax		3       
#define VisuPageMin		0 
#define AvgNum			8       //Number of sample for ADC read



//---------MPTT Parameter------------
#define MinSolVolt	800
#define LowSolVolt	1100
//#define MaxSolVolt	2800
//#define MinSolWatt	750
//#define LowSolWatt  900
#define TCtrl	    500   //0628 /300    //20
//#define AOffSet		0
//#define UpLimVOTH	1500
//#define DwLimVOTH	300

//#define VInMin      1720
#define VOutMin     900
#define PwmMin      500
#define PwmMax      1020    
int TimeTS =0;
#define TTS         6000/TCtrl    //2 seconds


#define PIn_T         10
#define VIn_T         10
#define Inc             2


//---------LCD I2C Addres and pinout---
#define EEPROM_ADDR		0x50
#define LCD_I2C_ADDR	0x20
#define DS1307_ADDR		0x68
#define BACKLIGHT_PIN	  3
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
//#define LedR_BIn    	A7
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
char buffer[25];
char FileName[6];


unsigned int Pattern = Pattern_No_All;
int SetData, SetDataOld;
int VIn, AIn, PIn, VIn_Old,AIn_Old, PIn_Old; 
int AInMax;
int POut, VOut;
int PWM, PwmDisp;
int VOutTH; 
float DeltaI, DeltaV, DeltaP;
char EditState = 0;
char Menu = 0;
char MenuOld = 0;
char i = 0;
char Cursor, OldCursor;
char UpButtState, DwButtState;
char SerCount;
char VisuPage, VisuPageOld;  // 0 = VIn AIn PWM VOut 1 = PIn POut AInMax 2 = EnProd 3 = Date Time

bool AllReady  = 0;
bool PattAllOn = 0;
bool EditMode  = 0;
bool InitEdit  = 0;
bool PowerOnEn =0;
bool PwAutoStart =0;
float EnProd;
int PwProd, Mem;
int Cnt1, Cnt2, Cnt3,Cnt4;