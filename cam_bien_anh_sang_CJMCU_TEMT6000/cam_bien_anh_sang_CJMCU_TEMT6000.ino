int temt6000Pin = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float value = analogRead(temt6000Pin);
  Serial.println((value/1023)*25); 
  delay(200);
}