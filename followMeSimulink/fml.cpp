
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
FmlDroneInterface::FmlDroneInterface(char* droneName,int droneId, int droneType, int droneAutopilot, int gcsId, int serialPort)
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

void FmlDroneInterface::encode(char c)
{  
    //try to get a new message 
    if (mavlink_parse_char(MAVLINK_COMM_1, c, &msg, &status)) {this->identifyMavMsg();}
}

char* FmlDroneInterface::getName()
{
  return name;
}

int FmlDroneInterface::getId()
{
  return id;
}

int FmlDroneInterface::getType()
{
  return type;
}

int FmlDroneInterface::getAutopilot()
{
  return autopilot;
}

int FmlDroneInterface::getGcsId()
{
  return gcs_id;
}

int FmlDroneInterface::getSerialPort()
{
  return serial_port;
}

void FmlDroneInterface::setRifLatitude(float rifLatitude){
  rif_location.latData = rifLatitude;
}

void FmlDroneInterface::setRifLongitude(float rifLongitude){
  rif_location.lngData = rifLongitude;
}

void FmlDroneInterface::setRifRelAltitude(float rifRelAltitude){
  rif_location.relAltData = rifRelAltitude;
}
  
float FmlDroneInterface::getLatitude(){
  location.updated = false;
  return location.lat();
}

float FmlDroneInterface::getLongitude(){
  location.updated = false;
  return location.lng();
}

float FmlDroneInterface::getRelativeAltitude(){
  location.updated = false;
  return location.relAlt();
} 
  
float FmlDroneInterface::getGroundSpeed(){
  other.updated = false;
  return other.gs();
}

bool FmlDroneInterface::isLocationUpdated(){
  return location.isUpdated();
}

bool FmlDroneInterface::isOtherUpdated(){
  return other.isUpdated();
}

bool FmlDroneInterface::isGpsFixed(){
  return ((location.lat()!= 0) && (location.lng()!= 0));
}

bool FmlDroneInterface::isDroneConnected(){
  return ((millis() - this->lastConnectionTime)<3000);
}

float FmlDroneInterface::getHeading(){
  other.updated = false;
  return other.hdg();
}

void FmlDroneInterface::identifyMavMsg()
{
   switch(msg.msgid) {
        case MAVLINK_MSG_ID_HEARTBEAT: {
          this->lastConnectionTime = millis();                 
        }
	break;
        case MAVLINK_MSG_ID_GLOBAL_POSITION_INT: {  
          
             mavlink_msg_global_position_int_decode(&msg, &global_position_int); 
             
             location.setLatitude(((float)global_position_int.lat)*0.0000001);                      //latitude     
             location.setLongitude(((float)global_position_int.lon)*0.0000001);                     //longitude
             location.setRelativeAltitude(((float)global_position_int.relative_alt)*0.001);         // Altitude above ground in meters   
             location.updated = true; 
             /*Serial.print("receive from serial port ");
             Serial.print(serial_port);
             Serial.print(" LAT: ");
             Serial.print(getLatitude(), 7);
             Serial.print(" LNG: ");
             Serial.print(getLongitude(), 7);
             Serial.print(" REL ALT: "); 
             Serial.print(getRelativeAltitude(), 7);   */
        }
        break;
        case MAVLINK_MSG_ID_VFR_HUD: {
             mavlink_msg_vfr_hud_decode(&msg, &vfr_hud);
             
             other.setGroundSpeed(vfr_hud.groundspeed);          ///< Current ground speed in m/s
             other.setHeading((float)vfr_hud.heading);           ///< Current heading in degrees, in compass units (0..360, 0=north)
             other.updated = true; 
             /*Serial.println("receive vfr hud from serial port ");
             Serial.println(serial_port);
             Serial.print("GND SPD: ");
             Serial.println(getGroundSpeed(), 7);
             Serial.print("HDG: ");
             Serial.println(getHeading(), 7);*/
        }
        break;
        default:
	     //Do nothing
        break;
 } 
}

void FmlDroneInterface::sendMavMsgHeartbeat()
{
      uint8_t buf[MAVLINK_MAX_PACKET_LEN];
      // Define items for heartbeat
      heartbeat.base_mode = 0; 
      heartbeat.custom_mode = 0;
      heartbeat.system_status = MAV_STATE_UNINIT;
      heartbeat.type = MAV_TYPE_GCS;  //MAV_TYPE_GCS if you want to comunicate with drone, MAV_TYPE_GENERIC if you want to comunicate with GCS
      heartbeat.autopilot = MAV_AUTOPILOT_INVALID;  
      // Pack the message
      // mavlink_msg_heartbeat_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t type, uint8_t autopilot)
      mavlink_msg_heartbeat_pack(gcs_id, gcs_id, &msg, heartbeat.type, heartbeat.autopilot, heartbeat.base_mode, heartbeat.custom_mode, heartbeat.system_status);
	
      // Copy the message to send buffer 
      uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

      // Send the message (.write sends as bytes) 	
      if(serial_port == 1) {
        Serial1.write(buf, len); 
        /*Serial.println("");
        Serial.println("send heartbeat to serial1");*/ }
      else if(serial_port == 2) { 
        Serial2.write(buf, len); 
        /*Serial.println("");
        Serial.println("send heartbeat to serial2"); */}
      else {
    //Serial.println("Serial port error"); 
      }    
}

void FmlDroneInterface::getDataStream() {

   uint8_t buf[MAVLINK_MAX_PACKET_LEN];  
   request_data_stream.req_stream_id = 6;
   request_data_stream.req_message_rate = 3;
   request_data_stream.start_stop = 1;    
    mavlink_msg_request_data_stream_pack(gcs_id, gcs_id, &msg, id, id, request_data_stream.req_stream_id, request_data_stream.req_message_rate, request_data_stream.start_stop);    
   
   // Copy the message to send buffer 
    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
	
    // Send the message (.write sends as bytes) 	
    if(serial_port == 1) {
      Serial1.write(buf, len); 
      /*Serial.println("");
      Serial.println("send data request to serial1");*/
    }     
    else if(serial_port == 2) { 
      Serial2.write(buf, len); 
      /*Serial.println("");
      Serial.println("send data request to serial2");*/      
    }      
    else {
    //Serial.println("Serial port error"); 
    }
 }

void FmlDroneInterface::sendMissionItemNavWaypoint()
{
    uint8_t buf[MAVLINK_MAX_PACKET_LEN];
    //Define items for mission_item messages
    //mission_item.seq; //sequence
    mission_item.frame = MAV_FRAME_GLOBAL_RELATIVE_ALT; // The coordinate system of the MISSION
    mission_item.current = 2; // current = 2 is a flag to tell us this is a "guided mode" waypoint and not for the mission
    mission_item.autocontinue = 1; // autocontinue to next wp
    mission_item.command = MAV_CMD_NAV_WAYPOINT; // The scheduled action for the MISSION. see MAV_CMD in common.xml MAVLink specs.
    mission_item.param1 = 0; // Hold time in decimal seconds. (ignored by fixed wing, time to stay at MISSION for rotary wing)
    mission_item.param2 = 0; // Acceptance radius in meters (if the sphere with this radius is hit, the MISSION counts as reached)
    mission_item.param3 = 0; // 0 to pass through the WP, if > 0 radius in meters to pass by WP. Positive value for clockwise orbit, negative value for counter-clockwise orbit. Allows trajectory control.
    mission_item.param4 = 0; // Desired yaw angle at MISSION (rotary wing)   
    
    mission_item.x = rif_location.lat();
    mission_item.y = rif_location.lng();    
    mission_item.z = rif_location.relAlt(); //meters
    
    // Pack the message
    // uint16_t mavlink_msg_mission_item_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t frame,
    //                                            uint16_t command, uint8_t current, uint8_t autocontinue, float param1, float param2, float param3, float param4, float x, float y, float z)
    mavlink_msg_mission_item_pack(gcs_id, gcs_id, &msg, id, id, mission_item.seq, mission_item.frame, mission_item.command, mission_item.current, mission_item.autocontinue, mission_item.param1, mission_item.param2, mission_item.param3, mission_item.param4, mission_item.x, mission_item.y, mission_item.z);
      
    // Copy the message to send buffer 
    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
	
    // Send the message (.write sends as bytes) 	
    if(serial_port == 1) {
      Serial1.write(buf, len); 
      /*Serial.println("");
      Serial.println("send waypoint to serial1");
      Serial.println("lat    lng    rel_alt");
      Serial.print(mission_item.x, 7);
      Serial.print("    ");
      Serial.print(mission_item.y, 7);
      Serial.print("    ");
      Serial.println(mission_item.z, 7);*/
    }     
    else if(serial_port == 2) { 
      Serial2.write(buf, len); 
      /*Serial.println("");
      Serial.println("send waypoint to serial2"); 
      Serial.println("lat    lng    rel_alt");
      Serial.print(mission_item.x, 7);
      Serial.print("    ");
      Serial.print(mission_item.y, 7);
      Serial.print("    ");
      Serial.println(mission_item.z, 7);*/      
    }      
    else {
    //Serial.println("Serial port error"); 
    }   
    //mission_item.seq = mission_item.seq +1;    //DA CONTROLLARE
}

void FmlLocation::commit()
{
   lastCommitTime = millis();
   valid = updated = true;
}

void FmlLocation::setLatitude(float latitude)
{
   latData = latitude;
}

void FmlLocation::setLongitude(float longitude)
{
  lngData = longitude;
}

void FmlLocation::setRelativeAltitude(float relativeAltitude)
{
  relAltData = relativeAltitude;
}

float FmlLocation::lat()
{
   updated = false;
   return latData;
}

float FmlLocation::lng()
{
   updated = false;
   return lngData;
}

float FmlLocation::relAlt()
{
   updated = false;
   return relAltData;
}

void FmlOther::commit()
{
   lastCommitTime = millis();
   valid = updated = true;
}

void FmlOther::setGroundSpeed(float groundspeed)
{
   groundSpeedData = groundspeed;
}

void FmlOther::setHeading(float heading)
{
   headingData = heading;
}

float FmlOther::gs()
{
   updated = false;
   return groundSpeedData;
}

float FmlOther::hdg()
{
   updated = false;
   return headingData;
}

//
// costruttore
//
FmlNav::FmlNav(char* navName)
{
  name = navName; 
}

char* FmlNav::getName()
{
  return name;
}



