#include <Arduino.h>
#line 1 "/home/pi/project/arduino/temperature/temperature.ino"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>

#define RX_PIN 10
#define TX_PIN 11

SoftwareSerial mySerial(RX_PIN, TX_PIN);
int ONE_WIRE_BUS = 2;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

#line 14 "/home/pi/project/arduino/temperature/temperature.ino"
void setup(void);
#line 20 "/home/pi/project/arduino/temperature/temperature.ino"
void loop(void);
#line 14 "/home/pi/project/arduino/temperature/temperature.ino"
void setup(void){
  Serial.begin(115200);

  mySerial.begin(9600);
}

void loop(void){
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
  
  Serial.println(temperature);
  mySerial.print(temperature);
  mySerial.write('\n');
  delay(1000);
}
