//millis를 사용하여 LED를 1초 주기로 깜빡이기
unsigned long time = millis() ;
void setup() {
    Serial.begin(9600);
    pinMode(5, OUTPUT);
}

void loop() {
    Led3OnOff();
}

void Led3OnOff() {
    if (time + 1000 < millis()) {  //millis와 1초 차이나면 LED 키기
        digitalWrite(5, HIGH) ;
    }
    if (time + 2000 < millis()) {  /millis와 또 1초 차이가 나면 LED 끄기
        time = millis() ;
        digitalWrite(5, LOW) ;
    }
}
