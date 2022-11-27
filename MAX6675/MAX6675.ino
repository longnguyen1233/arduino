/*    Max6675 Module  ==>   Arduino
 *    CS              ==>     D9
 *    SO              ==>     D8
 *    SCK             ==>     D10
 *    Vcc             ==>     Vcc (5v)
 *    Gnd             ==>     Gnd      */




#include <SPI.h>

#define MAX6675_CS   9
#define MAX6675_SO   8
#define MAX6675_SCK  10

void setup() {
 Serial.begin(9600);
}

void loop() {
  float temperature_read = readThermocouple(); 
  
  Serial.print("TEMPERATURE: ");
  Serial.print(temperature_read);
  Serial.println(" Do C");    
  delay(300);
}

double readThermocouple() {

  uint16_t v;
  pinMode(MAX6675_CS, OUTPUT);
  pinMode(MAX6675_SO, INPUT);
  pinMode(MAX6675_SCK, OUTPUT);
  
  digitalWrite(MAX6675_CS, LOW);
  delay(1);

  // Read in 16 bits,
  //  15    = 0 always
  //  14..2 = 0.25 degree counts MSB First
  //  2     = 1 if thermocouple is open circuit  
  //  1..0  = uninteresting status
  
  v = shiftIn(MAX6675_SO, MAX6675_SCK, MSBFIRST);
  v <<= 8;
  v |= shiftIn(MAX6675_SO, MAX6675_SCK, MSBFIRST);
  
  digitalWrite(MAX6675_CS, HIGH);
  if (v & 0x4) 
  {    
    // Bit 2 indicates if the thermocouple is disconnected
    return NAN;     
  }
  // The lower three bits (0,1,2) are discarded status bits
  v >>= 3;
  // The remaining bits are the number of 0.25 degree (C) counts
  return v*0.25;
}