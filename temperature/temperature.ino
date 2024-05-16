#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>

#define RX_PIN 10
#define TX_PIN 11

SoftwareSerial mySerial(RX_PIN, TX_PIN);
int ONE_WIRE_BUS = 2;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

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