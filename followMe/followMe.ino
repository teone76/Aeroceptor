

#include <TinyGPS.h>
#include "fml.h"

//class FmlDrone(char* name,int id, int type, int autopilot, int gcs_id, int serial_port)
FmlDrone rover("Emax",1,1,1,1,3);
FmlDrone multirotor_1("F550",2,2,2,10,1);
FmlDrone multirotor_2("F550",3,2,2,20,2);
Nav navigator("ATmega2560");

void setup() {
  
  Serial.begin(115200);  // Debug
  Serial1.begin(57600);  // Multicopter 1
  Serial2.begin(57600);  // Multicopter 2
  Serial3.begin(57600);  // Rover
  
}

void loop() {  
 
  navigator.sendHeartbeat(multirotor_1);
  navigator.sendHeartbeat(multirotor_2);  
  
  delay(1000);
  /*Serial.println(rover.getName());
  Serial.println(multirotor_1.getName());
  Serial.println(multirotor_2.getName());*/
  checkAvailableDataOnSerial_1();
  checkAvailableDataOnSerial_2();
  checkAvailableDataOnSerial_3();
}

//////// FUNCTIONS /////////


void checkAvailableDataOnSerial_1() {
  while(Serial1.available() > 0) multirotor_1.encode(Serial1.read());
 }
 
void checkAvailableDataOnSerial_2() {
  while(Serial2.available() > 0) multirotor_2.encode(Serial2.read());
 }
 
void checkAvailableDataOnSerial_3() { 
  while(Serial3.available() > 0) rover.encode(Serial3.read());
 }
  
