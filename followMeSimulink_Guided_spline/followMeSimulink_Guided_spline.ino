
#include <Wire.h>
#include <TinyGPS.h>
#include "fml.h"
TinyGPS gps;

#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "navigator.h"                 /* Model's header file */
#include "rtwtypes.h"
#include "fmlMsgLed.h"

//class FmlDrone(char* name,int id, int type, int autopilot, int gcs_id, int serial_port)
FmlDroneInterface rover("Emax",1,1,1,1,3);
FmlDroneInterface multirotor_1("F550",2,2,2,10,1);
FmlDroneInterface multirotor_2("F550",3,2,2,20,2);

FmlNav navigator("ATmega2560");
FmlMsgLed ledMessage1("mLed1");

unsigned long mavTimer = millis();
unsigned long mavInterval = 1000;

unsigned long ledTimer = millis();
unsigned long ledInterval = 500;

unsigned long simulinkTimer = millis();
unsigned long simulinkInterval = 100;


/* Da cancellare
float navigationLawInput [15];
float navigationLawOutput [6];
*/

//pin input from RX
int pin = 12;
unsigned long pwmIn = 0;

int state = 0;
int previous_state = 0;

unsigned long simulinkExecutionStart = 0;
unsigned long simulinkExecutionStop = 0;

void setup() {
  /* Initialize model */
  navigator_initialize();
  Wire.begin();          // I2C led  
  Serial.begin(115200);  // Debug
  Serial1.begin(57600);  // Multicopter 1
  Serial2.begin(57600);  // Multicopter 2
  Serial3.begin(57600);  // Rover
  
  pinMode(pin, INPUT);  
  
 /* Serial.println("Serial ready..");
  Serial.println("");
  Serial.print(rover.getName());
  Serial.print(" on serial3, ");  
  Serial.print(multirotor_1.getName());
  Serial.println(" on serial1, ");
//  Serial.println(multirotor_2.getName());
  Serial.println("");*/
  Serial.print("time_stamp , ");
  Serial.print("LAT_M , ");
  Serial.print("LNG_M , ");
  Serial.print("REL_ALT_M , ");
  Serial.print("LAT_R , ");
  Serial.print("LNG_R , ");
  Serial.print("REL_ALT_R , ");
  Serial.print("GND_SPD_R , ");
  Serial.print("HDG_R , ");
  Serial.print("DIST , ");
  Serial.print("CRS , ");
  Serial.print("CALC_LAT , ");
  Serial.print("CALC_LNG , ");
  Serial.print("execution time , ");
  Serial.print("GPS_FIX , ");
  Serial.print("n_sat , ");
  Serial.print("vx, ");
  Serial.print("vy, ");
  Serial.print("rif_vx, ");
  Serial.println("rif_vy");  
  ledMessage1.blinkMessage('B',red,none,none,none);
}

void loop() { 

  checkAvailableDataOnSerial(); 
  
  // SIMULINK TASK - 10 HZ
  if(millis() - simulinkTimer > simulinkInterval)
  { 
  simulinkTimer = millis();


  }
  
  // MAVLINK TASK - 1 HZ 
  if(millis() - mavTimer > mavInterval)
  { 
    mavTimer = millis();  
    // Invio del heatbeat a tutti i multirotori
    sendHeartbeat();  
    sendRequest(); 
    //multirotor_1.sendNavGuided();
  }  

     
  // 
  if(rover.isLocationUpdated() /*&& rover.isOtherUpdated()*/)
  { 
      // Set model inputs  
  navigator_U.In[0] = rover.getLatitude();
  navigator_U.In[1] = rover.getLongitude();
  navigator_U.In[2] = rover.getRelativeAltitude();
  navigator_U.In[3] = rover.getGroundSpeed();
  navigator_U.In[4] = rover.getHeading();
  
  navigator_U.In[5] = multirotor_1.getLatitude();
  navigator_U.In[6] = multirotor_1.getLongitude();
  navigator_U.In[7] = multirotor_1.getRelativeAltitude();
  navigator_U.In[8] = multirotor_1.getGroundSpeed();
  navigator_U.In[9] = multirotor_1.getHeading();  

  navigator_U.In[10] = multirotor_2.getLatitude();
  navigator_U.In[11] = multirotor_2.getLongitude();
  navigator_U.In[12] = multirotor_2.getRelativeAltitude();
  navigator_U.In[13] = multirotor_2.getGroundSpeed();
  navigator_U.In[14] = multirotor_2.getHeading();
  
  simulinkExecutionStart = micros();
  // Navigation Control Law - Step the model 
  navigator_step();
  simulinkExecutionStop = micros();
  
    // Aggiornamento dei reference point dei multirotore
    updateDronePositionReference();
      
    //Serial.println(pwmIn);
    if(followMeActived_1()) {          
      sendWaypoints();
    }
    else if (followMeActived_2()) {
      sendSplineWaypoints();
    }
    printAllData();   
    
    // Command input from RX 
    pwmIn = pulseIn(pin, HIGH, 20000); 
  }
  
    // LED TASK - 2 HZ 
  if(millis() - ledTimer > ledInterval)
  { 
    ledTimer = millis();  
    updateLed(); 
  }
}

//////// FUNCTIONS /////////

bool switchToFollowMe() {
  if((pwmIn > 1300) && (pwmIn < 1600)) {
    state = 1;
    if(state != previous_state) {
      previous_state = 1;
      return true;}
    else {return false;}
  }
  else if(pwmIn > 1700) {
    state = 2;
    if(state != previous_state) {
      previous_state = 2;
      return true;}
    else {return false;} 
  }
  else {
    previous_state = 0;
    return false;}   
}
      
  

 bool followMeActived_1() {
 if((pwmIn > 1300) && (pwmIn < 1600)) {return true;}
 else {return false;} 
}

 bool followMeActived_2() {
 if(pwmIn > 1700) {return true;}
 else {return false;} 
}

void checkAvailableDataOnSerial()
{
  while(Serial3.available() > 0) rover.encode(Serial3.read());
  while(Serial1.available() > 0) multirotor_1.encode(Serial1.read());
  while(Serial2.available() > 0) multirotor_2.encode(Serial2.read());  
}

void  sendRequest()
{
  //rover.getDataStream(Fml_data_stream_all);
  multirotor_1.getDataStream(Fml_gps_status);
  multirotor_1.getDataStream(Fml_global_position);
  multirotor_2.getDataStream(Fml_gps_status);
  multirotor_2.getDataStream(Fml_global_position);
}

void sendHeartbeat()
{
  multirotor_1.sendMavMsgHeartbeat();
  multirotor_2.sendMavMsgHeartbeat();   
}


void updateDronePositionReference()
{
  //OUTPUTS:
  multirotor_1.setRifLatitude(navigator_Y.Out[0]);
  multirotor_1.setRifLongitude(navigator_Y.Out[1]);
  multirotor_1.setRifRelAltitude(navigator_Y.Out[2]);

  multirotor_2.setRifLatitude(navigator_Y.Out[3]);
  multirotor_2.setRifLongitude(navigator_Y.Out[4]);
  multirotor_2.setRifRelAltitude(navigator_Y.Out[5]);
  
  //Vx Vy Yaw OUTPUTS:
  multirotor_1.setRifVx(rover.getVx());
  multirotor_1.setRifVy(rover.getVy());
  multirotor_1.setRifYaw(rover.getHeading());
  
  multirotor_2.setRifVx(rover.getVx());
  multirotor_2.setRifVy(rover.getVy());
  multirotor_2.setRifYaw(rover.getHeading());
}

void sendWaypoints()
{
  multirotor_1.sendMissionItemNavWaypoint();
  multirotor_2.sendMissionItemNavWaypoint();
}

void sendSplineWaypoints()
{
  multirotor_1.sendPositionTargetGlobalInt();
  multirotor_2.sendPositionTargetGlobalInt();
}

void printAllData()
{
   Serial.print(millis()); 
   Serial.print(", ");  
   Serial.print(multirotor_1.getLatitude(), 7);
   Serial.print(", ");
   Serial.print(multirotor_1.getLongitude(), 7);
   Serial.print(", ");
   Serial.print(multirotor_1.getRelativeAltitude(), 1);    
   Serial.print(", ");
   Serial.print(rover.getLatitude(), 7);
   Serial.print(", ");   
   Serial.print(rover.getLongitude(), 7);
   Serial.print(", ");
   Serial.print(rover.getRelativeAltitude(), 1);
   Serial.print(", ");
   Serial.print(rover.getGroundSpeed(), 1);
   Serial.print(", ");  
   Serial.print(rover.getHeading(), 1);
   Serial.print(", ");   
   Serial.print(gps.distance_between(rover.getLatitude(), rover.getLongitude(), multirotor_1.getLatitude(), multirotor_1.getLongitude()));
   Serial.print(", ");
   Serial.print(gps.course_to(rover.getLatitude(), rover.getLongitude(), multirotor_1.getLatitude(), multirotor_1.getLongitude()));
   Serial.print(", ");
   Serial.print(navigator_Y.Out[0], 7);
   Serial.print(", ");
   Serial.print(navigator_Y.Out[1], 7);
   Serial.print(", ");
   Serial.print(simulinkExecutionStop - simulinkExecutionStart);
   Serial.print(", ");
   Serial.print(rover.isGpsFixed());
   Serial.print(", ");
   Serial.print(rover.getSatVisible());
   Serial.print(", ");
   Serial.print(rover.getVx(), 2);
   Serial.print(", ");
   Serial.print(rover.getVy(), 2);
   Serial.print(", ");
   Serial.print(multirotor_1.getRifVx(), 2);
   Serial.print(", ");
   Serial.println(multirotor_1.getRifVy(), 2);     
}

void updateLed() {
  
  if(followMeActived_1()) {ledMessage1.setMessage('A',blue,previous,previous,previous);}
  else if (followMeActived_2()) {ledMessage1.setMessage('A',azure,previous,previous,previous);}
  else {ledMessage1.setMessage('A',none,previous,previous,previous);}
  if(rover.isDroneConnected()) {ledMessage1.setMessage('A',previous,none,previous,previous);}
  else {ledMessage1.setMessage('A',previous,white,previous,previous);}
  if(multirotor_1.isDroneConnected()) {ledMessage1.setMessage('A',previous,previous,none,previous);}  
  else {ledMessage1.setMessage('A',previous,previous,purple,previous);} 
  if(rover.isGpsFixed()) 
  {
    if(rover.getSatVisible()<=4) {ledMessage1.setMessage('A',previous,previous,previous,yellow);} 
    else if(rover.getSatVisible()>4) {ledMessage1.setMessage('A',previous,previous,previous,green);} 
  }
  else {ledMessage1.setMessage('A',previous,previous,previous,red);}
  ledMessage1.blinkMessage();  
}
