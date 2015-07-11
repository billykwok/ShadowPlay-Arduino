#include <SoftwareSerial.h>

boolean isDark1 = 0;
boolean isDark2 = 0;
boolean isLeft = 0;
boolean isRight = 0;

const int bt_rx = 10;
const int bt_tx = 11;
SoftwareSerial BTSerial(bt_rx, bt_tx);

enum Position {
	LEFT, MIDDLE, RIGHT
} pos;

void setup() {
	BTSerial.begin(38400);
	Serial.begin(115200);
	pos = MIDDLE;
}

void loop() {
	float temp = analogRead(0);
	Serial.println(temp);
	if (temp < 140) {
		isDark1 = 1;
	} else if (temp >= 140 && isDark1) {
		isDark1 = 0;
		if (pos == MIDDLE || pos == RIGHT) {
			BTSerial.print("l");
			BTSerial.println(F(""));
			// Serial.println("l");
			pos = LEFT;
		} else {
			BTSerial.print("m");
			BTSerial.println(F(""));
			// Serial.println("m");
			pos = MIDDLE;
		}
	}
	float temp2 = analogRead(1);
	if (temp2 < 120) {
		isDark2 = 1;
	} else if (temp2 >= 120 && isDark2) {
		isDark2 = 0;
		if (pos == MIDDLE || pos == LEFT) {
			BTSerial.print("r");
			BTSerial.println(F(""));
			// Serial.println("r");
			pos = RIGHT;
		} else {
			BTSerial.print("m");
			BTSerial.println(F(""));
			// Serial.println("m");
			pos = MIDDLE;
		}
	}
}
