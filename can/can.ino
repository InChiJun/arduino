#include <Arduino_CAN.h>
#include <Arduino.h>

static uint32_t const CANID = 0x00;  

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
        char send[8];
        for(int i=0; i<8; i++)send[i]=msg.data[i]; 
        
        Serial.println(send);
    }

    if (Serial.available())
    {
        uint8_t msg_data[8];
        int msg_length = Serial.readBytesUntil('\n', msg_data, sizeof(msg_data));
        if (msg_length > 0)
        {
            CanMsg msg(CanStandardId(CANID), msg_length, msg_data);
            CAN.write(msg);
        }
    }
}
