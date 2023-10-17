void loop(){ 
    switch(status){ 
        case INIT: 
            pinMode(13, OUTPUT); 
            setTimer(T_on); 
            status = LED_ON; 
            digitalWrite(13, HIGH); 
            break; 
        case LED_ON: 
            if(timer_flag == 1){
                status = LED_OFF;
                setTimer(T_off);
                digitalWrite(13, LOW); 
            } 
            break; 
        case LED_OFF: 
            if(timer_flag == 1){
                status = LED_ON;
                setTimer(T_on);
                digitalWrite(13, HIGH); 
            } 
            break; 
        default: 
            break; 
    }
    delay(10); 
}

void timer_run(){ 
    if(timer_counter > 0) 
        timer_counter--; 
    if(counter_timer == 0) 
        timer_flag =1; 
} 

void setTimer(long duration){ 
    timer_counter = duration; 
    timer_flag = 0; 
}