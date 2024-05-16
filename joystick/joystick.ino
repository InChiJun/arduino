int const LEFT_BTN = 2;
int const UP_BTN = 3;
int const RIGHT_BTN = 4;
int const DOWN_BTN = 5;
int const E_BTN = 6;
int const F_BTN = 7;
int const JOYSTICK_BTN = 8;
int const JOYSTICK_AXIS_X = A0;
int const JOYSTICK_AXIS_Y = A1;
int buttons[] = {LEFT_BTN, UP_BTN, RIGHT_BTN, DOWN_BTN, E_BTN, F_BTN, JOYSTICK_BTN};

void setup() {
  //Set all button pins as inputs with internal pullup resistors enabled.
  // for (int i=0; i < 7; i++)  pinMode(buttons[i], INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  // Check each button input and print the status to the Serial Monitor Window
  Serial.print("UP = "),Serial.print(digitalRead(UP_BTN)),Serial.print(" || ");
  Serial.print("DOWN = "),Serial.print(digitalRead(DOWN_BTN)),Serial.print(" || ");
  Serial.print("LEFT = "),Serial.print(digitalRead(LEFT_BTN)),Serial.print(" || ");
  Serial.print("RIGHT = "),Serial.print(digitalRead(RIGHT_BTN)),Serial.print(" || ");
  Serial.print("E = "),Serial.print(digitalRead(E_BTN)),Serial.print(" || ");
  Serial.print("F = "),Serial.print(digitalRead(F_BTN)),Serial.print(" || ");
  Serial.print("JOYSTICK BTN = "),Serial.print(digitalRead(JOYSTICK_BTN)),Serial.print(" || ");
  // Map the X/Y joystick to basic -1/0/1 to indicate basic direction of the joystick
  Serial.print("X DIR = "),Serial.print(map(analogRead(JOYSTICK_AXIS_X), 0, 1023, -1, 1));Serial.print(" || ");
  Serial.print("Y DIR = "),Serial.print(map(analogRead(JOYSTICK_AXIS_Y), 0, 1023, -1, 1));Serial.print(" || ");  
  // Print the full X/Y joystick values (0-1023)
  Serial.print("X = "),Serial.print(analogRead(JOYSTICK_AXIS_X));Serial.print(" || ");
  Serial.print("Y = "),Serial.print(analogRead(JOYSTICK_AXIS_Y));Serial.println(" || ");  
  delay(100);
  
 }