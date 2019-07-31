//ifttt를 사용하여 webhooks와 메일을 연동한 다음 특정 키워드를 입력하면 메일이 오도록 하는 것이다.
//이것을 하려면 먼저 ifttt에서 webhooks와 메일을 연동한 후 특정 키워드를 입력하여 완성한 다음에 할 수 있다.
//ifttt 라이브러리를 다운받아야 한다.
#include <ifttt.h>

ifttt myifttt;


const char* ssid     = "****";  //현재 접속 중인 ssid
const char* password = "****";  //현재 접속 중인 ssid 비밀번호

//ifttt에서 webhooks와 메일을 연동하면 나오는 토큰 입력↓
const char* token = "******************************************";

const char* trigger_name = "*****";  //특정 단어

void setup() 
{
    //Serial Speed == 115200
    myifttt.connectWifi(ssid, password);
    myifttt.webHooksTriggerRequest(token, trigger_name);
    
    ESP.deepSleep(0);
}
void loop() 
{
}
