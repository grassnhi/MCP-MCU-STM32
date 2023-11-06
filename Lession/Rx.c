void Rx_Callback(){ // reading a character
    buffer_flag = 1;
    buffer_data = read_char();
}

void Token_Parser(){ // reading a word/token/command
    if(buffer_flag == 1){
        buffer_flag = 0;

        // TODO your DFA

        token_flag = 1;
        token_data = "OK/RTS/ADC";
    }
}

void communication_processing(){
    if(token_flag == 1){
        token_flag = 0;
        // TODO your DFA
    }
}