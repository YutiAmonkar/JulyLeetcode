

bool isIsomorphic(char * s, char * t){
    
    char arr1[256] = {0};
    char arr2[256] = {0};
    int n1 = strlen(s);
    int n2 = strlen(t);
    int i;
    
    for(i=0;i<n2;i++){
        if((arr1[s[i]] == 0) && (arr2[t[i]]==0)){
            arr1[s[i]] = t[i];
            arr2[t[i]] = s[i];
        }
        else{
            if(arr1[s[i]] != 0){
                if(arr1[s[i]] != t[i])
                    return false;
            }
            
            if (arr2[t[i]] != 0) {
                if(arr2[t[i]] != s[i])
                    return false;
            }
        }
    }
    return true;

}