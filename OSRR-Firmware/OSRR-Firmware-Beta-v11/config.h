#ifndef CONFIG_H
#define CONFIG_H

// - Choose UART protocol:
//define ESC_UNITY             // ESC_UNITY for UART communication with a UNITY
#define ESC_VESC                // ESC_VESC for UART communication with a VESC 4.12-6.6

// - Choose Metric or Imperial
//#define METRIC
#define IMPERIAL

// - Choose Simple or Full Display mode
// #define SIMPLE
// #define FULL

// Defining variables to hold values for speed and distance calculation
int wheelDiameter = 145;  //Wheel diameter in MM. 
int wheelPulley = 60;     //Wheel Pulley Tooth Count
int motorPulley = 15;     //Motor Pulley Tooth Count
float motorPoles = 14;      //Motor Poles - 14 default

const int addr_wheelDiameter = 10;
const int addr_wheelPulley = 20;
const int addr_motorPulley = 30;

int e_wheelDiameter;  //Wheel diameter in MM. 
int e_wheelPulley;     //Wheel Pulley Tooth Count
int e_motorPulley;     //Motor Pulley Tooth Count


float gearRatio;
float ratioRpmSpeed;
float ratioPulseDistance;
float distanceValue;


unsigned long previousLCDUpdate = 0;
unsigned long previousVescUpdate = 0;
const long LCDUpdateInterval = 250;
const long VescUpdateInterval = 20;

int16_t thumbwheelVal0;
int16_t thumbwheelVal1;
String command;
int throttle = 127;
int throttleCenterMargin = 5;
bool throttleActive = false;
int min_ads = 0;
int max_ads = 1700;
int adc_max_limit = 2000;


int16_t remoteBatRaw;
int min_ads_bat = 1000;
int max_ads_bat = 1400;
int adc_max_bat_limit = 2000;

int16_t remoteRSSIRaw;

void calculateRatios()  {
  gearRatio = ( (float)motorPulley / (float)wheelPulley );
  ratioRpmSpeed = (gearRatio * 60 * (float)wheelDiameter * 3.14156) / ((motorPoles / 2) * 1000000);
  ratioPulseDistance = (gearRatio * (float)wheelDiameter * 3.14156) / ((motorPoles * 3) * 1000000);

}

//UNUSED (Future ToDo)
#ifdef ESC_UNITY
// Defining struct to handle callback data for UNITY
struct callback {
  float ampHours;
  float inpVoltage;
  long rpm;
  long tachometerAbs;
  uint8_t headlightActive;
  float avgInputCurrent;
  float avgMotorCurrent0;
  float avgMotorCurrent1;
  float dutyCycleNow0;
  float dutyCycleNow1;
  bool eStopArmed;
  int8_t receiverRssi;
  float filteredFetTemp0;
  float filteredFetTemp1;
  float filteredMotorTemp0;
  float filteredMotorTemp1;
} returnData;
#endif

//UNUSED
#ifdef ESC_VESC
// Defining struct to handle callback data for VESC
struct callback {
  float ampHours;
  float inpVoltage;
  long rpm;
  long tachometerAbs;
  uint8_t headlightActive;
  float avgInputCurrent;
  float avgMotorCurrent0;
  float dutyCycleNow0;
  bool eStopArmed;
  int8_t receiverRssi;
  float filteredFetTemp0;
  float filteredMotorTemp0;
} returnData;
#endif

// UNUSED
// Defining struct to hold stats
struct stats {
  float maxSpeed;
  long maxRpm;
  float minVoltage;
  float maxVoltage;
};

// Defining variables for speed and distance calculation



bool recievedData = false;
uint32_t lastTimeReceived = 0;
int timeoutMax = 500;
unsigned long lastDataCheck;
bool remoteBatFlash = true;
bool connBlink = true;
int connBlinkCount = 0;
unsigned long failCount = 0;
unsigned long successCount = 0;


#endif
