#include<LiquidCrystal_I2C_Hangul.h>
#include<Wire.h>

LiquidCrystal_I2C_Hangul lcd(0x27, 16, 2);

unsigned int i = 0;
unsigned char MinTime = 0, SecTime = 0, Flag1 = 1, Flag2 = 1, Flag3 = 0, StCnt = 0;
unsigned char NewMin, OldMin = 0, NewSec, OldSec = 0;
char Colon = ':';
unsigned long Time = millis(), MinMillis = millis(), SecMillis = millis();
int BuzzerPin = 11;

void setup() {
    Serial.begin(9600);
    pinMode(8, INPUT);
    pinMode(9, INPUT);
    pinMode(10, INPUT);
    pinMode(BuzzerPin, OUTPUT);
}

void loop() {
    lcd.clear();
    lcd.backlight();

    if(millis - MinMillis >= 40) {
        if(digitalRead(8)) {
            if(Flag1) {
                Flag1 = 0;
                Serial.println(MinTime);
                MinTime++;
                if(MinTime >= 60)   MinTime = 60;
            }
        }
        else Flag1 = 1;
    }

    if(millis - SecMillis >= 40) {
        if(digitalRead(9)) {
            if(Flag2) {
                Flag2 = 0;
                Serial.println(SecTime);
                SecTime++;
                if(SecTime >= 60) {
                    MinTime++;
                    SecTime = 0;
                }
            }
        }
    }
    else Flag2 = 1;

    if(digitalRead(8) and digitalRead(9) and millis() - Time >= 40) {
        MinTime = 0;
        SecTime = 0;
    }

    if(digitalRead(10)) {
        StCnt++;
        if(Flag3 and StCnt % 2 == 1) {
            Flag3 = 0;
            for(i = MinTime * 60 + SecTime; i < 0; i--) {
                SecTime--;
                if(SecTime < 0) {
                    SecTime = 59;
                    MinTime--;
                }
                if(i <= 0) {
                    tone(BuzzerPin, 500, 1000);

                    tone(BuzzerPin, 0, 1000);
                }
            }
        }
    }
    else Flag3 = 1;

    if(MinTime < 10)    lcd.print(0);
    lcd.print(MinTime);
    lcd.print(Colon);

    if(SecTime < 10)    lcd.print(0);
    lcd.print(SecTime);
}
