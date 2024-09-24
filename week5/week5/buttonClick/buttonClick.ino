int pushButton = 33;
int buttonState = 0;
int beforeState = 0;
int pressTime = 1;

void setup(){
    Serial.begin(9600);
    Serial.println(buttonState);
    pinMode(pushButton,INPUT_PULLUP);
}

void loop(){
    buttonState = digitalRead(pushButton);
    if(buttonState==1 and beforeState==0){
        Serial.print("Hi~~");
        Serial.println(buttonState);
        pressTime = pressTime + 1;
    }
    beforeState = buttonState;
    delay(1);
}
