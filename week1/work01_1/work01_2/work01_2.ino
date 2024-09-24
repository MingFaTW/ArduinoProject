const int led[] = {2,3,4,5,6,7,8,9};
const int led1[] = {9,8,7,6,5,4,3,2};
int i,i1;
int j,j1=0;
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
    digitalWrite(led[i],HIGH);
    }
    digitalWrite(led[j],LOW);
    digitalWrite(led[j+1],LOW);
    digitalWrite(led[j+2],LOW);
    delay(500);
    j++;
    if(j==6){
      while(j!=0){
        --j;
        for(int i=0;i<8;i++){
          digitalWrite(led[i],HIGH);
        }
        digitalWrite(led[j],LOW);
        digitalWrite(led[j+1],LOW);
        digitalWrite(led[j+2],LOW);
        delay(500);
      }
    }
}
