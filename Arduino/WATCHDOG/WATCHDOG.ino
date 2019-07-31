#include <avr/wdt.h>

void setup() {
    wdt_enable(WDTO_2S);  //와치독 2초 설정
    Serial.begin(9600);
    Serial.println("Start");
}

void loop() {
    Serial.println("doing");  //시리얼 출력
    delay(2500);  //2.5초
    wdt_reset();
}
