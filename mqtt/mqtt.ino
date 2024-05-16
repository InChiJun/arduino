#include "WiFi.h"
#include "ArduinoMqttClient.h"

char ssid[] = "IOTA_24G";
char pass[] = "kosta90009";
char broker[] = "20.20.20.5"; // 10.10.10.5 => 127.0.0.1은 접속은  아두이노
int port = 1883;

char s_topic[]="sensor/";
char p_topic[]="sensor/1/data";



WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

void setup()
{
  Serial.begin(115200);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED)
  {
    Serial.print(".");
    delay(5000);
  }
  delay(1000);

  while (mqttClient.connect(broker, port) == 0)
  {
    Serial.println(mqttClient.connectError());

    WiFi.disconnect();
    while (WiFi.begin(ssid, pass) != WL_CONNECTED)
    {
      Serial.print(".");
      delay(5000);
    }
    delay(1000);
  }
  Serial.println("mqtt ok");

//sub
mqttClient.subscribe(s_topic);

}

void loop()
{
  int messageSize=mqttClient.parseMessage();
  if (messageSize)
  {
    Serial.println(mqttClient.messageTopic());
  }
  while (mqttClient.available())
  {
    Serial.println(mqttClient.readString());
  }
  
  
  //pub
  delay(3000);
  mqttClient.beginMessage(p_topic);
  mqttClient.println(random(1000));
  mqttClient.endMessage();
}