#define SIGNAL_PIN 2
int loa = 11;
void setup()
{
  Serial.begin(9600);
  pinMode(SIGNAL_PIN, INPUT);
  pinMode(loa, OUTPUT);
}

void loop() {
  if(digitalRead(SIGNAL_PIN)==HIGH) {
    digitalWrite(loa, HIGH);
    Serial.println("Movement detected.");
  } else {
    Serial.println("Did not detect movement.");
    digitalWrite(loa, LOW);
  }
  delay(100);
}