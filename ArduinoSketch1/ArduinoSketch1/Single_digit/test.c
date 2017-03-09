if ((digitalread(button_G)||digitalRead(button_hiss_G))==0 && i == 1){
    i = j;
    i=0;
    changeLED(i, j);
}
if ((digitalread(button_R)||digitalRead(button_hiss_R))==0 && i == 1){
    i = j;
    i=0;
    changeLED(i, j);
}
if ((digitalread(button_B)||digitalRead(button_hiss_B))==0 && i == 1){
    i = j;
    i=0;
    changeLED(i, j);
}


void changeLED(int i, int j){
    if (i == 0 && j == 1){
        digitalWrite(led_G,1);
        delay(3000);
    }
    else if (i == 0 && j == 2){
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
    if (i == 1){
        digitalWrite(led_R,1);
        delay(3000);
    }
    if (i == 2 && j == 0){
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


}
