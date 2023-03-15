#include "LedControl.h"
 
LedControl lc=LedControl(12,11,10,1);
// pin 12 ____________________DIN pin
// pin 11 ____________________CLK pin
// pin 10 ____________________CS pin
// 
 
void setup()
{
  // the zero refers to the MAX7219 number, it is zero for 1 chip
  lc.shutdown(0,false);// turn off power saving, enables display
  lc.setIntensity(0,8);// sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen
}
 
void loop()
{
  //numbers 7 to 0
  for (int a=0; a<8; a++)
  {
    lc.setDigit(0,a,a,false);
    delay(100);
  }
  delay(1000);
  //display number 8 on all segments
  for (int a=0; a<8; a++)
  {
    lc.setDigit(0,a,8,false);
    delay(100);
  }
  delay(1000);
  //
  for (int a=8; a>=0; a--)
  {
    lc.setDigit(0,a,a,false);
    delay(100);
  }
}