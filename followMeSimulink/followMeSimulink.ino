

#include <TinyGPS.h>
#include "fml.h"
TinyGPS gps;

#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "navigator.h"                 /* Model's header file */
#include "rtwtypes.h"

//class FmlDrone(char* name,int id, int type, int autopilot, int gcs_id, int serial_port)
FmlDroneInterface rover("Emax",1,1,1,1,3);
FmlDroneInterface multirotor_1("F550",2,2,2,10,1);
FmlDroneInterface multirotor_2("F550",3,2,2,20,2);

FmlNav navigator("ATmega2560");

unsigned long mavTimer = millis();
unsigned long mavInterval = 1000;

unsigned long simulinkTimer = millis();
unsigned long simulinkInterval = 100;




/* Da cancellare
float navigationLawInput [15];
float navigationLawOutput [6];
*/

//pin input from RX
int pin = 12;
unsigned long pwmin = 0;

unsigned long simulinkExecutionStart = 0;
unsigned long simulinkExecutionStop = 0;

void setup() {
  /* Initialize model */
  navigator_initialize();
  
  Serial.begin(115200);  // Debug
  Serial1.begin(57600);  // Multicopter 1
  Serial2.begin(57600);  // Multicopter 2
  Serial3.begin(57600);  // Rover
  
  pinMode(pin, INPUT);  
  
  Serial.println("Serial ready..");
  Serial.println("");
  Serial.print(rover.getName());
  Serial.print(" on serial3, ");  
  Serial.print(multirotor_1.getName());
  Serial.println(" on serial1, ");
//  Serial.println(multirotor_2.getName());
  Serial.println("");
  Serial.print("   LAT_1      ");
  Serial.print("LNG_1    ");
  Serial.print("REL_ALT_1    ");
  Serial.print("LAT_3      ");
  Serial.print("LNG_3    ");
  Serial.print("REL_ALT_3  ");
  Serial.print("GND_SPD_3    ");
  Serial.print("HDG_3     ");
  Serial.print("DIST   ");
  Serial.print("CRS  ");
  Serial.print("CALC_LAT    ");
  Serial.print("CALC_LNG    ");
  Serial.println("time");
}

void loop() {  

  checkAvailableDataOnSerial(); 
  
  // SIMULINK TASK - 10 HZ
  if(millis() - simulinkTimer > simulinkInterval)
  { 
  simulinkTimer = millis();

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
  }
  
  // MAVLINK TASK - 1 HZ 
  if(millis() - mavTimer > mavInterval)
  { 
    mavTimer = millis();  
    // Invio del heatbeat a tutti i multirotori
    sendHeartbeat();  
    sendRequest();
   Serial.print(millis());       
   Serial.print(multirotor_1.getLatitude(), 7);
   Serial.print(", ");
   Serial.print(multirotor_1.getLongitude(), 7);
   Serial.print(", ");
   Serial.print(multirotor_1.getRelativeAltitude(), 7);    
   Serial.print(", ");
   Serial.print(rover.getLatitude(), 7);
   Serial.print(", ");   
   Serial.print(rover.getLongitude(), 7);
   Serial.print(", ");
   Serial.print(rover.getRelativeAltitude(), 7);
   Serial.print(", ");
   Serial.print(rover.getGroundSpeed(), 7);
   Serial.print(", ");
   Serial.print(rover.getHeading(), 7);
   Serial.print(", ");   
   Serial.print(gps.distance_between(rover.getLatitude(), rover.getLongitude(), multirotor_1.getLatitude(), multirotor_1.getLongitude()));
   Serial.print(", ");
   Serial.print(gps.course_to(rover.getLatitude(), rover.getLongitude(), multirotor_1.getLatitude(), multirotor_1.getLongitude()));
   Serial.print(", ");
   Serial.print(navigator_Y.Out[0], 7);
   Serial.print(", ");
   Serial.print(navigator_Y.Out[1], 7);
   Serial.print(", ");
   Serial.println(simulinkExecutionStop - simulinkExecutionStart); 
  }  

     
  // 
  if(rover.isLocationUpdated())
  { 
    // Aggiornamento dei reference point dei multirotore
    updateDronePositionReference();
    
    // Command input from RX 
    pwmin = pulseIn(pin, HIGH, 20000);
  
    //Serial.println(pwmin);
    if(pwmin < 1200) {          
      sendWaypoints();
      //Serial.println("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
    }         
  }
}

//////// FUNCTIONS /////////

void checkAvailableDataOnSerial()
{
  while(Serial3.available() > 0) rover.encode(Serial3.read());
  while(Serial1.available() > 0) multirotor_1.encode(Serial1.read());
  while(Serial2.available() > 0) multirotor_2.encode(Serial2.read());  
}

void  sendRequest()
{
  multirotor_1.getDataStream();
  multirotor_2.getDataStream();
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
}


void sendWaypoints()
{
  multirotor_1.sendMissionItemNavWaypoint();
  multirotor_2.sendMissionItemNavWaypoint();
}
