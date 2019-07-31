//스위치를 누르면 SwOn이 출력되면서 LED가 반전된다.
int swValue, Led = 0, Flag = 1;

void setup() {
    Serial.begin(9600);
    pinMode(7, INPUT);
    pinMode(8, OUTPUT);
}

void loop() {
    swValue = digitalRead(7);
    //Serial.println(swValue);

    if(swValue == 0 and Flag != swValue) {
    Led = ~Led;
    Serial.println("SwOn");
    Flag = 0;
    }
    else  Flag = 1;
  
    digitalWrite(8, Led);
}
