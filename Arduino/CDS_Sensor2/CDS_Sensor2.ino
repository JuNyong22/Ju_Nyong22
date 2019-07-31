//조도센서(CDS)를 사용하여 밝기에 따른 값 확인
void setup() {
    Serial.begin(9600);  //시리얼 모니터를 활용
}

void loop() {
    unsigned int Val = analogRead(A0);

    float Voltage = (float)map(Val, 0, 1024, 0, 100);
    Serial.println(Voltage / 100);  //시리얼 모니터에 값을 0.** 형식으로 출력
}
