#include <TinyNunchuk.h>

void setup()
{
    pinMode(A3,OUTPUT);
    pinMode(A2,OUTPUT);
    digitalWrite(A3,HIGH);
    digitalWrite(A2,LOW);
    // Send the initialization sequence to the nunchuk.
    nunchuk.begin();
    Serial.begin(115200);
}

void loop()
{
    nunchuk.update();
    delay(500);

    // Nunchuk Joystick position:
    // nunchuk.x
    // nunchuk.y
    Serial.print("=========================\n");
    Serial.print("X: ");
    Serial.print(nunchuk.x);
    Serial.print("Y: ");
    Serial.print(nunchuk.y);
    // Nunchuk Acceleration:
    // nunchuk.ax
    // nunchuk.ay
    // nunchuk.az
    Serial.print("ax: ");
    Serial.print(nunchuk.ax);
    Serial.print("ay: ");
    Serial.print(nunchuk.ay);
    Serial.print("az: ");
    Serial.print(nunchuk.az);
    // Nunchuk Button states:
    // nunchuk.c
    // nunchuk.z
    Serial.print("c button: ");
    Serial.print(nunchuk.c);
    Serial.print("z button: ");
    Serial.println(nunchuk.z);
    Serial.print("=========================\n");
}