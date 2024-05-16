int buttonpin = 10;                // Data Pin 3을 Key Switch interface 제어 핀으로 정의
int val;                          // numeric variables val

void setup()
{
  val digitalRead(buttonpin);

  if()

  pinMode(buttonpin,INPUT);  // Key Switch interface 제어 핀(GPIO Pin 3)을 입력으로 설정
  Serial.begin(115200);
}

void loop()
{
  val = digitalRead(buttonpin);   // Key Switch interface에서 값을 읽음 (GPIO State)
  if(val==LOW)                   // 푸시 스위치가 눌러졌다면
  {
    Serial.println("On");        
  }
  else
  {
    Serial.println("Off");       
  }
}
