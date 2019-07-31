//FND 500을 사용
#define FND_A 2
#define FND_B 3
#define FND_C 4
#define FND_D 5
#define FND_E 6
#define FND_F 7
#define FND_G 8
#define FND_DP 9

void setup() {
    Serial.begin(9600);
    pinMode(FND_A, OUTPUT);
    pinMode(FND_B, OUTPUT);
    pinMode(FND_C, OUTPUT);
    pinMode(FND_D, OUTPUT);
    pinMode(FND_E, OUTPUT);
    pinMode(FND_F, OUTPUT);
    pinMode(FND_G, OUTPUT);
    pinMode(FND_DP, OUTPUT);

}

void loop() {
    Fnd1();
}

void Fnd1() {  //1을 표시
    digitalWrite(FND_A, LOW);
    digitalWrite(FND_B, HIGH);
    digitalWrite(FND_C, HIGH);
    digitalWrite(FND_D, LOW);
    digitalWrite(FND_E, LOW);
    digitalWrite(FND_F, LOW);
    digitalWrite(FND_G, LOW);
    digitalWrite(FND_DP, LOW);
}
