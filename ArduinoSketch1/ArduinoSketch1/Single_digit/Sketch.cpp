#include <Arduino.h>
#include <stdlib.h>

#define led_Y 8
#define led_R 9
#define led_B 10
#define button_Y 0
#define button_R 1
#define button_B 2
#define button_hiss_0 3
#define button_hiss_1 4
#define button_hiss_2 5


void setup() {
	pinMode(led_Y,OUTPUT);
	pinMode(led_R,OUTPUT);
	pinMode(led_B,OUTPUT);
	pinMode(button_Y, INPUT);	
	pinMode(button_R, INPUT);	
	pinMode(button_B, INPUT);
	pinMode(button_hiss_0, INPUT);
	pinMode(button_hiss_1, INPUT);
	pinMode(button_hiss_2, INPUT);
	Serial.begin(9600);
}

void light_it_up(void){
	static int i = 0;
	//Clear LEDs
	digitalWrite(led_Y,0);
	digitalWrite(led_R,0);
	digitalWrite(led_B,0);
	// Keep the LED alive
	if (i == 0){
		digitalWrite(led_Y,1);
	}
	if (i == 1){
		digitalWrite(led_R,1);
	}
	if (i == 2){
		digitalWrite(led_B,1);
	}

	// All combinations for where you and the elevetor are
	// 3s delay for one floor, 6s delay for two floors
	if ((digitalRead(button_Y) == 0 || digitalRead(button_hiss_0)==0) && i == 2){
		i = 0;
		digitalWrite(led_Y,1);
		for (int jx = 0; jx <100; jx++){
			if ((digitalRead(button_R) == 0 || digitalRead(button_hiss_1)==0)){
				digitalWrite(led_R,1);
				delay(1000);
				digitalWrite(led_B,0);
			}
			delay(30);
		}
		delay(3000);
	}
	if ((digitalRead(button_Y)==0 || digitalRead(button_hiss_0)==0) && i == 1){
		i = 0;
		digitalWrite(led_Y,1);
		delay(3000);
	}
	if ((digitalRead(button_R)==0 || digitalRead(button_hiss_1)==0) && i == 0){
		i = 1;
		digitalWrite(led_R,1);
		delay(3000);
	}
	if ((digitalRead(button_R)==0 || digitalRead(button_hiss_1)==0) && i == 2){
		i = 1;
		digitalWrite(led_R,1);
		delay(3000);
	}
	if ((digitalRead(button_B)==0 || digitalRead(button_hiss_2)==0) && i == 0){
		i = 2;
		digitalWrite(led_B,1);
		for (int jx = 0; jx <100; jx++){
			if ((digitalRead(button_R) == 0 || digitalRead(button_hiss_1)==0)){
				digitalWrite(led_R,1);
				delay(1000);
				digitalWrite(led_Y,0);
			}
			delay(30);
		}
		delay(3000);
	}
	if ((digitalRead(button_B)==0 || digitalRead(button_hiss_2)==0) && i == 1){
		i = 2;
		digitalWrite(led_B,1);
		delay(3000);
	}
}

void loop() {
	light_it_up();
}