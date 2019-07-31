//함수를 사용하여 스위치로 LED제어하기
void setup() {
    Serial.begin(9600);
    pinMode (8, INPUT_PULLUP);  //스위치
    pinMode(6, OUTPUT);  //LED
}

void loop() {
    ShPush(8);  //함수 사용
}

//ShPush라는 함수
void ShPush(unsigned char pinNumber) {
    static unsigned char OldSw = 0, NewSw = 0;
    static unsigned char LedState = 0;
    static unsigned long NowTime = 0, ClickTime = 0;
    static unsigned int ClickCnt = 0;

    NewSw = digitalRead(pinNumber);  //스위치 입력 받기
    NowTime = millis();

    if(NowTime - ClickTime >= 40) {  //채터링 방지
        if(OldSw != NewSw) {
            OldSw = NewSw;
            if(NewSw == 0) {
                LedState = !LedState;  /LedState를 반전 == 스위치를 누를 때마다 LED 반전
                Serial.println("Click");  //스위치를 누를 때마다 Click를 시리얼 모니터에 출력
                digitalWrite(6, LedState);  //LED 출력
            }
        }
    }
    delay(40);
}
