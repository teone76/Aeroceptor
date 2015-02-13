

#include <TinyGPS.h>
#include "fml.h"

//class FmlDrone(char* name,int id, int type, int autopilot, int gcs_id, int serial_port)
FmlDroneInterface rover("Emax",1,1,1,1,3);
FmlDroneInterface multirotor_1("F550",2,2,2,10,1);
FmlDroneInterface multirotor_2("F550",3,2,2,20,2);
FmlNav navigator("ATmega2560");
unsigned long timer = millis();
unsigned long interval = 1000;



float navigationLawInput [15];
float navigationLawOutput [6];


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
  
  // 
  if(millis() - timer > interval)
  { 
    timer = millis();
    // Invio del heatbeat a tutti i multirotori
    sendHeartbeat();  
    
    // Calcolo della nuova posizione e settaggio della nuovo riferimento di posizione dei due multirotori
    calculateNewDronePosition();
    
    // 
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
{
  // Set navigatio law INPUTS
  navigationLawInput[0] = rover.getLatitude();
  navigationLawInput[1] = rover.getLongitude();
  navigationLawInput[2] = rover.getRelativeAltitude();
  navigationLawInput[3] = rover.other.gs();
  navigationLawInput[4] = rover.other.hdg();
  
  navigationLawInput[5] = multirotor_1.getLatitude();
  navigationLawInput[6] = multirotor_1.getLongitude();
  navigationLawInput[7] = multirotor_1.getRelativeAltitude();
  navigationLawInput[8] = multirotor_1.other.gs();
  navigationLawInput[9] = multirotor_1.other.hdg();  

  navigationLawInput[10] = multirotor_2.getLatitude();
  navigationLawInput[11] = multirotor_2.getLongitude();
  navigationLawInput[12] = multirotor_2.getRelativeAltitude();
  navigationLawInput[13] = multirotor_2.other.gs();
  navigationLawInput[14] = multirotor_2.other.hdg();  

 // Navigation Control Law
 navigationLawOutput[0] =  navigationLawInput[0];
 navigationLawOutput[1] =  navigationLawInput[1];
 navigationLawOutput[2] =  navigationLawInput[2];
 navigationLawOutput[3] =  navigationLawInput[0];
 navigationLawOutput[4] =  navigationLawInput[1];
 navigationLawOutput[5] =  navigationLawInput[2]; 
  
 //OUTPUTS:
  multirotor_1.setRifLatitude(navigationLawOutput[0]);
  multirotor_1.setRifLongitude(navigationLawOutput[1]);
  multirotor_1.setRifRelAltitude(navigationLawOutput[2]);

  multirotor_1.setRifLatitude(navigationLawOutput[0]);
  multirotor_1.setRifLongitude(navigationLawOutput[1]);
  multirotor_1.setRifRelAltitude(navigationLawOutput[2]);
}

void sendWaypoints()
{
  multirotor_1.sendMissionItemNavWaypoint();
  multirotor_2.sendMissionItemNavWaypoint();
}
