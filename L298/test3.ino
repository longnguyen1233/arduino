int ena = 5;
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int enb = 10;

void setup() 

{
  pinMode (ena, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enb, OUTPUT);

}

void motor1_chay ()
{ 
  analogWrite (ena, 150);
  digitalWrite (in1, HIGH); 
  digitalWrite (in2, LOW); 
}

void motor1_dung()
{ 
  digitalWrite (in1, LOW); 
  digitalWrite (in2, LOW);  
}


void motor2_chay ()
{ 
  analogWrite (enb, 150);
  digitalWrite (in3, HIGH); 
  digitalWrite (in4, LOW); 
}

void motor2_dung ()
{ 
  digitalWrite (in3, LOW); 
  digitalWrite (in4, LOW); 
}

void loop() 

{
  motor1_chay ();
  motor2_chay ();
  delay (2000);

  motor1_dung ();
  motor2_dung ();
  delay (3000);

}
