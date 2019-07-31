////랜덤함수를 직접적으로 짤 수 없어서 CNT를 빠르게 센 후에 버튼을 누르면 CNT값을 출력하기로 대체하였습니다.
unsigned char Flag = 1;

void setup() {
    Serial.begin(9600);
    pinMode(8, INPUT);
}

void loop() {
    for(int i = 1; i <= 23; i++) {
        if(digitalRead(8)) {
            if(Flag) {
                Flag = 0;
                Serial.println(i);
            }
            delay(100);
        }
        else Flag = 1;
    }
}
