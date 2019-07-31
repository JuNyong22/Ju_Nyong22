void setup() {
    Serial.begin(9600);  //시리얼 모니터 사용하기
}

void loop() {
    Serial.println(millis());  //millis 시간을 시리얼 모니로 출력
    delay(1000);  //1초 주기
}
