const byte LED[] = {13, 12, 11, 10};

void setup(){
    pinMode(LED[0], OUTPUT);
    pinMode(LED[1], OUTPUT);
    pinMode(LED[2], OUTPUT);
    pinMode(LED[3], OUTPUT);
}

void loop(){
    byte Index;

    // 정방향 LED ON
    for(Index = 0; Index < 4; Index++){
        digitalWrite(LED[0], HIGH);
        digitalWrite(LED[1], HIGH);
        digitalWrite(LED[2], HIGH);
        digitalWrite(LED[3], HIGH);

        digitalWrite(LED[Index], LOW);
        delay(100);
    }

    // 역방향 LED ON
    for(Index = 3; Index > 0; Index--){
        digitalWrite(LED[0], HIGH);
        digitalWrite(LED[1], HIGH);
        digitalWrite(LED[2], HIGH);
        digitalWrite(LED[3], HIGH);

        digitalWrite(LED[Index], LOW);
        delay(100);
    }
}