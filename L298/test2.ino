int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;

void setup() 
{
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);

}

void motor1_chay ()
{ digitalWrite (in1, HIGH); digitalWrite (in2, LOW); }

void motor1_dung()
{ digitalWrite (in1, LOW); digitalWrite (in2, LOW);  }


void motor2_chay ()
{ digitalWrite (in3, LOW); digitalWrite (in4, HIGH); }

void motor2_dung ()
{ digitalWrite (in3, LOW); digitalWrite (in4, LOW); }


void loop() 
{
  motor1_chay (); 
  motor2_chay ();
  delay (1000);

  
  motor1_dung (); 
  motor2_dung ();
  delay (5000);

}
