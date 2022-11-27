int ena = 5;
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int enb = 10;

int i;

void setup() 
{
  Serial. begin (9600);
  
  pinMode (ena, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enb, OUTPUT);

}

void motor1_dung()
{ 
  digitalWrite (in1, LOW); 
  digitalWrite (in2, LOW);  
}
void motor2_dung ()
{ 
  digitalWrite (in3, LOW); 
  digitalWrite (in4, LOW); 
}

void tangtoc ()
{
  
  for (i=0; i<256; i++)
  {
     analogWrite (ena, i);
     digitalWrite (in1, HIGH); 
     digitalWrite (in2, LOW);
     analogWrite (enb, i);
     digitalWrite (in3, LOW); 
     digitalWrite (in4, HIGH);
     Serial.  println (i);
     delay (50);
  }
}

void giamtoc ()
{
  
  for (i=255; i>0; i--)
  {
     analogWrite (ena, i);
     digitalWrite (in1, HIGH); 
     digitalWrite (in2, LOW);
     analogWrite (enb, i);
     digitalWrite (in3, LOW); 
     digitalWrite (in4, HIGH);
     Serial.  println (i);
     delay (50);
  }
}

void loop() 
{
  tangtoc ();
  Serial. println ("Chạy 10 giây");
  delay (10000);
  
  giamtoc ();
  Serial. println ("Dừng 5 giây");
  delay (5000);

}
