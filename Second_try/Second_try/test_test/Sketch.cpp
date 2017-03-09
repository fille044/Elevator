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

// Lights up the LED that is called
// (0,1,0) will light up the red LED
void changeLED(int  green, int red, int blue){
    digitalWrite(led_G, green);
    digitalWrite(led_R, red);
    digitalWrite(led_B, blue);
}
// Light blue for up, red for down
// (0,1) will light up red LED
// Could be used to power a motor up or down.
void motorLED(int up, int down){
    digitalWrite(led_up, up);
    digitalWrite(led_down, down);
}

// Moves the elevator to bottom floor, green
void move_to_G(int i){
	// From top(blue) to bottom(green)
	if (i == 2){
		changeLED(0,1,0);
		motorLED(0,1);
		// 100 30ms delays gives the opportunity to stop
		// at red floor on the way up
		for (int jx = 0; jx < 100 ; jx++){
			// If any of the red buttons are pressed, it will do a quick
			// stop at red floor and pick up people
			if ((digitalRead(button_R)==0) || digitalRead(button_hiss_R)==0){
				move_to_R(i);
			}
			delay(30);
		}
		motorLED(0,1);
		changeLED(1,0,0);
		delay(3000);
		motorLED(0,0);
	}
	// From middle(red) to bottom(green)
	else if (i == 1){
		motorLED(0,1);
		changeLED(1,0,0);
		delay(3000);
		motorLED(0,0);
	}
}

// Moves the elevator to middle floor, red
void move_to_R(int i){
	changeLED(0,1,0);
	// From bottom(green) to middle(red)
	if (i == 0){
		motorLED(1,0);
		delay(3000);
		motorLED(0,0);
	}
	// From top(blue) to middle(red)
	else if (i == 2){
		motorLED(0,1);
		delay(3000);
		motorLED(0,0);
	}
}

// Moves the elevator to top floor, blue
void move_to_B(int i){
	// From bottom(green) to top(blue)
	if (i == 0){
		changeLED(0,1,0);
		motorLED(1,0);
		// 100 30ms delays gives the opportunity to stop
		// at red floor on the way up
		for (int jx = 0; jx < 100 ; jx++){
			// If any of the red buttons are pressed, it will do a quick
			// stop at red floor and pick up people
			if ((digitalRead(button_R)==0) || digitalRead(button_hiss_R)==0){
				move_to_R(i);
			}
			delay(30);
		}
		motorLED(1,0);
		changeLED(0,0,1);
		delay(3000);
		motorLED(0,0);
	}
	// From middle(red) to top(blue)
	else if (i == 1){
		motorLED(1,0);
		changeLED(0,0,1);
		delay(3000);
		motorLED(0,0);
	}
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
