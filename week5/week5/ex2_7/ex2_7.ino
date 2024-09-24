int BASE = 6;
int NUM = 4;
int BASE1 = 37;
int DIPSW1state;
int DIPSW2state;
int DIPSW3state;
int DIPSW4state;


void setup() {
  // put your setup code here, to run once:
  for(int i=BASE;i<BASE+NUM;i++){
    pinMode(i,OUTPUT);
  }
  for(int i=BASE1;i<BASE1+NUM;i++){
    pinMode(i,INPUT_PULLUP);
  }  
  pinMode(A15,OUTPUT);
  digitalWrite(A15,LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  DIPSW1state = digitalRead(37);
  digitalWrite(6,DIPSW1state);
  Serial.println(DIPSW1state);
  DIPSW2state = digitalRead(38);
  digitalWrite(7,DIPSW2state);
  
  DIPSW3state = digitalRead(39);
  digitalWrite(8,DIPSW3state);
  
  DIPSW4state = digitalRead(40);
  digitalWrite(9,DIPSW4state);
}
