void setup() {
    Serial.begin(9600);
}

void loop() {
    Led3OnOff();
}

void Led3OnOff() {
    static unsigned long prevTimeLed3 = 0, nowTimeLed3 = 0;
    static unsigned char Led3State = 0;

    nowTimeLed3 = millis();

    if(nowTimeLed3 - prevTimeLed3 >= 1000) {
        prevTimeLed3 = nowTimeLed3;
        Led3State = !Led3State;
        digitalWrite(3, Led3State);
        Serial.println(millis());
    }
}
