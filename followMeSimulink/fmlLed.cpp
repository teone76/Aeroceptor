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
// if you don't want to change one or more blink colors: type '_' following the order 
  if(first != '_') {ledMessage[0] = first;}
  if(second != '_') {ledMessage[1] = second;}
  if(third != '_') {ledMessage[2] = third;}
  if(fourth != '_') {ledMessage[3] = fourth;}
  if(fifth != '_') {ledMessage[4] = fifth;}
  
  Wire.beginTransmission(0x04);
  Wire.write('$');
  Wire.endTransmission();   
  Wire.beginTransmission(0x04);  
  Wire.write(ledMessage[0]);
  Wire.endTransmission();  
  Wire.beginTransmission(0x04);  
  Wire.write(ledMessage[1]);
  Wire.endTransmission();  
  Wire.beginTransmission(0x04);  
  Wire.write(ledMessage[2]);
  Wire.endTransmission();  
  Wire.beginTransmission(0x04);  
  Wire.write(ledMessage[3]);
  Wire.endTransmission();  
  Wire.beginTransmission(0x04);  
  Wire.write(ledMessage[4]);
  Wire.endTransmission();    
}

void FmlLed::blinkMessage()
{
  Wire.beginTransmission(0x04);
  Wire.write('$');
  Wire.endTransmission();   
  Wire.beginTransmission(0x04);  
  Wire.write(ledMessage[0]);
  Wire.endTransmission();  
  Wire.beginTransmission(0x04);  
  Wire.write(ledMessage[1]);
  Wire.endTransmission();  
  Wire.beginTransmission(0x04);  
  Wire.write(ledMessage[2]);
  Wire.endTransmission();  
  Wire.beginTransmission(0x04);  
  Wire.write(ledMessage[3]);
  Wire.endTransmission();  
  Wire.beginTransmission(0x04);  
  Wire.write(ledMessage[4]);
  Wire.endTransmission(); 
}
  
