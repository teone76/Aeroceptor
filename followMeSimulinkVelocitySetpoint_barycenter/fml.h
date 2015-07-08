/*
*/

// Mavlink interface
#include "../GCS_MAVLink/include/mavlink/v1.0/common/mavlink.h"// Mavlink interface
#include "../GCS_MAVLink/include/mavlink/v1.0/ardupilotmega/ardupilotmega.h"
#include "../GCS_MAVLink/include/mavlink/v1.0/common/mavlink_msg_set_position_target_global_int.h"
#include "../GCS_MAVLink/include/mavlink/v1.0/common/mavlink_msg_set_position_target_local_ned.h"
#include "../GCS_MAVLink/include/mavlink/v1.0/ardupilotmega/mavlink.h"
#include "../GCS_MAVLink/include/mavlink/v1.0/common/common.h" 

#ifndef __Fml_h
#define __Fml_h

#define Fml_data_stream_all 0
#define Fml_gps_status 1
#define Fml_global_position 6

#include "Arduino.h"
#include <limits.h>



struct FmlLocation
{
   friend class FmlDroneInterface;

public:
   bool isValid() const    { return valid; }
   bool isUpdated() const  { return updated; }
   uint32_t age() const    { return valid ? millis() - lastCommitTime : (uint32_t)ULONG_MAX; }
   float lat();
   float lng();
   float relAlt();
   float vx();
   float vy();
   float hdg();
   float gs();
   float yaw();
   float yawRate();
   FmlLocation() : valid(false), updated(false)
   {}

private:
   bool valid, updated;
   float latData, lngData, relAltData, vxData, vyData, hdgData, gsData, yawData, yawRateData; 
   uint32_t lastCommitTime;
   
   void commit();
   void setLatitude(float latitude);
   void setLongitude(float longitude);
   void setRelativeAltitude(float relativeAltitude);
   void setVx(float vx);
   void setVy(float vy);
   void setHdg(float hdg);
   void setGs(int16_t vx, int16_t vy);
};

/*struct FmlOther
{
   friend class FmlDroneInterface;

public:
   bool isValid() const    { return valid; }
   bool isUpdated() const  { return updated; }
   uint32_t age() const    { return valid ? millis() - lastCommitTime : (uint32_t)ULONG_MAX; }
   float gs();
   float hdg();

   FmlOther() : valid(false), updated(false)
   {}

private:
   bool valid, updated;
   float groundSpeedData, headingData; 
   uint32_t lastCommitTime;
   
   void commit();
   void setGroundSpeed(float groundspeed);
   void setHeading(float heading);
}; */




class FmlDroneInterface
{
public:

  FmlDroneInterface(char* name,unsigned int id, int type, int autopilot,unsigned int gcs_id, int serial_port);
  void encode(char c); // process one character received from GPS
 
 /* double distanceBetweenDrone(FmlDrone drone);
  double courseTo(FmlDrone drone);*/

  

  char* getName();
  int getId();
  int getType();
  int getAutopilot();
  int getGcsId();
  int getSerialPort();
  bool isLocationUpdated();
//  bool isOtherUpdated();
  bool isGpsFixed();
  bool isDroneConnected();  
  void sendMavMsgHeartbeat();
  void sendMissionItemNavWaypoint();
  void sendPositionTargetGlobalInt();
  //void sendNavGuided();
  void getDataStream(int param_id, int rate);
  void setRifLatitude(float rifLatitude);
  void setRifLongitude(float rifLongitude);
  void setRifRelAltitude(float rifRelAltitude);
  void setRifVx(float rifVx);
  void setRifVy(float rifVy);
  void setRifYaw(float rifYaw);
  void setRifYawRate(float rifYawRate);
  void setSatVisible(int nSat);
  int getSatVisible();
  float getLatitude();
  float getLongitude();
  float getRelativeAltitude();
  float getVx();
  float getVy();
  float getRifVx();
  float getRifVy();
  float getGroundSpeed();
  float getHeading();
  float getYaw();
  float getYawRate();
  
private:
  FmlLocation location;
  FmlLocation rif_location;
//  FmlOther other;
  char* name;
  int id;
  int type;
  int autopilot;
  int gcs_id;  
  int serial_port;
  mavlink_message_t msg;
  mavlink_status_t status;
  mavlink_heartbeat_t heartbeat;
  mavlink_mission_item_t mission_item; 
  mavlink_global_position_int_t global_position_int;
  mavlink_vfr_hud_t vfr_hud; 
  mavlink_set_position_target_global_int_t position_target_global_int; 
  //mavlink_set_position_target_local_ned_t position_target_local_ned;
  //mavlink_command_long_t command_long;
 // mavlink_set_position_target_global_int_t packet;
  mavlink_request_data_stream_t request_data_stream;
  mavlink_gps_raw_int_t gps_raw_int;
  mavlink_command_ack_t command_ack;
  void identifyMavMsg();
  unsigned long lastConnectionTime;  
  int satVisible;
};


class FmlNav
{
public:

  FmlNav(char* name);
  char* getName();
  
private:

  char* name;  
};

#endif // def(__FmlDrone_h)
