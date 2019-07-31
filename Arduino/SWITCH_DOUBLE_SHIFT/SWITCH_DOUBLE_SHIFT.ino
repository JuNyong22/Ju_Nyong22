//스위치를 더블클릭 하면 Led 세 개가 한 칸씩 이동하는 코드입니다.
unsigned char Sw = 0, Flag = 1, Led = 0x01, Cnt = 0;
unsigned int  Time = 0;

void setup()   
{
    pinMode(7, INPUT);
    DDRC = 0x07;
}

void loop()    
{
    if(digitalRead(7))  //스위치를 누를 때마다 Cnt를 증가시킨다.
    {
        if(Flag)
        {
            Cnt++;
             Flag = 0;
        }
    }    else    Flag = 1;
    Time = Time + 40;
    delay(40);
    if(Time >= 400)
    {
        Cnt = 0;
        Time = 0;
    }
    if(Cnt >=2)  //Sw를 증가시켜 Led 빛을 한 칸 옆으로 옮긴다.
    {
        Sw++;
        Cnt = 0;
        if(Sw == 4)  //Sw 숫자가 4가 되면 Led는 3개이므로 다시 Sw 값을 초기화시킨다.
            {
                Sw = 0;
                PORTC = 0x00;
            } 
        if(Sw)  PORTC = Led << Sw-1;  //Led 한 칸씩 이동
    } 
}
