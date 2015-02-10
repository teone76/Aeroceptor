
// Mavlink interface
#include "../GCS_MAVLink/include/mavlink/v1.0/common/mavlink.h"// Mavlink interface
#include "../GCS_MAVLink/include/mavlink/v1.0/ardupilotmega/ardupilotmega.h"
#include "../GCS_MAVLink/include/mavlink/v1.0/ardupilotmega/mavlink.h"
#include "../GCS_MAVLink/include/mavlink/v1.0/common/common.h"
#include <TinyGPS.h>

#include "fml.h"


FmlDrone rover("Emax",1,1,1,1);
FmlDrone multirotor_1("F550",2,2,2,10);
FmlDrone multirotor_2("F550",3,2,2,20);

void setup() {
  
  Serial.begin(115200);  // Debug
  Serial1.begin(57600);  // Multicopter 1
  Serial2.begin(57600);  // Multicopter 2
  Serial3.begin(57600);  // Rover
  
}

void loop() {  
 
  send_heartbeat_1();
  send_heartbeat_2();
  
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
  
