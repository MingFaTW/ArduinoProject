#define CA1 30
#define CA2 31
#define CA3 32

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
  for(unsigned int number = 0;number<1000;number++){
    unsigned long startTime = millis();
    for(unsigned long elapsed = 0;elapsed<300;elapsed = millis() - startTime){
      pickDigit(1);
      pickNumber(number%10);
      delay(delay_time);
      pickDigit(2);
      pickNumber((number/10)%10);
      delay(delay_time);  
      pickDigit(3);
      pickNumber((number/100)%10);
      delay(delay_time);  
      pickDigit(4);
      pickNumber((number/1000)%10);
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
      digitalWrite(CA3,LOW);
      break;
    case 2:
      digitalWrite(CA1,HIGH);
      digitalWrite(CA2,LOW);
      digitalWrite(CA3,LOW);
      break;
    case 3:
      digitalWrite(CA1,LOW);
      digitalWrite(CA2,HIGH);
      digitalWrite(CA3,LOW);
      break;
    case 4:
      digitalWrite(CA1,HIGH);
      digitalWrite(CA2,HIGH);
      digitalWrite(CA3,LOW);
      break;
  }
}

void pickNumber(int x){
  switch(x){
    case 1:
      one();break;
    case 2:
      two();break;
    case 3:
      three();break;
    case 4:
      four();break;
    case 5:
      five();break;
    case 6:
      six();break;
    case 7:
      seven();break;
    case 8:
      eight();break;
    case 9:
      nine();break;
    default:
      zero();break;
  }
}

void zero(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
}

void one(){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}
void two(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
}

void three(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
}
void four(){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
void five(){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
void six(){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
void seven(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}
void eight(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}
void nine(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}

