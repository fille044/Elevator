/*
* Library with functions for the single digit module ELS-321GWA
* Last updated: 2017-03-02
* Delivered to you by Filip Lindström and Dennis Bunne.

* Defines all the output-pins. Top = pin1, top-right = pin2,
   top-left = pin3, middle = pin4, bottom-right = pin5,
   bottom-left = pin6, bottom = pin7, dot = pin8.
* The dice-function will print random numbers between 1-6.
   Could be used with a button.
* Counter is a function that counts from 0-9.
* Reverse_counter counts the opposite way, from 9-0.
* Clear_display will empty the display from previous numbers.
* Print_number will print the integer you send as an argument, 0-9.
*/

#include <ELS-321GWB.h>
#include <arduino.h>

// Simplified the pin layout
#define T 1
#define T_R 2
#define T_L 3
#define M 4
#define B 7
#define B_L 6
#define B_R 5
#define D 8

void dice(){
  int k = (rand() % 6) + 1;
  clear_display();
  delay(100);
  print_number(k);
  delay(1000);
}

// Counts from 0-9 on the display with 500ms delay
void counter(){
  for (int i=0;i<10;i++){
    clear_display();
    print_number(i);
    delay(500);
  }
}

// Counts from 9-0 on the display with 500ms delay
void reverse_counter(){
  for (int i=9;i>=0;i--){
    clear_display();
    print_number(i);
    delay(500);
  }
}

// Sets all the output-pins to low, to clear the screen
void clear_display(){
  digitalWrite(T_R,0);
  digitalWrite(T_L,0);
  digitalWrite(T,0);
  digitalWrite(M,0);
  digitalWrite(B_L,0);
  digitalWrite(B_R,0);
  digitalWrite(B,0);
}

// Prints whatever number is written as argument. From 0-9
void print_number(int a){
  switch(a){
    case 0:
      digitalWrite(T_R,1);
      digitalWrite(B_R,1);
      digitalWrite(B,1);
      digitalWrite(B_L,1);
      digitalWrite(T_L,1);
      digitalWrite(T,1);
      break;
    case 1:
      digitalWrite(T_R,1);
      digitalWrite(B_R,1);
      break;
    case 2:
      digitalWrite(T_R,1);
      digitalWrite(T,1);
      digitalWrite(B_L,1);
      digitalWrite(M,1);
      digitalWrite(B,1);
      break;
    case 3:
      digitalWrite(T_R,1);
      digitalWrite(T,1);
      digitalWrite(B_R,1);
      digitalWrite(M,1);
      digitalWrite(B,1);
      break;
    case 4:
      digitalWrite(T_R,1);
      digitalWrite(T_L,1);
      digitalWrite(M,1);
      digitalWrite(B_R,1);
      break;
    case 5:
      digitalWrite(T,1);
      digitalWrite(T_L,1);
      digitalWrite(B_R,1);
      digitalWrite(M,1);
      digitalWrite(B,1);
      break;
    case 6:
      digitalWrite(T_L,1);
      digitalWrite(T,1);
      digitalWrite(B_L,1);
      digitalWrite(B_R,1);
      digitalWrite(M,1);
      digitalWrite(B,1);
      break;
    case 7:
      digitalWrite(T_R,1);
      digitalWrite(B_R,1);
      digitalWrite(T,1);
      break;
    case 8:
      digitalWrite(T_R,1);
      digitalWrite(T_L,1);
      digitalWrite(T,1);
      digitalWrite(M,1);
      digitalWrite(B_L,1);
      digitalWrite(B_R,1);
      digitalWrite(B,1);
      break;
    case 9:
      digitalWrite(T_R,1);
      digitalWrite(T_L,1);
      digitalWrite(T,1);
      digitalWrite(M,1);
      digitalWrite(B_R,1);
      digitalWrite(B,1);
      break;
  }
}
