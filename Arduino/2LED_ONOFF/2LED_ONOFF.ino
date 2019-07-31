#define LED1 10
#define LED2 9
int Cnt = 0;
char Blue_Led_On = 0;
char Green_Led_On = 0;
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

//LED1은 0.5초, LED2는 1.7초마다 깜빡인다.
void loop() {
    Cnt++;
    
    digitalWrite(LED1, Blue_Led_On);
    digitalWrite(LED2, Green_Led_On);
    delay(100);
    
    if (Cnt % 5 == 0) {
      Blue_Led_On = ~Blue_Led_On;
    }
    if (Cnt % 17 == 0){
      Green_Led_On = ~Green_Led_On;
    }
    if (Cnt >= 85) {
      Cnt = 0;
    }
}
