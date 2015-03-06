
#include <Wire.h>
#include <TinyGPS.h>
#include "fml.h"
#include "fmlLed.h"
TinyGPS gps;
//class FmlDrone(char* name,int id, int type, int autopilot, int gcs_id, int serial_port)
FmlDroneInterface rover("Emax",1,1,1,1,3);
FmlDroneInterface multirotor_1("F550",2,2,2,10,1);
FmlDroneInterface multirotor_2("F550",3,2,2,20,2);
FmlNav navigator("ATmega2560");
FmlLed led("MyLed");
unsigned long timer = millis();
unsigned long interval = 1000;
unsigned long pwmin = 0;


float navigationLawInput [15];
float navigationLawOutput [6];

//pin input from RX
int pin = 12;

void setup() {

  Wire.begin();          // I2C led
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
  Serial.print("HDG_3      ");
  Serial.print("DIST   ");
  Serial.println("CRS    ");
  
  led.blinkMessage('A',red,red,red,red);
}

void loop() {  
  checkAvailableDataOnSerial(); 
  // 
  if(millis() - timer > interval)
  { 
    timer = millis();
    // Invio del heatbeat a tutti i multirotori
    sendHeartbeat();  
    sendRequest();    
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
   Serial.println(gps.course_to(rover.getLatitude(), rover.getLongitude(), multirotor_1.getLatitude(), multirotor_1.getLongitude()));
  }  

  // 
  if(rover.isLocationUpdated())
  { 
    // Calcolo della nuova posizione e settaggio della nuovo riferimento di posizione dei due multirotori
    calculateNewDronePosition();

    // Command input from RX 
    pwmin = pulseIn(pin, HIGH, 20000);
    //Serial.println(pwmin);
    if(pwmin < 1200) {     
    // 
      sendWaypoints();
      led.blinkMessage(previous,blue,previous,previous,previous);
    }
    else { led.blinkMessage(previous,none,previous,previous,previous); }   
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

void calculateNewDronePosition()
{
  // Set navigatio law INPUTS
  navigationLawInput[0] = rover.getLatitude();
  navigationLawInput[1] = rover.getLongitude();
  navigationLawInput[2] = rover.getRelativeAltitude();
  navigationLawInput[3] = rover.getGroundSpeed();
  navigationLawInput[4] = rover.getHeading();
  
  navigationLawInput[5] = multirotor_1.getLatitude();
  navigationLawInput[6] = multirotor_1.getLongitude();
  navigationLawInput[7] = multirotor_1.getRelativeAltitude();
  navigationLawInput[8] = multirotor_1.getGroundSpeed();
  navigationLawInput[9] = multirotor_1.getHeading();  

  navigationLawInput[10] = multirotor_2.getLatitude();
  navigationLawInput[11] = multirotor_2.getLongitude();
  navigationLawInput[12] = multirotor_2.getRelativeAltitude();
  navigationLawInput[13] = multirotor_2.getGroundSpeed();
  navigationLawInput[14] = multirotor_2.getHeading();  

 // Navigation Control Law
 navigationLawOutput[0] =  navigationLawInput[0];
 navigationLawOutput[1] =  navigationLawInput[1];
 navigationLawOutput[2] =  navigationLawInput[7];
 navigationLawOutput[3] =  navigationLawInput[0];
 navigationLawOutput[4] =  navigationLawInput[1];
 navigationLawOutput[5] =  navigationLawInput[12]; 
  
 //OUTPUTS:
  multirotor_1.setRifLatitude(navigationLawOutput[0]);
  multirotor_1.setRifLongitude(navigationLawOutput[1]);
  multirotor_1.setRifRelAltitude(navigationLawOutput[2]);

  /*multirotor_2.setRifLatitude(navigationLawOutput[3]); 
  multirotor_2.setRifLongitude(navigationLawOutput[4]);
  multirotor_2.setRifRelAltitude(navigationLawOutput[5]);*/
}

void sendWaypoints()
{
  multirotor_1.sendMissionItemNavWaypoint();
  multirotor_2.sendMissionItemNavWaypoint();
}
