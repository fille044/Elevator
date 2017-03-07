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
#include "functions.h"

#define led_G 8
#define led_R 9
#define led_B 10
#define button_G 0
#define button_R 1
#define button_B 2
#define button_hiss_0 3
#define button_hiss_1 4
#define button_hiss_2 5
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
	pinMode(button_hiss_0, INPUT);
	pinMode(button_hiss_1, INPUT);
	pinMode(button_hiss_2, INPUT);
	Serial.begin(9600);
}

void loop() {
	light_it_up();
	int value = analogRead(foto_0);
	Serial.println(value);
}
