#define row_size 8
#define col_size 8
#define delay_time 300
const byte ROWS = 4;
const byte COLS = 4;

int joyPinX=A1;
int joyPinY=A2;
int SW=A3;
int value = 0;
int xzero = 0;
int yzero = 0;
int SWstate = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SW,INPUT_PULLUP);
  yzero = analogRead(joyPinY);
  xzero = analogRead(joyPinX);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int x,y,value;
  value = analogRead(joyPinX);
  x = value-xzero;
  value = analogRead(joyPinY);
  y = value-yzero;
  SWstate = digitalRead(SW);
  SWstate = digitalRead(SW);
  Serial.print("X = ");
  Serial.print(x);
  Serial.print("  Y = ");
  Serial.print(y);
  Serial.print("SW = ");
  Serial.println(SWstate);
  delay(20);
}
