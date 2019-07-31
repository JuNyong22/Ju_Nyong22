unsigned long nowTime = 0, prevTime = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    nowTime = millis();

    if(nowTime - prevTime >= 1000) {
        prevTime = nowTime;
        Serial.println(millis());
    }
}
