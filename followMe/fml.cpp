
#include "fml.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



//
// costruttore
//
FmlDrone::FmlDrone(char* droneName,int droneId, int droneType, int droneAutopilot, int gcsId)
{
  name = droneName;
  id = droneId;
  type = droneType;
  autopilot = droneAutopilot; 
  gcs_id = gcsId;  
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


