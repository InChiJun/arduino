#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;
void setup(){
    Serial.begin(115200);
    if(aht.begin()){
        Serial.println("OK");
    } else{
        Serial.println("NG");
    }
}

void loop(){
    sensors_event_t huminity, temp;

    aht.getEvent(&huminity, &temp);
    Serial.print(huminity.relative_humidity);
    Serial.print("   ");
    Serial.println(temp.temperature);

    delay(1000);
}