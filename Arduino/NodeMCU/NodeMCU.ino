//Blynk라는 앱을 이용하고 보드도 아두이노 우노가 아닌 NodeMCU에 ESP8266을 사용하였다.
//Blynk 앱에서 a를 입력하면 aaa, b를 입력하면 bbb가 나오도록 구성하였다.
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Blynk 앱에서 주는 코드
char auth[] = "0RCBdLNE0n0MUX_QV2t_Ki06vOxulEFW";

char ssid[] = "****";  //현재 사용 중인 ssid
char pass[] = "****";  //현재 사용 중인 ssid의 비밀번호

BlynkTimer timer;

void setup()
{

  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  
  timer.setInterval(1000L, myTime1);
}

//핸드폰에서 입력하는 문자 출력
BLYNK_WRITE(V7) {
    String Val = param.asStr();
    Serial.print(Val);
}

void myTime1() {
    Serial.println("myTime1");
}

void loop()
{
  Blynk.run();
  timer.run();
  if(Serial.available() > 0) {
    unsigned char Val = Serial.read();
    if(Val == 'a') {
        Serial.println("aaa");
        Blynk.virtualWrite(V7, "aaa");
    }
    else if(Val == 'b') {
        Serial.println("bbb");
        Blynk.virtualWrite(V7, "bbb");
    }
  }
}
