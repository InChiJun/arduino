// 한글이 깨져서 출력된다. 이유 모르겠음. 라이브러리 자체 문제로 보임

#include<LiquidCrystal_I2C_Hangul.h>
#include<Wire.h>

LiquidCrystal_I2C_Hangul lcd(0x27,16,2); //LCD 클래스 초기화

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
}

void loop() {
    lcd.printHangul(L"Hi",0,2); //lcd.printHangul(한글 문장, 시작 포인트, 문장 길이);
}