int Pin = A6;
int Value = 0;
int ledPin = 4;
int DIPSW1state;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(37,INPUT_PULLUP);
  //pinMode(ledPin,OUTPUT);
  pinMode(A15,OUTPUT);
  digitalWrite(A15,LOW);
}

void loop() {
  // put your main code here, to run repeatedly: 
  DIPSW1state = digitalRead(37);
  
  if(DIPSW1state==0){
    Value = analogRead(Pin);
    Serial.print("Value = ");
    Serial.println(Value);
    if(Value>1000){
      analogWrite(ledPin,Value);
    }else{
      digitalWrite(ledPin,HIGH);
    }
    delay(1000);
  }else{
    digitalWrite(ledPin,HIGH);
  }
}
