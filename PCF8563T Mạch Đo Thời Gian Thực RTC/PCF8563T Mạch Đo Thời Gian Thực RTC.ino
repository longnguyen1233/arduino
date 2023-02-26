 /*  
modified on Nov 16, 2020
Modified by MehranMaleki from Arduino Examples
Home
*/

#include <Wire.h>
#include <Rtc_Pcf8563.h>

//init the real-time clock
Rtc_Pcf8563 rtc;
 
 
void setup()
{
  Serial.begin(9600);
  Wire.begin();
  
  //clear out all the registers
  rtc.initClock();
  //set a time to start with.
  //day, weekday, month, century, year
  rtc.setDate(16, 3, 11, 20, 20);
  //hr, min, sec
  rtc.setTime(11, 0, 0);
}
                                                                                
void loop()
{

  Serial.print("Time:");
  //Serial.print(rtc.formatTime(RTCC_TIME_HM));
  Serial.print(rtc.formatTime());
  

  Serial.print("\t Date:");
  //Serial.println(rtc.formatDate(RTCC_DATE_ASIA));
  Serial.println(rtc.formatDate());

  
  delay(1000);
    
}
  
