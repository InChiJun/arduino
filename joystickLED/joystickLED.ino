int const BREAK_BTN = 2;
int const UP_BTN = 3;
int const EXCEL_BTN = 4;
int const DOWN_BTN = 5;
int const E_BTN = 6;
int const F_BTN = 7;
int const JOYSTICK_BTN = 8;
int const JOYSTICK_AXIS_X = A0;
int const JOYSTICK_AXIS_Y = A1;
int buttons[] = {BREAK_BTN, UP_BTN, EXCEL_BTN, DOWN_BTN, E_BTN, F_BTN, JOYSTICK_BTN};
int const RED = 12;
int const GREEN = 13;

void setup() {
  //Set all button pins as inputs with internal pullup resistors enabled.
  for (int i=0; i < 7; i++)  pinMode(buttons[i], INPUT_PULLUP);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if(digitalRead(BREAK_BTN) == LOW){
    digitalWrite(RED, HIGH);
  } else{
    digitalWrite(RED, LOW);
  }
  if(digitalRead(EXCEL_BTN) == LOW){
    digitalWrite(GREEN, HIGH);
  } else{
    digitalWrite(GREEN, LOW);
  }
  delay(1000);
  
 }