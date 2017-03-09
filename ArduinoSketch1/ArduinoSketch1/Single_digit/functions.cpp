#include <Arduino.h>
#include <stdlib.h>
#include "functions.h"


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
