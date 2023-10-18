// Write a program using Timer3 to generate asquare wave on pin PD5 (1 kHz)

    HAL_TIM_Base_Start_IT(&htim3);

int counter = 1000;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	counter--;
    if(counter <= 0){
        counter = 1000;
        HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    }
}