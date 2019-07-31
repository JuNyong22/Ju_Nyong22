#define BLUE_LED_PIN 10
#define GREEN_LED_PIN 9
unsigned char cnt_blue = 0, cnt_green = 0;

void setup() {
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
}

//파란색 LED는 20%의 밝기, 초록색 LED는 90%의 밝기
void loop() {
  cnt_blue++;
  cnt_green++;
  delay(1);
  
  if (cnt_blue <= 2) digitalWrite(BLUE_LED_PIN, 1);
  else  {
    digitalWrite(BLUE_LED_PIN, 0);
    if (cnt_blue <= 10) cnt_blue = 0;
  }

  if (cnt_green <= 9) digitalWrite(GREEN_LED_PIN, 1);
  else  {
    digitalWrite(GREEN_LED_PIN, 0);
    if (cnt_green <= 10) cnt_green = 0;
  }
}
