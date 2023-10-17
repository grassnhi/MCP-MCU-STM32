// Configure Timer2 Interrupt for every (Cycle T =) 10ms

/*
T = 10 ms => f = 100 Hz 
F = 8 MHz => f = 1 / (pre+1)(1+counter) = 100 => pre = 7999
                                                counter = 9
*/

int counter = 100;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	counter--;
	if(counter <= 0){
		counter = 100;
		HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	}
}

// Generate a pulse on PA5 having freq = 50Hz and Duty Cycle = 50%

/*
Duty cycle = ON / T = 50% => ON = OF => ON = OFF = 1s
f = 1 / T = 50 Hz => T = 20 ms => 1s = 20 ms x 50
F = 8 MHz => f = 1 / (pre+1)(1+counter) = 50 => pre = 9999
                                                counter = 15
*/

int counter = 50;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	counter--;
	if(counter <= 0){
		counter = 50;
		HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	}
}