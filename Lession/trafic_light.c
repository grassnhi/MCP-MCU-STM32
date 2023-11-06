enum TrafficLightState {
    RED1_GREEN2,
	RED1_YELLOW2,
	GREEN1_RED2,
	YELLOW1_RED2,
  };
// Initialize the current state of the traffic light
int counter = 3;
int light = 5;
enum TrafficLightState currentState = RED1_GREEN2;
enum TrafficLightState nextState = currentState;
while (1)
  {
	  display7SEG(light);
	  switch (currentState) {
	    case RED1_GREEN2:
	    	turnonTraffigLights(RED1);
	    	turnonTraffigLights(GREEN2);
	    	counter--;
	    	light--;
	    	if(counter <= 0)
	    	{
	    		nextState = RED1_YELLOW2;
	    		counter = 2;
	    	}
	    	break;
	    case RED1_YELLOW2:
	    	turnonTraffigLights(RED1);
	    	turnonTraffigLights(YELLOW2);
	    	counter--;
	    	light--;
	    	if(counter <= 0)
	    	{
	    		nextState = GREEN1_RED2;
		    	counter = 3;
		    	light = 3;
	    	}
	    	break;
	    case GREEN1_RED2:
	    	turnonTraffigLights(GREEN1);
	    	turnonTraffigLights(RED2);
	    	counter--;
	    	light--;
	    	if(counter <= 0)
	    	{
	    		nextState = YELLOW1_RED2;
		    	counter = 2;
		    	light = 2;
	    	}
	    	break;
	    case YELLOW1_RED2:
	    	turnonTraffigLights(YELLOW1);
	    	turnonTraffigLights(RED2);
	    	counter--;
	    	light--;
	    	if(counter <= 0)
	    	{
	    		nextState = RED1_GREEN2;
		    	counter = 3;
		    	light = 5;
	    	}
	    	break;
	  }
	  currentState = nextState;
	  HAL_Delay(1000);
  }