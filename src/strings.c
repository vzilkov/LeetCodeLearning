
int transform_string(char* str, int len){
    char bs_symbol = '#';
    int count_symbols_in_str = len;
    for(int i=len, bs_counter=0; 
                i >= 0; 
                i--)
    {
        if(str[i] == bs_symbol)
        {
            bs_counter++;
            str[i] = 0;
            count_symbols_in_str--;
        }
        else if(bs_counter){
            bs_counter--;
            str[i] = 0;
            count_symbols_in_str--;
        }
    }
    return count_symbols_in_str;
}

int backspaceCompare(char* s, char* t) {
    int result = 1;
    int s_len = strlen(s);
    int t_len = strlen(t);

    // char s[] = "aaa###a";
    // char t[] = "aaaa###a";
    int len_s_tran_str = 0, len_t_tran_str = 0;
    len_s_tran_str = transform_string(s, s_len);
    len_t_tran_str = transform_string(t, t_len);

    if(len_s_tran_str != len_t_tran_str){
        return 0;
    }

    for(int i=0,j=0; i<s_len && j<t_len; i++,j++){
        while(s[i] == 0 && i<s_len){
            i++;
        }
        while(t[j] == 0 && j<t_len){
            j++;
        }
        if(s[i] != t[j]){
            return 0;
        }
    }
    
    return result;
}