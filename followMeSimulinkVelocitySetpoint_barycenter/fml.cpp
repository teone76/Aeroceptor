
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
FmlDroneInterface::FmlDroneInterface(char* droneName,unsigned int droneId, int droneType, int droneAutopilot, unsigned int gcsId, int serialPort)
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
        case MAVLINK_MSG_ID_COMMAND_ACK: {
                     mavlink_msg_command_ack_decode(&msg, &command_ack);
                     Serial.print("COMMAND ACK: command: ");
                     Serial.println(command_ack.command);
                     switch (command_ack.result) {
                       case 0:
                       Serial.println("Command ACCEPTED and EXECUTED");
                       break;
                       case 1:
                       Serial.println("Command TEMPORARY REJECTED/DENIED");
                       break;
                       case 2:
                       Serial.println("Command PERMANENTLY DENIED");
                       break;                       
                       case 3:
                       Serial.println("Command UNKNOWN/UNSUPPORTED");
                       break;                       
                       case 4:
                       Serial.println("Command executed, but failed");
                       break;    
                     }
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
      else if(serial_port == 3) { 
        Serial3.write(buf, len); 
        /*Serial.println("");
        Serial.println("send data request to serial3");*/      
      }         
      else {
        //Serial.println("Serial port error"); 
      }    
}

void FmlDroneInterface::getDataStream(int param_id, int rate) {

   uint8_t buf[MAVLINK_MAX_PACKET_LEN];  
   request_data_stream.req_stream_id = param_id;  // 2:gps_status,  6: global position
   request_data_stream.req_message_rate = rate;
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
      Serial.println("send data request to serial3");*/      
    }          
    else {
    //Serial.println("Serial port error"); 
    }
 }

/*void FmlDroneInterface::sendNavGuided() 
{
  uint8_t buf[MAVLINK_MAX_PACKET_LEN];
  
 command_long.param1 = 1; ///< Parameter 1, as defined by MAV_CMD enum.
 command_long.param2 = 0; ///< Parameter 2, as defined by MAV_CMD enum.
 command_long.param3 = 0; ///< Parameter 3, as defined by MAV_CMD enum.
 command_long.param4 = 0; ///< Parameter 4, as defined by MAV_CMD enum.
 command_long.param5 = 0; ///< Parameter 5, as defined by MAV_CMD enum.
 command_long.param6 = 0; ///< Parameter 6, as defined by MAV_CMD enum.
 command_long.param7 = 0; ///< Parameter 7, as defined by MAV_CMD enum.
 command_long.command = 92; //MAV_CMD_NAV_GUIDED_ENABLE; ///< Command ID, as defined by MAV_CMD enum.
 command_long.target_system = id; ///< System which should execute the command
 command_long.target_component = id; ///< Component which should execute the command, 0 for all components
 command_long.confirmation = 0; ///< 0: First transmission of this command. 1-255: Confirmation transmissions (e.g. for kill command)
 
 mavlink_msg_command_long_pack(gcs_id, gcs_id, &msg, command_long.target_system, command_long.target_component, command_long.command, command_long.confirmation, command_long.param1, command_long.param2, command_long.param3, command_long.param4, command_long.param5, command_long.param6, command_long.param7);

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
      Serial.println(mission_item.z, 7);
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
      Serial.println(mission_item.z, 7);      
    }      
    else {
    //Serial.println("Serial port error"); 
    }   
    //mission_item.seq = mission_item.seq +1;    //DA CONTROLLARE
} */

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

void FmlDroneInterface::sendPositionTargetGlobalInt()
{
    uint8_t buf[MAVLINK_MAX_PACKET_LEN];
    //Serial.print(MAVLINK_MAX_PACKET_LEN); 
 position_target_global_int.time_boot_ms = 0; //millis(); ///< Timestamp in milliseconds since system boot. The rationale for the timestamp in the setpoint is to allow the system to compensate for the transport delay of the setpoint. This allows the system to compensate processing latency.
 position_target_global_int.lat_int = rif_location.lat(); ///< X Position in WGS84 frame in 1e7 * meters
 position_target_global_int.lon_int = rif_location.lng(); ///< Y Position in WGS84 frame in 1e7 * meters
 position_target_global_int.alt = rif_location.relAlt(); ///< Altitude in meters in WGS84 altitude, not AMSL if absolute or relative, above terrain if GLOBAL_TERRAIN_ALT_INT
 position_target_global_int.vx = rif_location.vx();   ///< X velocity in NED frame in meter / s
 position_target_global_int.vy = rif_location.vy();   ///< Y velocity in NED frame in meter / s
 position_target_global_int.vz = 0; ///< Z velocity in NED frame in meter / s
 position_target_global_int.afx = 0; ///< X acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 position_target_global_int.afy = 0; ///< Y acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 position_target_global_int.afz = 0; ///< Z acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 position_target_global_int.yaw = 0; //rif_location.hdg();  ///< yaw setpoint in rad
 position_target_global_int.yaw_rate = 0; ///< yaw rate setpoint in rad/s
 position_target_global_int.type_mask = 0b0000000111000111; ///< Bitmask to indicate which dimensions should be ignored by the vehicle: a value of 0b0000000000000000 or 0b0000001000000000 indicates that none of the setpoint dimensions should be ignored. If bit 10 is set the floats afx afy afz should be interpreted as force instead of acceleration. Mapping: bit 1: x, bit 2: y, bit 3: z, bit 4: vx, bit 5: vy, bit 6: vz, bit 7: ax, bit 8: ay, bit 9: az, bit 10: is force setpoint, bit 11: yaw, bit 12: yaw rate
 position_target_global_int.target_system; ///< System ID
 position_target_global_int.target_component; ///< Component ID
 position_target_global_int.coordinate_frame = 6; ///< Valid options are: MAV_FRAME_GLOBAL_INT = 5, MAV_FRAME_GLOBAL_RELATIVE_ALT_INT = 6, MAV_FRAME_GLOBAL_TERRAIN_ALT_INT = 11
 
/* position_target_local_ned.time_boot_ms = millis(); ///< Timestamp in milliseconds since system boot
 position_target_local_ned.x = 0; ///< X Position in NED frame in meters
 position_target_local_ned.y = 0; ///< Y Position in NED frame in meters
 position_target_local_ned.z = 0; ///< Z Position in NED frame in meters (note, altitude is negative in NED)
 position_target_local_ned.vx = 1; ///< X velocity in NED frame in meter / s
 position_target_local_ned.vy = 0; ///< Y velocity in NED frame in meter / s
 position_target_local_ned.vz = 0; ///< Z velocity in NED frame in meter / s
 position_target_local_ned.afx = 0; ///< X acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 position_target_local_ned.afy = 0; ///< Y acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 position_target_local_ned.afz = 0; ///< Z acceleration or force (if bit 10 of type_mask is set) in NED frame in meter / s^2 or N
 position_target_local_ned.yaw = 0; ///< yaw setpoint in rad
 position_target_local_ned.yaw_rate = 0; ///< yaw rate setpoint in rad/s
 position_target_local_ned.type_mask = 0b0000000111000111; ///< Bitmask to indicate which dimensions should be ignored by the vehicle: a value of 0b0000000000000000 or 0b0000001000000000 indicates that none of the setpoint dimensions should be ignored. If bit 10 is set the floats afx afy afz should be interpreted as force instead of acceleration. Mapping: bit 1: x, bit 2: y, bit 3: z, bit 4: vx, bit 5: vy, bit 6: vz, bit 7: ax, bit 8: ay, bit 9: az, bit 10: is force setpoint, bit 11: yaw, bit 12: yaw rate
 position_target_local_ned.target_system = id; ///< System ID
 position_target_local_ned.target_component = id; ///< Component ID
 position_target_local_ned.coordinate_frame = 1; ///< Valid options are: MAV_FRAME_LOCAL_NED = 1, MAV_FRAME_LOCAL_OFFSET_NED = 7, MAV_FRAME_BODY_NED = 8, MAV_FRAME_BODY_OFFSET_NED = 9 */
    
    // Pack the message
    // mavlink_msg_set_position_target_global_int_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
    //					                                       uint32_t time_boot_ms, uint8_t target_system, uint8_t target_component, uint8_t coordinate_frame, uint16_t type_mask, int32_t lat_int, int32_t lon_int, float alt, float vx, float vy, float vz, float afx, float afy, float afz, float yaw, float yaw_rate)
    mavlink_msg_set_position_target_global_int_pack(gcs_id, gcs_id, &msg, position_target_global_int.time_boot_ms, id, id, position_target_global_int.coordinate_frame, position_target_global_int.type_mask, position_target_global_int.lat_int, position_target_global_int.lon_int, position_target_global_int.alt, position_target_global_int.vx, position_target_global_int.vy, position_target_global_int.vz, position_target_global_int.afx, position_target_global_int.afy, position_target_global_int.afz, position_target_global_int.yaw, position_target_global_int.yaw_rate);
    
    // mavlink_msg_set_position_target_local_ned_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
    //						       uint32_t time_boot_ms, uint8_t target_system, uint8_t target_component, uint8_t coordinate_frame, uint16_t type_mask, float x, float y, float z, float vx, float vy, float vz, float afx, float afy, float afz, float yaw, float yaw_rate)
   // mavlink_msg_set_position_target_local_ned_pack(gcs_id, gcs_id, &msg, position_target_local_ned.time_boot_ms, id, id, position_target_local_ned.coordinate_frame, position_target_local_ned.type_mask, position_target_local_ned.x, position_target_local_ned.y, position_target_local_ned.z, position_target_local_ned.vx, position_target_local_ned.vy, position_target_local_ned.vz, position_target_local_ned.afx, position_target_local_ned.afy, position_target_local_ned.afz, position_target_local_ned.yaw, position_target_local_ned.yaw_rate);   
    // Copy the message to send buffer 
    uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
    
    
       /* switch(msg.msgid) {
        case MAVLINK_MSG_ID_SET_POSITION_TARGET_GLOBAL_INT: {
          mavlink_msg_set_position_target_global_int_decode(&msg, &packet);
          
        bool pos_ignore      = packet.type_mask & 0b111;  //001 | 010 | 100 ->  0000000000000111 
        bool vel_ignore      = packet.type_mask & 0b111000;
        bool acc_ignore      = packet.type_mask & 0b111000000;          
        Serial.println(pos_ignore);
        Serial.println(vel_ignore);
        Serial.println(acc_ignore);
        Serial.println(packet.lat_int);
         Serial.println(packet.lon_int);
        Serial.println(packet.type_mask, BIN);
        }
        break;
        default:
	     //Do nothing
        break;
      } 	*/
    // Send the message (.write sends as bytes) 	
    if(serial_port == 1) {
      Serial1.write(buf, len);
      //Serial.print(len);
      //Serial.println("MESSAGGIO INVIATO"); 
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



