
char * customSortString(char * order, char * str){
    int arr[27] = {0};
    int i, j,k, index = 0;
    int order_len = strlen(order);
    int str_len = strlen(str);
    char op_string[201];
    
    for(i=0;i<str_len;i++){
        arr[str[i] - 'a']++;
    }

    for(i=0;i<order_len;i++){
        for(j=0;j<arr[order[i]-'a'];j++) 
            op_string[index++] = order[i];
        arr[order[i] - 'a'] = 0;
    }
    for(i=0;i<27;i++){
        while(arr[i] != 0){
            op_string[index++] = i + 'a';
            arr[i]--;
        }
    }
    op_string[index] = '\0';
    strncpy(str, op_string, str_len+1);
    
    return str;
}
