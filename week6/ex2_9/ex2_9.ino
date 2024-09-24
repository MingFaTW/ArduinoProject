#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
                              {'F','E','D','C'},
                              {'B','3','6','9'},
                              {'A','2','5','8'},                                                
                              {'0','1','4','7'}};
byte rowPins[ROWS]={25,24,23,22};
byte colPins[ROWS]={29,28,27,26};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys),rowPins,colPins,ROWS,COLS);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  char customKey = customKeypad.getKey();
  if(customKey){
    Serial.println(customKey);
  }
}
