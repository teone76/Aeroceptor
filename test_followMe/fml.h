/*
*/

// Mavlink interface
#include "../GCS_MAVLink/include/mavlink/v1.0/common/mavlink.h"// Mavlink interface
#include "../GCS_MAVLink/include/mavlink/v1.0/ardupilotmega/ardupilotmega.h"
#include "../GCS_MAVLink/include/mavlink/v1.0/ardupilotmega/mavlink.h"
#include "../GCS_MAVLink/include/mavlink/v1.0/common/common.h"

#ifndef __Fml_h
#define __Fml_h


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
   FmlLocation() : valid(false), updated(false)
   {}

private:
   bool valid, updated;
   float latData, lngData, relAltData; 
   uint32_t lastCommitTime;
   
   void commit();
   void setLatitude(float latitude);
   void setLongitude(float longitude);
   void setRelativeAltitude(float relativeAltitude);
};

struct FmlOther
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
};




class FmlDroneInterface
{
public:

  FmlDroneInterface(char* name,int id, int type, int autopilot, int gcs_id, int serial_port);
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
  void sendMavMsgHeartbeat();
  void sendMissionItemNavWaypoint();
  void getDataStream();
  void setRifLatitude(float rifLatitude);
  void setRifLongitude(float rifLongitude);
  void setRifRelAltitude(float rifAltitude);
  
  float getLatitude();
  float getLongitude();
  float getRelativeAltitude();
  float getGroundSpeed();
  float getHeading();
  
private:
  FmlLocation location;
  FmlLocation rif_location;
  FmlOther other;
  char* name;
  int id;
  int type;
  int autopilot;
  int gcs_id;  
  int serial_port;
  mavlink_message_t msg;
  mavlink_status_t status;
  mavlink_heartbeat_t heartbeat;
  mavlink_global_position_int_t global_position_int;
  mavlink_vfr_hud_t vfr_hud; 
  mavlink_mission_item_t mission_item; 
  mavlink_request_data_stream_t request_data_stream;
  void identifyMavMsg();
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
