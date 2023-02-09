#include<SoftwareSerial.h>
SoftwareSerial sim(10,11);

int led = 4;
String val;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  sim.begin(9600);
  delay(100);
  sim.println("AT");
  sim.println("AT+CMGF=1");
  sim.println("AT+CNMI=1,2,0,0,0");
}

void loop() {
  if(Serial.available()){
    sim.write(Serial.read());
  }
  if(sim.available()>0){
    val = sim.readStringUntil('\n');
    Serial.println(val);
    if(val=="On\r"){
      digitalWrite(led,HIGH);
      phanhoi(1);
      Serial.println("LED ON");
    }
    if(val=="Off\r"){
      digitalWrite(led,LOW);
      phanhoi(0);
      Serial.println("LED OFF");
    }
  }

}

void phanhoi(bool tipe){
  sim.println("AT+CMGF=1");
  delay(1000);
  sim.println("AT+CMGS=\"0377107817\"\r");
  delay(1000);
  if(tipe==1){
    sim.println("LED ON");
  }else{
    sim.println("LED OFF");
  }
  delay(100);
  sim.println((char)26);
  delay(1000);
}
