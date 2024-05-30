#include <TinyNunchuk.h>

void setup()
{
    // pinMode(A3,OUTPUT);
    // pinMode(A2,OUTPUT);
    // digitalWrite(A3,HIGH);
    // digitalWrite(A2,LOW);
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
    Serial.println("=========================");
    Serial.print("X: ");
    Serial.println(nunchuk.x);
    Serial.print("Y: ");
    Serial.println(nunchuk.y);
    // Nunchuk Acceleration:
    // nunchuk.ax
    // nunchuk.ay
    // nunchuk.az
    Serial.print("ax: ");
    Serial.println(nunchuk.ax);
    Serial.print("ay: ");
    Serial.println(nunchuk.ay);
    Serial.print("az: ");
    Serial.println(nunchuk.az);
    // Nunchuk Button states:
    // nunchuk.c
    // nunchuk.z
    Serial.print("c button: ");
    Serial.println(nunchuk.c);
    Serial.print("z button: ");
    Serial.println(nunchuk.z);
}