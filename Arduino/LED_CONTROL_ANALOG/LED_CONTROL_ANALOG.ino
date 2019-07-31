//하드웨어의 아날로그를 이용하여 LED밝기 조절
void setup() {
    Serial.begin(9600);
}

void loop() {
    for(int i = 0; i <= 255; i++) {  //LED 밝기 올리기
        analogWrite(3, i);
        Serial.println(i);
        delay(1);
    }
    for(int i = 255; i >= 0; i--) {  //LED 밝기 내리기
        analogWrite(3, i);
        Serial.println(i);
        delay(1);
    }
}
