/*
 * functions.cpp
 *
 * Created: 07/03/2017 12:52:39
 *  Author: fille
 *
 * Schoolproject where we simulate the funtions of an elevator.
 * Buttons and LEDs both inside the elevator and in the stairwell.
 * light_it_up inside functions.cpp makes the  elevator go up or down depending
 * on what button is pushed.
 * If you go from floor 2 to 0, and a person on floor 1 presses the button
 * before you have passed floor 1, the elevetor will stop there for one second,
 * and then continue down to floor 0.
 * An emergency button in the elevator will stop the ride and wait for
 * user input.
 *
*/

#include <Arduino.h>
#include <stdlib.h>

#define led_G 8
#define led_R 9
#define led_B 10
#define led_up 12
#define led_down 13
#define button_G 0
#define button_R 1
#define button_B 2
#define button_hiss_G 3
#define button_hiss_R 4
#define button_hiss_B 5
#define foto_0 A0
#define foto_1 A1
#define foto_2 A2

void setup() {
	pinMode(led_G,OUTPUT);
	pinMode(led_R,OUTPUT);
	pinMode(led_B,OUTPUT);
	pinMode(button_G, INPUT);
	pinMode(button_R, INPUT);
	pinMode(button_B, INPUT);
	pinMode(button_hiss_G, INPUT);
	pinMode(button_hiss_R, INPUT);
	pinMode(button_hiss_B, INPUT);
	Serial.begin(9600);
}
void move_to_G(int i);
void move_to_R(int i);
void move_to_B(int i);
void changeLED(int  green, int red, int blue);
void motorLED(int up, int down);


void changeLED(int  green, int red, int blue){
    digitalWrite(led_G, green);
    digitalWrite(led_R, red);
    digitalWrite(led_B, blue);
}
void motorLED(int up, int down){
    digitalWrite(led_up, up);
    digitalWrite(led_down, down);
}

void move_to_G(int i){
	if (i == 2){
		changeLED(0,1,0);
		motorLED(0,1);
		for (int jx = 0; jx < 100 ; jx++){
			if (digitalRead(button_R)==0){
				move_to_R(i);
			}
			delay(30);
		}
		motorLED(0,1);
		changeLED(1,0,0);
		delay(3000);
		motorLED(0,0);
	}
	else if (i == 1){
		motorLED(0,1);
		changeLED(1,0,0);
		delay(3000);
		motorLED(0,0);
	}
}

void move_to_R(int i){
	changeLED(0,1,0);
	if (i == 0){
		motorLED(1,0);
		delay(3000);
		motorLED(0,0);
	}
	else if (i == 2){
		motorLED(0,1);
		delay(3000);
		motorLED(0,0);
	}
}

void move_to_B(int i){
	if (i == 0){
		changeLED(0,1,0);
		motorLED(1,0);
		for (int jx = 0; jx < 100 ; jx++){
			if (digitalRead(button_R)==0){
				move_to_R(i);
			}
			delay(30);
		}
		motorLED(1,0);
		changeLED(0,0,1);
		delay(3000);
		motorLED(0,0);	
	}
	else if (i == 1){
		motorLED(1,0);
		changeLED(0,0,1);
		delay(3000);
		motorLED(0,0);
	}
}



void loop() {	
    static int i = 0;
	if (i == 0) changeLED(1,0,0);
	if (i == 1) changeLED(0,1,0);
	if (i == 2) changeLED(0,0,1);
		
	if (digitalRead(button_G)==0){
		move_to_G(i);
		i = 0;
    }
	if (digitalRead(button_R)==0){
		move_to_R(i);
		i = 1;
	}
	if (digitalRead(button_B)==0){
		move_to_B(i);
		i = 2;
	}
}
