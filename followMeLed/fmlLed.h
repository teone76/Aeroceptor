/*
*/
#include <Wire.h>

#ifndef __FmlLed_h
#define __FmlLed_h


#include "Arduino.h"
#include <limits.h>

// Led
class FmlLed
{
public:

  FmlLed(char* name);
  char* getName();
  char ledMessage[6];
/* blinkStatus function --> blinkStatus(char first, char second, char third, char fourth, char fifth) 
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
   A1234 -> red-blue-green-white    -    blinkStatus('A','1','2','3','4');
   C2___ -> blue...for 10seconds    -    blinkStatus('C','2','_','_','_');
   R7715 -> azure-azure-red-yellow    -    blinkStatus('R','7','7','1','5');
   S6___ -> purple-purple-purple...25times    -    blinkStatus('T','6','_','_','_');
   */
  
  void blinkMessage(char first, char second, char third, char fourth, char fifth);
  void blinkStatus(); 
private:

  char* name;  
};

#endif // def(__FmlDrone_h)
