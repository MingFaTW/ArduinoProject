#define CA1 30
#define CA2 31
#define CA3 32

byte segs[7]={2,3,4,5,6,7,8};
byte seven_seg_digits[10][7]=
{
  {0,0,0,0,0,0,1},
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
  {0,1,0,0,0,0,0},
  {0,0,0,1,1,1,1},
  {0,0,0,0,0,0,0},
  {0,0,0,1,1,0,0},
};

int delay_time = 4;


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
  digitalWrite(9,HIGH);
  
  pinMode(CA1,OUTPUT);
  pinMode(CA2,OUTPUT);
  pinMode(CA3,OUTPUT);
  pinMode(A13,OUTPUT);
  digitalWrite(A13,LOW);
}

void loop() {
  // put your main code here, to run repeatedly: 
  for(unsigned int number = 0;number < 360001; number++){
      unsigned long startTime = millis();
    for(unsigned long elapsed = 0;elapsed < 300;elapsed = millis()-startTime){
       lightDigit1(number%10);
       delay(delay_time);
       lightDigit2((number%60)/10);
       delay(delay_time);
       lightDigit3((number/60)%10);
       delay(delay_time);
       lightDigit4((number/60)/10%10);
       delay(delay_time);
    }
  }
}

void pickDigit(int x){
  digitalWrite(CA1,HIGH);
  digitalWrite(CA2,HIGH);
  digitalWrite(CA3,HIGH);
  switch(x){
    case 1:
      digitalWrite(CA1,LOW);
      digitalWrite(CA2,LOW);
      digitalWrite(CA3,LOW); break;
    case 2:
      digitalWrite(CA1,HIGH);
      digitalWrite(CA2,LOW);
      digitalWrite(CA3,LOW); break;
    case 3:
      digitalWrite(CA1,LOW);
      digitalWrite(CA2,HIGH);
      digitalWrite(CA3,LOW); break;
    case 4:
      digitalWrite(CA1,HIGH);
      digitalWrite(CA2,HIGH);
      digitalWrite(CA3,LOW); break;
  }
}

void lightDigit1(byte number){
  pickDigit(1);
  lightSegments(number);
}

void lightDigit2(byte number){
  pickDigit(2);
  lightSegments(number);
}

void lightDigit3(byte number){
  pickDigit(3);
  lightSegments(number);
}

void lightDigit4(byte number){
  pickDigit(4);
  lightSegments(number);
}

void lightSegments(byte number){
  for(int i=0;i<7;i++){
    digitalWrite(segs[i],seven_seg_digits[number][i]);
  }
}
