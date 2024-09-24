// arduino pin=2,3,4,5,6,7,8
  byte seven_seg_digits[16][7]=
  {
    {0,0,0,0,0,0,1}, //0
    {1,0,0,1,1,1,1}, //1
    {0,0,1,0,0,1,0}, //3
    {0,0,0,0,1,1,0}, //2
    {1,0,0,1,1,0,0}, //4
    {0,1,0,0,1,0,0}, //5
    {0,1,0,0,0,0,0}, //6
    {0,0,0,1,1,1,1}, //7
    {0,0,0,0,0,0,0}, //8
    {0,0,0,1,1,0,0}, //9
    {0,0,0,1,0,0,0}, //A
    {1,1,0,0,0,0,0}, //b
    {0,1,1,0,0,0,1}, //c
    {1,0,0,0,0,1,0}, //d
    {0,1,1,0,0,0,0}, //e
    {0,1,1,1,0,0,0}, //f
  };

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  writeDot(1);
  pinMode(A12,OUTPUT);
  digitalWrite(A12,LOW);
  pinMode(A13,OUTPUT);
  digitalWrite(A13,LOW);
  pinMode(A14,OUTPUT);
  digitalWrite(A14,LOW);
  pinMode(A15,OUTPUT);
  digitalWrite(A15,LOW);
  pinMode(30,OUTPUT);
  pinMode(31,OUTPUT);
  pinMode(32,OUTPUT);
  digitalWrite(32,LOW);
  digitalWrite(31,LOW);
  digitalWrite(30,LOW);
}

void writeDot(byte dot){
  digitalWrite(9,dot);  
}
void sevenSegWrite(byte digit){
  byte pin = 2;
  for(byte segCount=0;segCount<7;++segCount){
    digitalWrite(pin,seven_seg_digits[digit][segCount]);
    ++pin;
  }
}

void loop() {
  // put your main code here, to run repeatedly: 
  for(byte count = 0;count < 16;count++){
    delay(1000);
    sevenSegWrite(count);
  }
}
