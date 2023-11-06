// Delay = 10

#define T_on  3
#define T_off 5

int status = 0;
int counter_on = T_on;
int counter_off = T_off;

led_off();

int counter_1s = 100;

while (1)
{
    counter_1s--;
    if(counter_1s <= 0){
        counter_1s = 100;
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
    }
    delay(10);
}
