// LED turn on and off every second. Change the delay from 1000 to 10

int led_status = 0;
int count = 100;
while (1){
    if (count <= 0){
        led_status = 1;
        if (led_status == 1){
            led_on();
        }
        else{
            led_off();
        }
        count = 100;
    }
    count --;
    delay(10);
}
