/*
 * command_parser.c
 *
 *  Created on: Nov 2, 2023
 *      Author: PC
 */

#include "command_parser.h"

void command_parser_fsm(){
    switch (parser_status)
    {
    case INIT:
        if(buffer[index_buffer-1] == '!'){
            parser_status = END;
            command_index = 0;
        }
        break;

    case END:
        if(buffer[index_buffer-1] == '#'){
            parser_status = INIT;
            command[command_index] = '\0';
            command_flag = 1;
        }
        else if(buffer[index_buffer-1] == '!'){
            command_index = 0;
        }else{
            command[command_index++] = temp;
            if(command_index == MAX_BUFFER_SIZE){
                command_index = 0;
            }
        }
        break;
    
    default:
        break;
    }
    // command_flag = 1;
}
