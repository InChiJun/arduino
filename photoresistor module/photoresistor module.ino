int sensorPin = A10; //define analog pin A2
int value = 0; 

void setup() {
	pinMode(A10, INPUT);
	Serial.begin(115200); 
} 

void loop() {
	value = analogRead(sensorPin); 
	Serial.println(value, DEC); // light intensity
								// high values for bright environment
								// low values for dark environment
	delay(100); 
}