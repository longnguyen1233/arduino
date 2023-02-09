#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(12, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void setup() 
{                 
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);  
  mySoftwareSerial.begin(9600);
  if (!myDFPlayer.begin(mySoftwareSerial, true, false)) {  while(true){delay(0); }   }
  myDFPlayer.volume(30); 
  myDFPlayer.play(1);
}

void loop() 
{
 if(digitalRead(2) == LOW) 
 {while(digitalRead(2) == LOW);
  myDFPlayer.next();
 }
 if(digitalRead(3) == LOW) 
 {while(digitalRead(3) == LOW);
  myDFPlayer.previous();
 }




}



























