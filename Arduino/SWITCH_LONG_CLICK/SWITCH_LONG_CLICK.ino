unsigned int Time = 0, Cnt = 0, Flag = 1;

void setup() 
{
    pinMode(7, INPUT);
    Serial.begin(9600);
}

void loop() 
{
    while(digitalRead(7)) {
        if(Flag == 1) {
            Time++;
            Cnt = 1;
            delay(100);
            if(Time >= 6) {  //0.6 초가 지나면 Long Click을 출력한다.
                Time = 0;
                Serial.println("Long Click");
                Cnt = 0;
                Flag = 0;
            }
        }
    }
    if(digitalRead(7) == 0)    Flag = 1;
    if(Cnt) {
        if(Time < 6) {  //만약 스위치가 0.6 초 이내로 눌린다면 Click을 출력한다.
                Serial.println("click");
                Time = 0;
                Cnt = 0;
            }
    }
}
