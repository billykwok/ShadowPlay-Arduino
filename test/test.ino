#include <SoftwareSerial.h>

const int bt_rx = 10;
const int bt_tx = 11;
SoftwareSerial BTSerial(bt_rx, bt_tx);

void setup() {
    BTSerial.begin(9600);
}

void loop() {
    BTSerial.print(1234, DEC);
    BTSerial.println(F(""));
    delay(500);
}