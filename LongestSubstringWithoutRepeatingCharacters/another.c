int lengthOfLongestSubstring(char* s) {
    int array[1000000];
    array[0] = 0;
    int index = 0;
    int max = 0;
    while(s[index] != '\0'){
        array[index + 1] = array[index] + 1;
        for(int i = index - array[index]; i < index; i ++){
            if(s[index] != s[i]){
                continue;
            }else{
                array[index + 1] = index - i;
                break;
            }
        }
        if(max < array[index + 1])
            max = array[index + 1];
        index ++;
    }
    return max;
}
///
int lengthOfLongestSubstring(char* s) {
    int longest = 0, currentLength = 0, start = 0, position[128] = {0};
    for(int i = 0; s[i]; position[s[i]] = ++i, currentLength++) {
        if(position[s[i]] > start) {
            longest = (longest > currentLength) ? longest : currentLength;
            start = position[s[i]];
            currentLength = i - position[s[i]];}}
    return (longest > currentLength) ? longest : currentLength;}

/////
int lengthOfLongestSubstring(char* s)
{
    int len=0;
    char *end=s,*temp;
    char* addressTable[128]={NULL};
    while(*end){
        temp = addressTable[*end];
        addressTable[*end]=end;
        if(temp>=s){
        len=end-s>len?end-s:len;
        s = temp+1;
        }end++;
    }
    len=end-s>len?end-s:len;
    return len;
}
