#define BLUE_LED_PIN 10
#define GREEN_LED_PIN 9

void setup() {
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
}

//파란색 LED는 20%의 밝기, 초록색 LED는 90%의 밝기
void loop() {
    digitalWrite(BLUE_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, HIGH);
    delay(2);
    
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
    delay(7);
    
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    delay(1);
}
