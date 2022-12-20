int in1=6;
int in2=7;
String text;
float vitri;// xung /s
float rpm; //tốc độ động cơ
float N; //xung/vòng

int tt;// trạng thái chạy
unsigned long previousMillis;

void chay()
{
  if(digitalRead(4)==1)
    vitri--;
  else
    vitri++;
}
void setup() {
  // put your setup code here, to run once:
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  tt=0;
  attachInterrupt(0, chay, RISING);
  Serial.begin(9600);
  digitalWrite (in1, LOW);
  digitalWrite (in2, HIGH );
  previousMillis = millis();
  Serial.println("Chon so vong:");
  Serial.println("1: 280 rmp");
  Serial.println("2: 620 rmp");
}

void loop() {
  // put your main code here, to run repeatedly:
 if (millis() - previousMillis >= 1000)
  {
    N=((vitri/(rpm))*60);
    digitalWrite (in1, LOW);
    digitalWrite (in2, LOW );
  }
  else
    previousMillis=millis();
  if(rpm==280 || rpm==620)
  {
    Serial.print("So xung tren vong: "); 
    Serial.print(N);
    Serial.print("\t");
    Serial.print("Ty so truyen: ");
    Serial.println(N/11);
    rpm=1;
  }
  
//  if (vitri>=202)
//  {
//     digitalWrite (in1, LOW);
//     digitalWrite (in2, LOW );
//  }
  if(Serial.available())
  {
    text = Serial.readStringUntil('\n');
    if(text == "1")
    {
      rpm=280.00;
  
    }
    if(text == "2")
    {
      rpm=620.00;
     
    }
  }
  
}