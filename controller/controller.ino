#include <SoftwareSerial.h>

const int bt_rx = 10;
const int bt_tx = 11;
String str = "";
int index = 0;
SoftwareSerial BTSerial(bt_rx, bt_tx);

void setup() {
    BTSerial.begin(9600);
    Serial.begin(9600);
}

void loop() {
    if (BTSerial.available() > 0) {
        Serial.write(BTSerial.read());
    }
    // BTSerial.write();
}