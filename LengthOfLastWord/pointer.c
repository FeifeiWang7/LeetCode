int lengthOfLastWord(char* s) {
    char *start = s;
    int length = 0;
    while(*s) {
        s++;
    }
    s--;
    while(*s == ' ') {
        s--;
    }
    while(*s != ' ' && (s >= start)){
        length++;
        s--;
    }
    return length;
}
