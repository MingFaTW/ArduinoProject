#define A 0
#define B 1
#define A_BAR 2
#define B_BAR 3
#define tt 20
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
  for(j=0;j<=3;j++)
    digitalWrite(run2_F[i][j],HIGH);
  delay(tt);
  }
}
