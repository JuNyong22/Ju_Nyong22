//조도센서(CDS)를 사용하여 밝기에 따른 값 확인
void setup() {
    Serial.begin(9600);
}

void loop() {
    unsigned int Val = analogRead(A0);
    Serial.println(Val * 0.0048828125);  //시리얼 모니터로 볼트 값 측정, 아누이노는 5V까지 공금
}
