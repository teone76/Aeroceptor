/*
*/
#include <Wire.h>

#ifndef __FmlMsgLed_h
#define __FmlMsgLed_h

#define red '1'
#define blue '2'
#define green '3'
#define white '4'
#define yellow '5'
#define purple '6'
#define azure '7'
#define none '0'
#define previous '_'

#include "Arduino.h"
#include <limits.h>

// Led
class FmlMsgLed
{
public:

  FmlMsgLed(char* name);
  char* getName();
  char ledMessage[5];
/* blinkStatus function --> blinkMessage(char first, char second, char third, char fourth, char fifth) 
    Inputs explanation:
     first char is a capital char, meaning:
      Normal priority:
       A: ....                          (4 flashes, 4 colors)
       B: .........................     (25 flashes, 1 color)
       C: _________________________     (1 extended flash, 1 color)   
   
      High priority:    (this type of message start immediately)
       R: ....                          (4 flashes, 4 colors)
       S: .........................     (25 flashes, 1 color)
       T: _________________________     (1 extended flash, 1 color)   
   
    Available colors:
    1:red, 2:blue, 3:green, 4:white, 5:yellow, 6:purple, 7:azure
   
   examples:
   A1234 -> red-blue-green-white    -    blinkMessage('A','1','2','3','4');
   C2___ -> blue...for 10seconds    -    blinkMessage('C','2','_','_','_');
   R7715 -> azure-azure-red-yellow    -    blinkMessage('R','7','7','1','5');
   S6___ -> purple-purple-purple...25times    -    blinkMessage('T','6','_','_','_');
   */
  
  void blinkMessage(char first, char second, char third, char fourth, char fifth);
  void blinkMessage();
  void setMessage(char first, char second, char third, char fourth, char fifth);  
private:

  char* name;  
};

#endif // def(__FmlDrone_h)
