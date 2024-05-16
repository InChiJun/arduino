# 1 "/home/pi/project/arduino/temperature/temperature.ino"
# 2 "/home/pi/project/arduino/temperature/temperature.ino" 2
# 3 "/home/pi/project/arduino/temperature/temperature.ino" 2
# 4 "/home/pi/project/arduino/temperature/temperature.ino" 2

#define RX_PIN 10
#define TX_PIN 11

SoftwareSerial mySerial(10, 11);
int ONE_WIRE_BUS = 2;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void){
  _UART1_.begin(115200);

  mySerial.begin(9600);
}

void loop(void){
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);

  _UART1_.println(temperature);
  mySerial.print(temperature);
  mySerial.write('\n');
  delay(1000);
}
