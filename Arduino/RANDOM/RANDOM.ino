//랜덤함수를 직접적으로 짤 수 없어서 CNT를 빠르게 센 후에 버튼을 누르면 CNT값을 출력하기로 대체하였습니다.
#define SW_PIN 8
unsigned int Cnt = 1;  //랜덤값
unsigned char OldSw, NewSw = 0;

void setup() {
    Serial.begin(9600);
    pinMode(SW_PIN, INPUT_PULLUP);
}

void loop() {
    NewSw = digitalRead(SW_PIN);

    if(OldSw != NewSw) {
        OldSw = NewSw;
        if(NewSw == 0) {
            Serial.println(Cnt);  //CNT값 출력
        }
        delay(1000);
    }

    Cnt++;
    if(Cnt >= 23) Cnt = 1;  //범위가 넘어서면 다시 CNT를 1로 초기화
}
