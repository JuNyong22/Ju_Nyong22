//조도센서(CDS)를 사용하여 밝기에 따른 값 확인
void setup() {
    Serial.begin(9600);
}

void loop() {
    unsigned int Val = analogRead(A0);
    Serial.println(Val);  //시리얼 모니터에 값을 *** 형식으로 출력
}
}
