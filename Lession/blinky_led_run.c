#include "blinky_led.h"
#include "software_timer.h"

void led_on(){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
}

void led_off(){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);
}

int main(){
    /* ... */
    led_status = INIT;

    while (1)
    {
        blinky_led_run();
    }
}
    

/* ... */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	timerRun();
}