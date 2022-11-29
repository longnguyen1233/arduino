int in1=6;
int in2=7;
int vitri=0;
int tt1,tt2;
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

  attachInterrupt(0, chay, RISING);
  Serial.begin(9600);

  digitalWrite (in1, HIGH);
  digitalWrite (in2, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  tt1 = digitalRead(in1);
  tt2 = digitalRead(in2);
  if(abs(vitri)>5000 )
  {

    digitalWrite (in2, LOW);
    digitalWrite (in1, LOW );
    delay(2000);
    digitalWrite (in2, !tt2);
    digitalWrite (in1, !tt1 );
    vitri=0;
    
  }
  
  Serial.print(tt1);
  Serial.print(tt2);
  Serial.print("       ");
  Serial.println(vitri);
}
