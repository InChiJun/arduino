#include <Arduino_CAN.h>
static uint32_t const CAN_ID = 0x20;

void setup()
{
    Serial.begin(115200);
    CAN.begin(CanBitRate::BR_500k);
}

void loop()
{
    if (CAN.available())
    {
        CanMsg msg = CAN.read();
        Serial.println(msg);
    }

    uint8_t msg_data[]={0xCA, 0xFE,0,0,0,0,0,0};
    CanMsg sendMsg(CanStandardId(CAN_ID),sizeof(msg_data), msg_data);

    CAN.write(sendMsg);
    Serial.println();

    delay(1000);
}
