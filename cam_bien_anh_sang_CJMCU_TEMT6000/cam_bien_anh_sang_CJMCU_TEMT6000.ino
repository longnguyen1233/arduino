int temt6000Pin = A1;

void setup() {
  Serial.begin(9600);
  pinMode(temt6000Pin,INPUT);
}

void loop() {
  float value = analogRead(temt6000Pin);
  Serial.println(value); 
  
}