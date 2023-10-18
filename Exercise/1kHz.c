// Write a program to generate a square wave on pin PD5 (1 kHz)
// – Using HAL_Delay(uint32_t ms) function

while (1)
{
	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	HAL_Delay(500); // cannot delay(0.5)
}


// Timer2

int counter = 1000;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
//	timerRun();
	counter--;
	if(counter <= 0){
		counter = 1000;
		HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
	}
}