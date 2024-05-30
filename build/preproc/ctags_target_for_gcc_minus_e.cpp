# 1 "/home/pi/project/arduino/will/will.ino"
# 2 "/home/pi/project/arduino/will/will.ino" 2

void setup()
{
    pinMode(A3,OUTPUT);
    pinMode(A2,OUTPUT);
    digitalWrite(A3,HIGH);
    digitalWrite(A2,LOW);
    // Send the initialization sequence to the nunchuk.
    nunchuk.begin();
    _UART1_.begin(115200);
}

void loop()
{
    nunchuk.update();
    delay(500);

    // Nunchuk Joystick position:
    // nunchuk.x
    // nunchuk.y
    _UART1_.print("=========================\n");
    _UART1_.print("X: ");
    _UART1_.print(nunchuk.x);
    _UART1_.print("Y: ");
    _UART1_.print(nunchuk.y);
    // Nunchuk Acceleration:
    // nunchuk.ax
    // nunchuk.ay
    // nunchuk.az
    _UART1_.print("ax: ");
    _UART1_.print(nunchuk.ax);
    _UART1_.print("ay: ");
    _UART1_.print(nunchuk.ay);
    _UART1_.print("az: ");
    _UART1_.print(nunchuk.az);
    // Nunchuk Button states:
    // nunchuk.c
    // nunchuk.z
    _UART1_.print("c button: ");
    _UART1_.print(nunchuk.c);
    _UART1_.print("z button: ");
    _UART1_.println(nunchuk.z);
    _UART1_.print("=========================\n");
}
