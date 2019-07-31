//하드웨어의 아날로그를 이용하여 LED밝기 조절
void setup() {
}

void loop() {  //LED가 나중에 켜질수록 점점 밝아진다.
    analogWrite(3, 25);  //첫 번째 LED 밝기가 가장 낮다.
    analogWrite(9, 0);
    delay(200);

    analogWrite(5, 85);  //두 번째 LED 밝기가 두번째로 낮다.
    analogWrite(10, 0);
    delay(200);
    
    analogWrite(6, 145);  //세 번째 LED 밝기가 중간이다.
    analogWrite(3, 0);
    delay(200);
    
    analogWrite(9, 205);  //네 번째 LED 밝기가 두번째로 높다.
    analogWrite(5, 0);
    delay(200);
    
    analogWrite(10, 255);  //마지막 LED 밝기가 가장 밝다.
    analogWrite(6, 0);
    delay(200);
}
