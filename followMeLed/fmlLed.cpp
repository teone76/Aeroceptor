#include <Wire.h>
#include "fmlLed.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//
// costruttore
//
FmlLed::FmlLed(char* ledName)
{
  name = ledName; 
}

//
// public methods
//

char* FmlLed::getName()
{
  return name;
}

void FmlLed::blinkMessage(char first, char second, char third, char fourth, char fifth)
{
  Wire.beginTransmission(0x04);
  ledMessage[0] = ('$');
  ledMessage[1] = first;
  ledMessage[2] = second;
  ledMessage[3] = third;
  ledMessage[4] = fourth;
  ledMessage[5] = fifth;
  
  Wire.write(message,6);
  Wire.endTransmission();  
}

void FmlLed::blinkStatus()
{
  Wire.beginTransmission(0x04);
  ledMessage[0] = ('$');  
  Wire.write(message,6);
  Wire.endTransmission();  
}

