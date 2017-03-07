#include <Arduino.h>
#include <stdlib.h>

#define led_Y 8
#define led_R 9
#define led_B 10
#define button_Y 0
#define button_R 1
#define button_B 2

void setup() {
	pinMode(led_Y,OUTPUT);
	pinMode(button_Y, INPUT);	
	pinMode(led_R,OUTPUT);
	pinMode(button_R, INPUT);	
	pinMode(led_B,OUTPUT);
	pinMode(button_B, INPUT);
	Serial.begin(9600);
}

void loop() {
	
	digitalWrite(led_Y,0);
	digitalWrite(led_R,0);
	digitalWrite(led_B,0);

	if (digitalRead(button_Y) == 0){
		digitalWrite(led_Y,1);
	}
	if (digitalRead(button_R) == 0){
		digitalWrite(led_R,1);
	}	
	if (digitalRead(button_B) == 0){
		digitalWrite(led_B,1);
	}
}