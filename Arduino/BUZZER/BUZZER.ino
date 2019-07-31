int piezoPin = 6;
  
void setup() {
  pinMode(piezoPin, OUTPUT);
}



void loop() {
  buzzer();
} 

void buzzer() {
    for(int freq = 150; freq <=1800; freq = freq + 2) {
    tone(piezoPin, freq, 10);
  }



  for(int freq = 1800; freq <=150; freq = freq - 2) {
    tone(piezoPin, freq, 10);
  }
}
