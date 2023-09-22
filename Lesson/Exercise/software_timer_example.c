setTimer1(200);
while (1)
{ 
  if(timer1_flag == 1){
	  setTimer1(200);
	  //TODO
  }
 
  timerRun();
  HAL_Delay(10);
}