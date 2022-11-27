const int Sensor = A0;
int Value = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Value =  analogRead(Sensor);
  Serial.print("Sensor =");
  Serial.print(Value);
  Serial.println();
  delay(500);
}
