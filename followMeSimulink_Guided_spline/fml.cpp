
//Mavlink interface
#include "../GCS_MAVLink/include/mavlink/v1.0/common/mavlink.h"// Mavlink interface
#include "../GCS_MAVLink/include/mavlink/v1.0/ardupilotmega/ardupilotmega.h"
#include "../GCS_MAVLink/include/mavlink/v1.0/ardupilotmega/mavlink.h"
#include "../GCS_MAVLink/include/mavlink/v1.0/common/common.h" 

#include "fml.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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
    if (mavlink_parse_char(MAVLINK_COMM_1, c, &msg, &status)) {this->identifyMavMsg();
    }
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

int FmlDroneInterface::getSatVisible()
{
  return satVisible;
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

void FmlDroneInterface::setRifVx(float rifVx){
  rif_location.vxData = rifVx;
}

void FmlDroneInterface::setRifVy(float rifVy){
  rif_location.vyData = rifVy;
}

void FmlDroneInterface::setRifYaw(float rifYaw){
  rif_location.yawData = rifYaw;
}

void FmlDroneInterface::setRifYawRate(float rifYawRate){
  rif_location.yawRateData = rifYawRate;
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

float FmlDroneInterface::getVx(){
  location.updated = false;
  return location.vx();
}

float FmlDroneInterface::getVy(){
  location.updated = false;
  return location.vy();
}

float FmlDroneInterface::getRifVx(){
  return rif_location.vx();
}

float FmlDroneInterface::getRifVy(){
  return rif_location.vy();
}
  
float FmlDroneInterface::getGroundSpeed(){
  location.updated = false;
  return location.gs();
}

float FmlDroneInterface::getHeading(){
  location.updated = false;
  return location.hdg();
}

float FmlDroneInterface::getYaw(){
  location.updated = false;
  return location.yaw();
}

float FmlDroneInterface::getYawRate(){
  location.updated = false;
  return location.yawRate();
}

void FmlDroneInterface::setSatVisible(int nSat){
  satVisible = nSat;
}

bool FmlDroneInterface::isLocationUpdated(){
  return location.isUpdated();
}

/*bool FmlDroneInterface::isOtherUpdated(){
  return other.isUpdated();
}*/

bool FmlDroneInterface::isGpsFixed(){
  return ((location.lat()!= 0) && (location.lng()!= 0) && (getSatVisible() > 0));
}

bool FmlDroneInterface::isDroneConnected(){
  return ((millis() - this->lastConnectionTime)<3000);
}

void FmlDroneInterface::identifyMavMsg()
{
   switch(msg.msgid) {
        case MAVLINK_MSG_ID_HEARTBEAT: { 
             this->lastConnectionTime = millis();          
        }
	break;
        case MAVLINK_MSG_ID_GPS_RAW_INT: {
             mavlink_msg_gps_raw_int_decode(&msg, &gps_raw_int);  
             setSatVisible(gps_raw_int.satellites_visible); 
        }
	break;
        case MAVLINK_MSG_ID_GLOBAL_POSITION_INT: {  
             mavlink_msg_global_position_int_decode(&msg, &global_position_int); 
             
             location.setLatitude(((float)global_position_int.lat)*0.0000001);                      //latitude     
             location.setLongitude(((float)global_position_int.lon)*0.0000001);                     //longitude
             location.setRelativeAltitude(((float)global_position_int.relative_alt)*0.001);         // Altitude above ground in meters   
             
             location.setVx(((float)global_position_int.vx)*0.01);             // Ground X Speed (Latitude), expressed as m/s * 100
             location.setVy(((float)global_position_int.vy)*0.01);             // Ground Y Speed (Longitude), expressed as m/s * 100
             location.setHdg(((float)global_position_int.hdg)*0.01);                  // Compass heading in degrees * 100, 0.0..359.99 degrees. If unknown, set to: UINT16_MAX
             location.setGs(global_position_int.vx, global_position_int.vy);   // GroundSpeed expressed as m/s
  
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
       /* case MAVLINK_MSG_ID_VFR_HUD: {
             mavlink_msg_vfr_hud_decode(&msg, &vfr_hud);
             
             other.setGroundSpeed(vfr_hud.groundspeed);          ///< Current ground speed in m/s
             other.setHeading((float)vfr_hud.heading);           ///< Current heading in degrees, in compass units (0..360, 0=north)
             other.updated = true; 
             Serial.println("receive vfr hud from serial port ");
             Serial.println(serial_port);
             Serial.print("GND SPD: ");
             Serial.println(getGroundSpeed(), 7);
             Serial.print("HDG: ");
             Serial.println(getHeading(), 7);
        }
        break;*/
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

void FmlDroneInterface::getDataStream(int param_id) {

   uint8_t buf[MAVLINK_MAX_PACKET_LEN];  
   request_data_stream.req_stream_id = param_id;  // 2:gps_status,  6: global position
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
    else if(serial_port == 3) { 
      Serial3.write(buf, len); 
      /*Serial.println("");
      Serial.println("send data request to serial2");*/      
    }          
    else {
    //Serial.println("Serial port error"); 
    }
 }

void FmlDroneInterface::sendPositionTargetGlobalInt()
{
    uint8_t buf[MAVLINK_MAX_PACKET_LEN];
    
 position_target_global_int.time_boot_ms = millis(); ///< Timestamp in milliseconds since system boot. The rationale for the timestamp in the setpoint is to allow the system to compensate for the transport delay of the setpoint. This allows the system to compensate processing latency.
 position_target_global_int.lat_int = rif_location.lat(); ///< X Position in WGS84 frame in 1e7 * meters
 position_target_global_int.lon_int = rif_location.lng(); ///< Y Position in WGS84 frame in 1e7 * meters
 position_target_global_int.alt = rif_location.relAlt(); ///< Altitude in meters in WGS84 altitude, not AMSL if absolute or relative, above terrain if GLOBAL_TERRAIN_ALT_INT
 position_target_global_int.vx = 0; //rif_location.vx();   ///< X velocity in NED frame in meter / s
 position_target_global_int.vy = 0; //rif_location.vy();   ///< Y velocity in NED frame in meter / s
 position_target_global_int.vz = 0; ///< Z velocity in NED frame in meter / s
 position_target_global_int.afx = 0; ///< X acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 position_target_global_int.afy = 0; ///< Y acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 position_target_global_int.afz = 0; ///< Z acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 position_target_global_int.yaw = 0; //rif_location.hdg();  ///< yaw setpoint in rad
 position_target_global_int.yaw_rate = 0; ///< yaw rate setpoint in rad/s
 position_target_global_int.type_mask = 0b0000110111111000; ///< Bitmask to indicate which dimensions should be ignored by the vehicle: a value of 0b0000000000000000 or 0b0000001000000000 indicates that none of the setpoint dimensions should be ignored. If bit 10 is set the floats afx afy afz should be interpreted as force instead of acceleration. Mapping: bit 1: x, bit 2: y, bit 3: z, bit 4: vx, bit 5: vy, bit 6: vz, bit 7: ax, bit 8: ay, bit 9: az, bit 10: is force setpoint, bit 11: yaw, bit 12: yaw rate
 position_target_global_int.target_system; ///< System ID
 position_target_global_int.target_component; ///< Component ID
 position_target_global_int.coordinate_frame = 6; ///< Valid options are: MAV_FRAME_GLOBAL_INT = 5, MAV_FRAME_GLOBAL_RELATIVE_ALT_INT = 6, MAV_FRAME_GLOBAL_TERRAIN_ALT_INT = 11
    
    // Pack the message
    // mavlink_msg_set_position_target_global_int_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
    //					                                       uint32_t time_boot_ms, uint8_t target_system, uint8_t target_component, uint8_t coordinate_frame, uint16_t type_mask, int32_t lat_int, int32_t lon_int, float alt, float vx, float vy, float vz, float afx, float afy, float afz, float yaw, float yaw_rate)
    mavlink_msg_set_position_target_global_int_pack(gcs_id, gcs_id, &msg, position_target_global_int.time_boot_ms, id, id, position_target_global_int.coordinate_frame, position_target_global_int.type_mask, position_target_global_int.lat_int, position_target_global_int.lon_int, position_target_global_int.alt, position_target_global_int.vx, position_target_global_int.vy, position_target_global_int.vz, position_target_global_int.afx, position_target_global_int.afy, position_target_global_int.afz, position_target_global_int.yaw, position_target_global_int.yaw_rate);
      
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

void FmlLocation::setVx(float vx)
{
  vxData = vx;
}

void FmlLocation::setVy(float vy)
{
  vyData = vy;
}

void FmlLocation::setHdg(float hdg)
{
  hdgData = hdg;
}

void FmlLocation::setGs(int16_t vx, int16_t vy)
{
  gsData = (float) (sqrt((long)vx * (long)vx + (long)vy * (long)vy )*0.01);
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

float FmlLocation::vx()
{
   updated = false;
   return vxData;
}

float FmlLocation::vy()
{
   updated = false;
   return vyData;
}

float FmlLocation::hdg()
{
   updated = false;
   return hdgData;
}

float FmlLocation::gs()
{
   updated = false;
   return gsData;
}

float FmlLocation::yaw()
{
   updated = false;
   return yawData;
}

float FmlLocation::yawRate()
{
   updated = false;
   return yawRateData;
}

/*void FmlOther::commit()
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
}*/

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



