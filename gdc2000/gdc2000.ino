#define LED 8
#define servo 9
#define door_closed 10
#define door_open 11
#define button_dn 12
#define button_up 13
#define sensor A3

void setup() {  
  pinMode(servo, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(button_dn, OUTPUT);
  pinMode(button_up, OUTPUT);
  pinMode(door_open, OUTPUT);
  pinMode(door_closed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  static int up = 0;
  static int dn = 0;
  int k = analogRead(sensor);
  Serial.println(k);
  //digitalWrite(LED,1);
  while (analogRead(sensor) < 100){
    if (dn == 1){
      for (int i = 0; i< 2000; i++){
        if (digitalRead(door_open) != 1){
          for (int j = 0; j<3; j++){
            digitalWrite(servo, 1);
            delayMicroseconds(1000);
            digitalWrite(servo, 0);
            delay(50);
          }
        }
      }
      dn = 0;
    }
    if (digitalRead(button_up) == 1){
        up = 1;
        dn = 0;
    }
    if ((dn != 0) || (up == 1)){
        digitalWrite(LED, 1);
    }
      
    if (digitalRead(button_dn) == 1){
      dn = 1;
      up = 0;
    }
    if (up == 1){
      for (int i = 0; i< 2000; i++){
        if (digitalRead(door_closed) == 1){
          for (int j = 0; j<3; j++){
            digitalWrite(servo, 1);
            delayMicroseconds(2000);
            digitalWrite(servo, 0);
            delay(50);
          }
        }
      }
      up = 0;
    }
  }
  Serial.print(" -- ");
  Serial.print(up);
  Serial.print(" --- ");
  Serial.println(dn);
  delay(100);
}
      
      

    

