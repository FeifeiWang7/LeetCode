bool isNumber(const char *s) 
{
    //Check front spaces and sign
    while(*s == ' ') s++;
    if(*s == '\0') return false;
    if(*s == '-'||*s=='+') s++;

    //Check base: must contain at least one digit, before or after decimal point(if exits)
    bool flag = isdigit(*s);
    while(isdigit(*s)) s++;
    if(*s=='.')
    {
        s++;
        flag = isdigit(*s)|| flag;
        while(isdigit(*s)) s++;
    } 
    if(!flag) return false;

    //Check exponent: must contain digits
    if(*s == 'e' || *s == 'E')
    {
        s++;
        if(*s=='+'||*s=='-') s++;
        if(!isdigit(*s)) return false;
        while(isdigit(*s)) s++;
    }

    //Check trailing part
    while(*s==' ') s++;

    return *s =='\0';
}
///
bool isNumber(char *s) {
    if (!s) return false;
    while(s[0]==' ') ++s;
    while(s[strlen(s)-1]==' ') s[strlen(s)-1]='\0';
    bool canSign=true, canE=false, wasE=false, canDot=true, wasDot=false, aftE=false, wasNum=false;
    int n=strlen(s);
    for (int i=0; i<n;++i)
    {
        if ((s[i]=='+')||(s[i]=='-'))
            if (canSign)
            {
                canSign = false;
                canE = false;
            }
            else
                return false;
        else
        if ((s[i]>='0')&&(s[i]<='9'))
        {
            canSign = false;
            canDot = true;
            canE = true;
            aftE = false;
            wasNum= true;
        }
        else
        if (s[i]=='e')
            if ((!canE)||(wasE))
                return false;
            else
            {
                wasE=true;
                canSign=true;
                aftE=true;
            }
        else
        if (s[i]=='.')
        {
            if ((!canDot)||(wasDot)||(wasE))
                return false;
            else
            {
                canSign = false;
                wasDot = true;
            }
        }
        else
            return false;
    }
    return !aftE&&wasNum;
}
//
bool isNumber(char *s) {

int state = 0;

while(*(s) == ' ') s++ ;

if(*s == '+' || *s == '-')
    s++;

if(*s == '.' && *(s + 1) == '\0')
    return false ;
else if(*s == '.' && *(s + 1) == ' ')
    return false ;
else if(*s == '.' && (*(s + 1) == 'E' || *(s + 1) == 'e'))
    return false ;

while(*s != '\0')
{
     switch(state){

        case 0 :    if(isdigit(*s)) {state = 1;  s++;}
                    else if(*s == '.') {state = 2 ; s++;}
                    else if(*s == ' ') {state = 7;s++;}
                    else goto Exit ;
                    break ;
        case 1 :    if(isdigit(*s)) {state =1; s++ ;}
                    else if (*s == '.') {state =2 ; s++;}
                    else if (*s == 'E' || *s == 'e') {state =4 ; s++;}
                    else if(*s == ' ') {state = 7;s++;}
                    else goto Exit ;
                    break;
        case 2 :    if(isdigit(*s)) {state =3 ;s++;}
                    else if (*s == 'E' || *s == 'e') {state =4 ; s++;}
                    else if(*s == ' ') {state = 7;s++;}
                    else goto Exit ;
                    break;
        case 3 :    if(isdigit(*s)) {state = 3 ; s++;}
                    else if(*s == 'E' || *s == 'e') {state =4 ; s++;}
                    else if(*s == ' ') {state = 7;s++;}
                    else goto Exit;
                    break;
        case 4 :    if(isdigit(*s)) {state = 6 ; s++;}
                    else if(*s == '+' || *s == '-') {state = 5; s++;}
                    else goto Exit;
                    break;
        case 5 :    if(isdigit(*s)) {state = 6 ; s++;}
                    else if(*s == ' ') {state = 7;s++;}
                    else goto Exit;
                    break;
        case 6 :    if(isdigit(*s)) {state = 6 ; s++;}
                    else if(*s == ' ') {state = 7;s++;}
                    else goto Exit;
                    break;
        case 7 :    if(*s != ' ')  goto Exit ;
                    else    s++;
                    break ;
     }  
}

if(state == 0 ||  state == 4 || state == 5 )
    return false ;

return true;

Exit : return false ;
}

///
// /^\s*[+-]?(\.[0-9]+|[0-9]+(\.[0-9]*)?)(e[+-]?[0-9]+)?\s*$/

bool isNumber(char* s) {
    // skip white spaces
    while (*s != '\0' && *s == ' ') ++s;

    // optional sign
    if (*s == '+' || *s == '-') ++s;

    int startWithDot = 0;
    if (*s == '.') {
        startWithDot = 1;
        ++s;
    }

    // parse one or more digits
    char* s0 = s;
    while (*s != '\0' && *s >= '0' && *s <= '9') ++s;
    if (s0 == s) return false;

    // if haven't seen . yet, parse digits (zero or more) after the decimals point.
    if (startWithDot == 0 && *s == '.') {
        ++s;
        while (*s != '\0' && *s >= '0' && *s <= '9') ++s;
    }

    // parse scientfic notation
    if (*s == 'e') {
        ++s;
        if (*s == '+' || *s == '-') ++s;

        s0 = s;
        while (*s != '\0' && *s >= '0' && *s <= '9') ++s;
        if (s0 == s) return false;
    }

    // skip white spaces
    while (*s != '\0' && *s == ' ') ++s;

    return *s == '\0';
}
