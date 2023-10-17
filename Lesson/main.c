#include "led.h" 
#include "timer.h" 
#include "gpio.h" 
#include "button.h" 

void main(){
    initGPIO();
    initTimer();
    initButton();
    initLED();
    ....
    ....
    while(1){

    }; 
} 

void timer_isr(){ 

} 

void ext_isr(){

}