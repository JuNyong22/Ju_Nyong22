//PORT를 사용하여 LED 켜보기
void setup() {
    DDRC = 0xFF;
}

void loop() {  //LED를 아주 적은 시간만 키도록 하였다.
    PORTC = 0xFF;
    delay(1);
    PORTC = ~PORTC;
    delay(1000);
}
