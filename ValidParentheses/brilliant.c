void f(char **s,bool *b) {
    char cur=0;
    if(!**s||!*b)return;
    else cur=**s;
    switch(cur) {
        case ')':
        case ']':
        case '}':
            *b=false;
            return;
    }
    while(*b&&*++*s) {
        if(')'==**s||']'==**s||'}'==**s) {
            if(**s-cur>2||**s-cur<0) *b=false;
            else cur=0;
            break;
        } else f(s,b);
    }
    if(cur)*b=false;
}
bool isValid(char* s) {
    bool b=true;
    do {
        f(&s,&b);
    }while(b&&*s++);
    return b;
}
