const int led[] = {2,3,4,5,6,7,8,9};
int i;
int j=0;
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<8;i++){
    pinMode(led[i],OUTPUT);
    pinMode(A15,OUTPUT);
    digitalWrite(A15,LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly: 
  for(int i=0;i<8;i++){
    digitalWrite(i,HIGH);
    digitalWrite(led[i],LOW);
    delay(500);
    j++;
    if(j==8)
      j=0;
  }
}
