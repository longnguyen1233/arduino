#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(8, 9); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
String text;
void setup() 
{                 
  
  mySoftwareSerial.begin(9600);
  if (!myDFPlayer.begin(mySoftwareSerial, true, false)) {  while(true){delay(0); }   }
  myDFPlayer.volume(30); 
  nhac_mo_dau();
}

void loop() 
{
  

}

void nhac_mo_dau()
{
myDFPlayer.play(1);
}



























