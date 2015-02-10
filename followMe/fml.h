/*
*/

#ifndef __Fml_h
#define __Fml_h


#include "Arduino.h"
#include <limits.h>



struct FmlLocation
{
   friend class FmlDrone;

public:
   bool isValid() const    { return valid; }
   bool isUpdated() const  { return updated; }
   uint32_t age() const    { return valid ? millis() - lastCommitTime : (uint32_t)ULONG_MAX; }
   double lat();
   double lng();
   double relAlt();

   FmlLocation() : valid(false), updated(false)
   {}

private:
   bool valid, updated;
   double latData, lngData, relAltData; 
   uint32_t lastCommitTime;
   
   void commit();
   void setLatitude(double latitude);
   void setLongitude(double longitude);
   void setRelativeAltitude(double relativeAltitude);
};

struct FmlOther
{
   friend class FmlDrone;

public:
   bool isValid() const    { return valid; }
   bool isUpdated() const  { return updated; }
   uint32_t age() const    { return valid ? millis() - lastCommitTime : (uint32_t)ULONG_MAX; }
   double groundSpeed();
   double heading();

   FmlOther() : valid(false), updated(false)
   {}

private:
   bool valid, updated;
   double groundSpeedData, headingData; 
   uint32_t lastCommitTime;
   
   void commit();
   void groundSpeed(double groundSpeed);
   void setheading(double heading);
};




class FmlDrone
{
public:
  FmlDrone(char* name,int id, int type, int autopilot, int gcs_id);
  bool encode(char c); // process one character received from GPS
 
 /* double distanceBetweenDrone(FmlDrone drone);
  double courseTo(FmlDrone drone);*/

  FmlLocation location;
  FmlOther other;
  char* getName();
  int getId();
  int getType();
  int getAutopilot();
  int getGcsId();
private:
  //enum {MAV_PACKET_POS,MAV_PACKET_SPEED, MAV_PACKET_OTHER};
  char* name;
  int id;
  int type;
  int autopilot;
  int gcs_id;  
};

#endif // def(__FmlDrone_h)
