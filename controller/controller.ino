#include <SoftwareSerial.h>

const int bt_rx = 10;
const int bt_tx = 11;
SoftwareSerial BTSerial(bt_rx, bt_tx);

const int PI_PIN = 0;
const int sens = 2;  // this value indicates the limit reading between dark and light,
const int nPalas = 36; // the number of blades of the propeller
const int milisegundos = 100; // the time it takes each reading
const int DEBUG_PIN = 6;

int val = 0;
long last = 0;
int stat = LOW;
int stat2;
int contar = 0;

void setup() {
    BTSerial.begin(9600);
    Serial.begin(9600);
    pinMode(DEBUG_PIN, OUTPUT);
}

void loop() {
    if (BTSerial.available() > 0) {
        Serial.write(BTSerial.read());
    }

    val = map(analogRead(PI_PIN), 0, 1023, 0, 100);
    stat = val < sens ? LOW : HIGH;
    digitalWrite(DEBUG_PIN, stat);
    
    if (stat2 != stat) {
        ++contar;
        stat2 = stat;
    }

    if (millis() - last >= milisegundos) {
        // double rps = ((double) contar / nPalas) / 2.0 * 1000.0 / milisegundos;
        double rpm = ((double) contar / nPalas) / 2.0 * 60000.0 / milisegundos;
        // Serial.print(contar / 2.0);
        // Serial.print("  RPS ");
        // Serial.print(rps);
        // Serial.print(" RPM");
        Serial.print(rpm);
        // Serial.print("  VAL ");
        // Serial.println(val);
        contar = 0;
        last = millis();
    }
    // BTSerial.write();
}