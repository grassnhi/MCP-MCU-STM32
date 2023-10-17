// Blinky LED1 and LED2 every 2 seconds ver 1
// HAL_GPIO_Toggle in while(1)

while (1)
{
	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
	HAL_Delay(2000);
}

// Blinky LED1 and LED2 every 2 seconds ver 2

while (1)
{
	HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	HAL_Delay(2000);
	HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
}