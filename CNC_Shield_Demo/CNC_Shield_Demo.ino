
// CNC Shield Stepper  Control Demo
// Superb Tech
// www.youtube.com/superbtech

// const int StepX = 5;
// const int DirX = 2;
// const int StepY = 6;
// const int DirY = 3;
// const int StepZ = 7;
// const int DirZ = 4;
// const int en = 8;

const int StepX = 2;
const int DirX = 5;
const int StepY = 3;
const int DirY = 6;
const int StepZ = 4;
const int DirZ = 7;


void setup() {
  pinMode(StepX,OUTPUT);
  pinMode(DirX,OUTPUT);
  pinMode(StepY,OUTPUT);
  pinMode(DirY,OUTPUT);
  pinMode(StepZ,OUTPUT);
  pinMode( DirZ,OUTPUT);
 // pinMode( en,OUTPUT);
  //digitalWrite(en, LOW);
}

void loop() {
 digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
 digitalWrite(DirY, HIGH);
 digitalWrite(DirZ, HIGH);
 
 for(int x = 0; x < 400; x++)
  {
    digitalWrite(StepX,HIGH); // Cạnh lên
    delayMicroseconds(1000); //Thời gian xuất xung = tốc độ quay | 400
    digitalWrite(StepX,LOW); // Cạnh xuống
    delayMicroseconds(1000);
  }
  delay(1000);
   for(int x = 0; x < 400; x++)
  {
    digitalWrite(StepY,HIGH); // Cạnh lên
    delayMicroseconds(1000); //Thời gian xuất xung = tốc độ quay | 400
    digitalWrite(StepY,LOW); // Cạnh xuống
    delayMicroseconds(1000);
  }
  delay(1000);
   for(int x = 0; x < 400; x++)
  {
    digitalWrite(StepZ,HIGH); // Cạnh lên
    delayMicroseconds(1000); //Thời gian xuất xung = tốc độ quay | 400
    digitalWrite(StepZ,LOW); // Cạnh xuống
    delayMicroseconds(1000);
  }
  delay(1000);

  
}
