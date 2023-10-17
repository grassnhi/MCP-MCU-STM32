// Blinky LED1 every 2 seconds using timer interrupt
// Use a counter

int main(void)
{
  /* . . . */
  HAL_TIM_Base_Start_IT(&htim2);

  while (1)
  {


  }
}

/* . . . */

int counter = 200;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	counter--;
	if(counter <= 0){
		counter = 200;
		HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	}
}

// Blinky 2 LED every 2 seconds using timer interrupt 

int counter = 200;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	counter--;
	if(counter <= 0){
		counter = 200;
		HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
	}
}