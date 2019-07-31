//인터럽트를 사용해보기
unsigned char Sw2 = 2;
unsigned char led8 = 8;

void setup() {
    pinMode(led8, OUTPUT);
    pinMode(Sw2, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(Sw2), SwInt, CHANGE); // Eable interrupt
}

void loop() {
    
}

void SwInt() {
    noInterrupts();  //인터럽트 사용 금지
    static unsigned char LedState = 0;
    LedState = !LedState;  //LED 반전
    digitalWrite(led8, LedState);
    delay(200);
    interrupts();  //인터럽트 사용 금지 풀기
}
