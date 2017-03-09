/*
 * functions.cpp
 *
 * Created: 07/03/2017 12:52:39
 *  Author: fille
 */
#include <Arduino.h>
#include <stdlib.h>
#include "functions.h"

#define led_G 8
#define led_R 9
#define led_B 10
#define button_G 0
#define button_R 1
#define button_B 2
#define button_hiss_G 3
#define button_hiss_R 4
#define button_hiss_B 5
#define foto_0 A0
#define foto_1 A1
#define foto_2 A2

void light_it_up(void){
	// If i=0, floor 0
	// If i=1, floor 1
	// If i=2, floor 2
	static int i = 0;

	Serial.println(i);

	//Clear LEDs
	digitalWrite(led_G,0);
	digitalWrite(led_R,0);
	digitalWrite(led_B,0);
	// Keep only one LED alive
	if (i == 0){
 		digitalWrite(led_G,1);
	}
	if (i == 1){
 		digitalWrite(led_R,1);
	}
	if (i == 2){
 		digitalWrite(led_B,1);
	}

	// All combinations for where you and the elevator are
	// 3s delay for one floor, 6s delay for two floors, 1s delay for pick up

	if ((digitalRead(button_G) == 0 || digitalRead(button_hiss_G) == 0) && i == 2){
 		i = 0;
 		digitalWrite(led_G,1);
		// 30s delays with the opportunity to change floor
 		for (int jx = 0; jx <100; jx++){
 			if ((digitalRead(button_R) == 0 || digitalRead(button_hiss_R) == 0)){
 				digitalWrite(led_R,1);
 				delay(1000);
 				digitalWrite(led_B,0);
 			}
 			delay(30);
 		}
 		delay(3000);
	}
	if ((digitalRead(button_G) == 0 || digitalRead(button_hiss_G) == 0) && i == 1){
 		i = 0;
 		digitalWrite(led_G,1);
 		delay(3000);
	}
	if ((digitalRead(button_R) == 0 || digitalRead(button_hiss_R) == 0) && i == 0){
 		i = 1;
 		digitalWrite(led_R,1);
 		delay(3000);
	}
	if ((digitalRead(button_R) == 0 || digitalRead(button_hiss_R) == 0) && i == 2){
 		i = 1;
 		digitalWrite(led_R,1);
 		delay(3000);
	}
	if ((digitalRead(button_B) == 0 || digitalRead(button_hiss_B) == 0) && i == 0){
 		i = 2;
 		digitalWrite(led_B,1);
		// 30s delays with the opportunity to change floor
 		for (int jx = 0; jx <100; jx++){
 			if ((digitalRead(button_R) == 0 || digitalRead(button_hiss_R) ==0 )){
 				digitalWrite(led_R,1);
 				delay(1000);
 				digitalWrite(led_G,0);
 			}
 			delay(30);
 		}
 		delay(3000);
	}
	if ((digitalRead(button_B) == 0 || digitalRead(button_hiss_B) == 0) && i == 1){
 		i = 2;
 		digitalWrite(led_B,1);
 		delay(3000);
	}
	delay(100);
}
