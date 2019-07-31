#include <EEPROM.h>

void setup() {
    Serial.begin(9600);
    Serial.println("Start");
    unsigned char Value = (unsigned char)EEPROM.read(10);
    if(Value == 0xFF) { //초기값일때
        EEPROM.write(10, 1);
    }
    else {
        Value++; //업로드 할 때마다
        EEPROM.write(10, Value);
    }
    unsigned char Value2 = (unsigned char)EEPROM.read(10);
    Serial.println(Value2);
    if(Value2 >= 15) {
        while(1); // 업로드 15회하면 계속 반복 == 15회 업로드 되면 사용 불가능
    }
}

void loop() {
    
}
