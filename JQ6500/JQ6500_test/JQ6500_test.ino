#include <Arduino.h>
#include <SoftwareSerial.h>
#include <JQ6500_Serial.h>

String text;

SoftwareSerial mySerial(8, 9);
JQ6500_Serial mp3(mySerial);

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  mp3.reset();
  mp3.setVolume(10);
  mp3.setLoopMode(MP3_LOOP_ALL);
  mp3.play();  
  
}

void loop() {
  if(Serial.available()) { 
    text = Serial.readStringUntil('\n'); 
      
        if(text == "n") {
            mp3.next();     
            Serial.println("Next");
        }
        
        else if(text == "p") {
            mp3.prev();
            Serial.println("Prev");
        }
        else if(text == "1") {
            mp3.setVolume(10);
            mp3.play(); 
            Serial.println("Volume 30%");
        }
        else if(text == "2") {
            mp3.setVolume(20);
            mp3.play(); 
            Serial.println("Volume 70%");
        }
        else if(text == "3") {
            mp3.setVolume(30);
            mp3.play(); 
            Serial.println("Volume 100%");
        }
        else if(text == "all") {
            mp3.setLoopMode(MP3_LOOP_ALL);
            mp3.play();  
            Serial.println("play all");
            
        }

        else if(text == "one") {
            mp3.setLoopMode(MP3_LOOP_ONE_STOP);
            mp3.play(); 
            Serial.println("play one");
            
        }
        else if(text == "r") {
            mp3.setLoopMode(MP3_LOOP_ONE);
            mp3.play(); 
            Serial.println("play repeat");
            
        }

    
   }
}
