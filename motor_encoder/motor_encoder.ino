int vitri=0;
void chay()
{
  if(digitalRead(4)==1)
    vitri--;  
  else
    vitri++;
}
void setup()
{
  attachInterrupt(0, chay, RISING);
  Serial.begin(9600);
}
void loop()
{
  Serial.println(vitri);
}