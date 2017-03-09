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

void move_to_G(int i);
void move_to_R(int i);
void move_to_B(int i);
void changeLED(int  green, int red, int blue);
void motorLED(int up, int down);
