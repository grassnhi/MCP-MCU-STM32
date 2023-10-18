// Generate square waves on pins PD1 (10 Hz) and PD7 (100 Hz) respectively. 
// Ngắt => f = 10hz 
// NOOOOOOOOOOOOOOOOOOOOOOOO

int counter = 5;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	counter--;
	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin); // T = 100ms => on-off=50ms
	if(counter <= 0){
		counter = 5;
		HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin); // 1s => on-off=500ms
	}
}


// Use Timer3 interrupts to generate square waves on pins PD1 (10 Hz) and PD7 (100 Hz) respectively.
// Ngắt => f = 100hz

int counter1 = 10;
int counter2 = 10;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	counter1--;
	if(counter1 <= 0){
		counter1 = 10;
		HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin); // 100ms -> No counter => 10ms
		counter2--;
		if(counter2 <= 0){
			counter2 = 10;
			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin); // 1s => No counter => 10 ms, 1 counter => 100ms
		}
	}
}