//스위치를 누를 때마다 LED가 한 칸씩 옆으로 이동한다.
#define LED0 A0
#define LED1 A1
#define LED2 A2
int oldSwValue = 0, newSwValue, LedState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);  //스위치
  pinMode(LED0, OUTPUT);  //LED1
  pinMode(LED1, OUTPUT);  //LED2
  pinMode(LED2, OUTPUT);  //LED3
}

void loop() {
    newSwValue = digitalRead(7);
    
    if(oldSwValue != newSwValue) {
        oldSwValue = newSwValue;
        if(newSwValue >= 1) {
            LedState++;  //LedState의 값을 1씩 증가
            Serial.println("swOn");  //스위치가 눌릴 때마다 "SwOn"이 출력된다.
            if(LedState >= 3)   LedState = 0;
        }
    }

    //LED 세 개가 한 칸씩 이동할 수 있도록 하였다.
    if(LedState == 0){  
        digitalWrite(LED0, HIGH);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
    }
    else if(LedState == 1){
        digitalWrite(LED0, LOW);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
    }
    else {
        digitalWrite(LED0, LOW);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
    }
    delay(40);
}
