

#include <TinyGPS.h>
#include "fml.h"

//class FmlDrone(char* name,int id, int type, int autopilot, int gcs_id, int serial_port)
FmlDroneInterface rover("Emax",1,1,1,1,3);
FmlDroneInterface multirotor_1("F550",2,2,2,10,1);
FmlDroneInterface multirotor_2("F550",3,2,2,20,2);
FmlNav navigator("ATmega2560");
unsigned long timer = millis();
unsigned long interval = 1000;


void setup() {

  Serial.begin(115200);  // Debug
  Serial1.begin(57600);  // Multicopter 1
  Serial2.begin(57600);  // Multicopter 2
  Serial3.begin(57600);  // Rover
  
/*Serial.println(rover.getName());
  Serial.println(multirotor_1.getName());
  Serial.println(multirotor_2.getName()); */
}

void loop() {  

  checkAvailableDataOnSerial(); 

  if(millis() - timer > interval)
  { 
    timer = millis();
    sendHeartbeat();   
    calculateNewDronePosition();
    sendWaypoints();
  }    
}

//////// FUNCTIONS /////////

void checkAvailableDataOnSerial()
{
  while(Serial3.available() > 0) rover.encode(Serial3.read());
  while(Serial1.available() > 0) multirotor_1.encode(Serial1.read());
  while(Serial2.available() > 0) multirotor_2.encode(Serial2.read());  
}

void sendHeartbeat()
{
  multirotor_1.sendMavMsgHeartbeat();
  multirotor_2.sendMavMsgHeartbeat();   
}

void calculateNewDronePosition()
{/*
 //INPUTS:
  rover.location.lat();
  rover.location.lng();
  rover.location.relAlt();
  rover.other.gs();
  rover.other.hdg();
  
  multirotor_1.location.lat();
  multirotor_1.location.lng();
  multirotor_1.location.relAlt();
  multirotor_1.other.gs();
  multirotor_1.other.hdg();  

  multirotor_2.location.lat();
  multirotor_2.location.lng();
  multirotor_2.location.relAlt();
  multirotor_2.other.gs();
  multirotor_2.other.hdg();  

 //SIMULINK_FUNCTION()..
  
 //OUTPUTS:
  multirotor_1.rif_location.setLatitude(simulink_outputs ----> float rif1_latitude);
  multirotor_1.rif_location.setLongitude(simulink_outputs ----> float rif1_longitude);
  multirotor_1.rif_location.setRelativeAltitude(simulink_outputs ----> float rif1_relativeAltitude);

  multirotor_2.rif_location.setLatitude(simulink_outputs ----> float rif2_latitude);
  multirotor_2.rif_location.setLongitude(simulink_outputs ----> float rif2_longitude);
  multirotor_2.rif_location.setRelativeAltitude(simulink_outputs ----> float rif2_relativeAltitude); */
}

void sendWaypoints()
{
  multirotor_1.sendMissionItemNavWaypoint();
  multirotor_2.sendMissionItemNavWaypoint();
}
