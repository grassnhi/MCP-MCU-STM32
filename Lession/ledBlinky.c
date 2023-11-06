// LED turn on and off every second (LED Blinky)

int led_status = 0;
while(1){
    led_status = 1 - led_status;
    if(led_status == 1){
        turn_on();
    }else{
        turn_off();
    }
    delay(1000)
}