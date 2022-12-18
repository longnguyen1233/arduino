/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  /*{'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}*/

  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
/*byte rowPins[ROWS] = {5, 4, 3, 2}; // (R1,R2,R3,R4)
byte colPins[COLS] = {6, 7, 8, 9}; // (C1,C2,C3,C4)*/

byte colPins[ROWS] = {6, 7, 8, 9}; // (R1,R2,R3,R4)
  byte rowPins[COLS] = {5, 4, 3, 2}; // (C1,C2,C3,C4)
/*
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
*/
//initialize an instance of class NewKeypad - Khởi tạo đối tượng customKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
  }
}
