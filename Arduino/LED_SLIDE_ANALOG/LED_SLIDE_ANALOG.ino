void setup() {
  

}

void loop() {
    for(int i = 750; i >= 0; i -= 10) {
        analogWrite(3, i - 600);
        if (i - 600 <= 0)  digitalWrite(3, 0);
        delay(5);
        if ( i <= 690) {
            analogWrite(5, i - 500);
            if (i - 500 <= 0)  digitalWrite(5, 0);
            delay(5);
            if ( i <= 625) {
                analogWrite(6, i - 400);
                if (i - 400 <= 0)  digitalWrite(6, 0);
                delay(5);
                if ( i <= 565) {
                    analogWrite(9, i - 300);
                    if (i - 300 <= 0)  digitalWrite(9, 0);
                    delay(5);
                    if ( i <= 500) {
                        analogWrite(10, i - 250);
                        if (i - 250 <= 0)  digitalWrite(10, 0);
                        delay(5);
                    }
                }
            }
        }
    }
}
