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

void changeLED(int i, int j){
    if (i == 0 && j == 1){
        digitalWrite(led_G,1);
		digitalWrite(led_R,0);
		digitalWrite(led_B,0);
        delay(3000);
    }
    else if (i == 0 && j == 2){
        digitalWrite(led_G,1);
        // 30s delays with the opportunity to change floor
        for (int jx = 0; jx <100; jx++){
            if (((digitalRead(button_R) == 0) || (digitalRead(button_hiss_R) == 0))){
                digitalWrite(led_R,1);
                delay(1000);
                digitalWrite(led_B,0);
            }
            delay(30);
        }
        delay(3000);
		digitalWrite(led_G,0);
    }
    if (i == 1){
        digitalWrite(led_R,1);
		digitalWrite(led_G,0);
		digitalWrite(led_B,0);
        delay(3000);
    }
    if (i == 2 && j == 0){
        digitalWrite(led_B,1);
        // 30s delays with the opportunity to change floor
        for (int jx = 0; jx <100; jx++){
            if (((digitalRead(button_R) == 0) || (digitalRead(button_hiss_R) ==0))){
                digitalWrite(led_R,1);
                delay(1000);
                digitalWrite(led_G,0);
            }
            delay(30);
        }
        delay(3000);
		digitalWrite(led_R,0);
    }
	if (i == 2 && j == 1){
		digitalWrite(led_B,1);
		digitalWrite(led_G,0);
		digitalWrite(led_R,0);
		delay(3000);
	}
}
