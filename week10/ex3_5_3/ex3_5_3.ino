#define A 2
#define B 3
#define A_BAR 4
#define B_BAR 5
#define tt 20
unsigned run1_F[4] = {A,B,A_BAR,B_BAR};
unsigned run2_F[4][2] = {{A,B},{B,A_BAR},{A_BAR,B_BAR},{B_BAR,A}};

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
  // put your main code here, to run repeatedly: 
  int i,j;
  for(i=0;i<=3;i++){
    stop1();
    digitalWrite(run1_F[i],HIGH);
    delay(tt);
    stop1();
    for(j=0;j<=1;j++)
      digitalWrite(run2_F[i][j],HIGH);
    delay(tt);
  }
}
