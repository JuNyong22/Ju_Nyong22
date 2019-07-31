//10퍼센트의 밝기로 키기
#define BLUE_LED_PIN 9
#define LED_ON 1
#define LED_OFF 0
void setup() {
  pinMode(BLUE_LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(BLUE_LED_PIN, LED_ON);
  delay(1);
  digitalWrite(BLUE_LED_PIN, LED_OFF);
  delay(9);
}
