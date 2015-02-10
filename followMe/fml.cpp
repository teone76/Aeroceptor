
// Mavlink interface
#include "../GCS_MAVLink/include/mavlink/v1.0/common/mavlink.h"// Mavlink interface
#include "../GCS_MAVLink/include/mavlink/v1.0/ardupilotmega/ardupilotmega.h"
#include "../GCS_MAVLink/include/mavlink/v1.0/ardupilotmega/mavlink.h"
#include "../GCS_MAVLink/include/mavlink/v1.0/common/common.h"
#include "fml.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


//
// costruttore
//
FmlDrone::FmlDrone(char* droneName,int droneId, int droneType, int droneAutopilot, int gcsId, int serialPort)
{
  name = droneName;
  id = droneId;
  type = droneType;
  autopilot = droneAutopilot; 
  gcs_id = gcsId;  
  serial_port = serialPort;
}


//
// public methods
//

bool FmlDrone::encode(char c)
{  
  return false;
}

char* FmlDrone::getName()
{
  return name;
}

int FmlDrone::getId()
{
  return id;
}

int FmlDrone::getType()
{
  return type;
}

int FmlDrone::getAutopilot()
{
  return autopilot;
}

int FmlDrone::getGcsId()
{
  return gcs_id;
}

int FmlDrone::getSerialPort()
{
  return serial_port;
}

void FmlLocation::commit()
{
   lastCommitTime = millis();
   valid = updated = true;
}

void FmlLocation::setLatitude(double latitude)
{
   latData = latitude;
}

void FmlLocation::setLongitude(double longitude)
{
  lngData = longitude;
}

void FmlLocation::setRelativeAltitude(double relativeAltitude)
{
  relAltData = relativeAltitude;
}

double FmlLocation::lat()
{
   updated = false;
   return latData;
}

double FmlLocation::lng()
{
   updated = false;
   return lngData;
}

double FmlLocation::relAlt()
{
   updated = false;
   return relAltData;
}



//
// costruttore
//
Nav::Nav(char* navName)
{
  name = navName; 
}

char* Nav::getName()
{
  return name;
}

void Nav::sendHeartbeat(FmlDrone drone)
{
        // Define items for heartbeat
      mavlink_message_t msg;
      mavlink_heartbeat_t heartbeat;
      uint8_t buf[MAVLINK_MAX_PACKET_LEN];
      
      heartbeat.base_mode = 0; 
      heartbeat.custom_mode = 0;
      heartbeat.system_status = MAV_STATE_UNINIT;
      heartbeat.type = MAV_TYPE_GCS;  //MAV_TYPE_GCS if you want to comunicate with drone, MAV_TYPE_GENERIC if you want to comunicate with GCS
      heartbeat.autopilot = MAV_AUTOPILOT_INVALID;  
      // Pack the message
      // mavlink_msg_heartbeat_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t type, uint8_t autopilot)
      mavlink_msg_heartbeat_pack(drone.getGcsId(), drone.getGcsId(), &msg, heartbeat.type, heartbeat.autopilot, heartbeat.base_mode, heartbeat.custom_mode, heartbeat.system_status);
	
      // Copy the message to send buffer 
      uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

      // Send the message (.write sends as bytes) 	
      if(drone.getSerialPort()==1) {
        Serial1.write(buf, len); }
      else if(drone.getSerialPort()==2) { 
        Serial2.write(buf, len); }
      else {
    //Serial.println("Serial port error"); 
      }    
}

