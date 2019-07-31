//FND로 표현할 수 있는 숫자, 문자들을 표시
//(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, C, E, F, H, L, P, U, b, d, t, -(Hypoon), c, u, h)
static int Seg[8] = {2, 3, 4, 5, 6, 7, 8, 9};
static int FND_1[8] = {0, 1, 1, 0, 0, 0, 0, 0}, FND_2[8] = {1, 1, 0, 1, 1, 0, 1, 0};
static int FND_3[8] = {1, 1, 1, 1, 0, 0, 1, 0}, FND_4[8] = {0, 1, 1, 0, 0, 1, 1, 0};
static int FND_5[8] = {1, 0, 1, 1, 0, 1, 1, 0}, FND_6[8] = {1, 0, 1, 1, 1, 1, 1, 0};
static int FND_7[8] = {1, 1, 1, 0, 0, 1, 0, 0}, FND_8[8] = {1, 1, 1, 1, 1, 1, 1, 0};
static int FND_9[8] = {1, 1, 1, 1, 0, 1, 1, 0}, FND_0[8] = {1, 1, 1, 1, 1, 1, 0, 0};
static int FND_A[8] = {1, 1, 1, 0, 1, 1, 1, 0}, FND_b[8] = {0, 0, 1, 1, 1, 1, 1, 0};
static int FND_C[8] = {1, 0, 0, 1, 1, 1, 0, 0}, FND_d[8] = {0, 1, 1, 1, 1, 0, 1, 0};
static int FND_E[8] = {1, 0, 0, 1, 1, 1, 1, 0}, FND_F[8] = {1, 0, 0, 0, 1, 1, 1, 0};
static int FND_H[8] = {0, 1, 1, 0, 1, 1, 1, 0}, FND_L[8] = {0, 0, 0, 1, 1, 1, 0, 0};
static int FND_P[8] = {1, 1, 0, 0, 1, 1, 1, 0}, FND_t[8] = {0, 0, 0, 1, 1, 1, 1, 0};
static int FND_U[8] = {0, 1, 1, 1, 1, 1, 0, 0}, FND_Hypoon[8] = {0, 0, 0, 0, 0, 0, 1, 0};
static int FND_c[8] = {0, 0, 0, 1, 1, 0, 1, 0}, FND_u[8] = {0, 0, 1, 1, 1, 0, 0, 0};
static int FND_h[8] = {0, 0, 1, 0, 1, 1, 1, 0};
static char FND_INPUT, i;

void setup() {
    Serial.begin(9600);
    for(i = 0; i < 8; i++) {
        pinMode(Seg[i], OUTPUT);
    }

}

void loop() {
        Fnd('*');
}

void Fnd(char FND_INPUT) {  //각 숫자일 때, 숫자 표시
    if (FND_INPUT == 1) {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_1[i]);
          }
    }

    if (FND_INPUT == 2) {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_2[i]);
          }
    }

    if (FND_INPUT == 3) {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_3[i]);
          }
    }

    if (FND_INPUT == 4) {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_4[i]);
          }
    }

    if (FND_INPUT == 5) {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_5[i]);
          }
    }

    if (FND_INPUT == 6) {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_6[i]);
          }
    }

    if (FND_INPUT == 7) {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_7[i]);
          }
    }

    if (FND_INPUT == 8) {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_8[i]);
          }
    }

    if (FND_INPUT == 9) {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_9[i]);
          }
    }

    if (FND_INPUT == 0) {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_0[i]);
          }
    }

    if (FND_INPUT == 'A') {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_A[i]);
          }
    }

    if (FND_INPUT == 'b') {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_b[i]);
          }
    }

    if (FND_INPUT == 'C') {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_C[i]);
          }
    }

    if (FND_INPUT == 'd') {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_d[i]);
          }
    }

    if (FND_INPUT == 'E') {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_E[i]);
          }
    }

    if (FND_INPUT == 'F') {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_F[i]);
          }
    }

    if (FND_INPUT == 'H') {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_H[i]);
          }
    }

    if (FND_INPUT == 'L') {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_L[i]);
          }
    }

    if (FND_INPUT == 'P') {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_P[i]);
          }
    }

    if (FND_INPUT == 't') {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_t[i]);
          }
    }

    if (FND_INPUT == 'U') {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_U[i]);
          }
    }

    if (FND_INPUT == '-') {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_Hypoon[i]);
          }
    }
    
    if (FND_INPUT == 'c') {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_c[i]);
          }
    }

    if (FND_INPUT == 'u') {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_u[i]);
          }
    }

    if (FND_INPUT == 'h') {
          for(i = 0; i < 8; i++) {
            digitalWrite(Seg[i], FND_h[i]);
          }
    }
}
