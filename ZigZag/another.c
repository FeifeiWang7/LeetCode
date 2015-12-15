char* convert(char* s, int numRows) {
    int strLen = strlen(s), counter = 0;
    char *ret = malloc((strLen+1)*(sizeof(char)));
    if(numRows == 1 || numRows >= strLen) {
        for(int i = 0; i < strLen; i++) {
            ret[i] = s[i];}}
	}
    else {
        for(int i = 1; i <= numRows; i++) {
            for(int j = i; j <= strLen; j += 2*numRows-2) {
                ret[counter++] = s[j-1];
                if(1 != i &&  i != numRows && j+2*(numRows-i) <= strLen) {
                    ret[counter++] = s[j+2*(numRows-i)-1];}}}}
    ret[strLen] = '\0';
    return ret;}
////
char* convert(char* s, int numRows) {
    int len = strlen(s);
    int n = numRows;
    char *ret = (char*)malloc(len + 1);
    int indexRet = 0;   
    int jump[2];
    int i, j, k;

    for (i=0; i < n; i++) {
        jump[0] = 2 * (n - 1 - i);
        jump[1] = 2 * i;
        if (i == 0 || i == n - 1) 
            jump[1] = jump[0] = 2 * (n - 1); 
        for (j = i,k=0; j < len; j += jump[k], k = (k + 1) % 2) {
            ret[indexRet++] = s[j];
        }   
    }
    return ret;
}
