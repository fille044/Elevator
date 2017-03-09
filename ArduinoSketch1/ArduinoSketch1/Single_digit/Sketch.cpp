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

void loop() {
    static int i = 0;
	// To indicate what floor the elevetor is, or where it is heading
	if (i == 0) changeLED(1,0,0);
	if (i == 1) changeLED(0,1,0);
	if (i == 2) changeLED(0,0,1);
	// One of the green buttons pressed
	if ((digitalRead(button_G)==0) || digitalRead(button_hiss_G)==0){
		move_to_G(i);
		i = 0;
    }
	// One of the red buttons pressed
	if ((digitalRead(button_R)==0) || digitalRead(button_hiss_R)==0){
		move_to_R(i);
		i = 1;
	}
	// One of the blue buttons pressed
	if ((digitalRead(button_B)==0) || digitalRead(button_hiss_B)==0){
		move_to_B(i);
		i = 2;
	}
}
