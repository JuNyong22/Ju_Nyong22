//스위치를 누를 때마다 Led가 한 칸씩 이동하는 코드입니다.
unsigned char Sw = 0, Flag = 1;

void setup()   
{
    pinMode(7, INPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
}

void loop()    
{
    if(digitalRead(7))  //스위치가 입력되면 Sw 값을 증가시킨다.
    {
        if(Flag)
        {
        Sw++;
        if(Sw == 4) Sw = 0;  //Led는 세 개 뿐이므로 Sw 값이 4가 되면 다시 0으로 초기화한다.
        Flag = 0;
        }
    }
    else    Flag = 1;
    //Sw 값이 증가됨에 따른 Led 한 칸씩 이동하기
    if(Sw == 0)
    {
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
    }
    if(Sw == 1)
    {
        digitalWrite(A0, HIGH);
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
    }
    if(Sw == 2)
    {
        digitalWrite(A0, LOW);
        digitalWrite(A1, HIGH);
        digitalWrite(A2, LOW);
    }
    if(Sw == 3)
    {
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        digitalWrite(A2, HIGH);
    }
}
