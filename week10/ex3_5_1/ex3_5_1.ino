#define A 0  
#define B 1
#define A_BAR 2
#define B_BAR 3
#define tt 20
unsigned run1_F[4] = {A,B,A_BAR,B_BAR};

void stop1(){
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(A_BAR,LOW);
  digitalWrite(B_BAR,LOW);
}

void setup() {
  // put your setup code here, to run once:
  int i;
  for(i=0;i<=3;i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  int i;
  for(i=0;i<=3;i++){
    stop1();
    digitalWrite(run1_F[i],HIGH);
    delay(tt);
  }
  // put your main code here, to run repeatedly: 
}
