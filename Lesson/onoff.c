// LED turns on for 3 seconds and then turn off for 5 second

#define T_on  3
#define T_off 5

int status = 0;
int counter_on = T_on;
int counter_off = T_off;

led_off();

while (1)
{
    if(status == 0){
        led_off();
        counter_off--;
        if(counter_off <= 0){
            status = 1;
            counter_off = 5;
        }
    }else{
        led_on();
        counter_on--;
        if(counter_on <= 0){
            status = 0;
            counter_on = 3;
        }
    }
    delay(1000);
}
