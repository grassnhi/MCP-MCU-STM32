// LED turns on for 3 seconds and then turn off for 5 second
// Delay = 10

int led_status = 1, on_sec = 0, off_sec = 0;
while (1)
{
    if(led_status == 1){
        on_sec +=1;
        if(on_sec == 300){
            led_off();
            led_status = 0;
            on_sec = 0;
        }
    }else{
        off_sec += 1;
        if(off_sec == 500){
            led_on();
            led_status = 1;
            off_sec = 0;
        }
    }
    delay(10);
}
