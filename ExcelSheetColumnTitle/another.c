char* convertToTitle(int n) {
    char *res = (char *)calloc(8, sizeof(char));
    int i = 6;
    while(n){
        res[i--] = (char)((n-1) % 26) + 'A';
        n = (n - 1) / 26;
    }
    return res+i+1;
}
