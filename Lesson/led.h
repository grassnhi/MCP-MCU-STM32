#ifndef  __LED_H_ 
#define __LED_H_ 

#include <system_lib.h> 
#include "user_lib.h"
#include "UserFolder/lib.h"

extern int T_on; 
extern int T_off;  

void setOn(long duration); 
void setoff(long duration); 

#endif