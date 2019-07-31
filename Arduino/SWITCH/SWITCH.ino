//스위치를 사용해 보기
void setup() {
    Serial.begin(9600);
    pinMode(7, INPUT);
}

void loop() {
    int swValue;
    swValue = digitalRead(7);  //스위치 값 스위치 입력을 0으로 해놓았으니 스위치를 안누르면 1, 누르면 0이 출력된다.
    Serial.println(swValue);  //스위치 값 출력
}
