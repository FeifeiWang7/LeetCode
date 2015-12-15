class Solution {
public:
    // idea: state translation
    enum State {I, // integer                   ->{'+','-'}[0-9]+
                D, // double                    ->Integer{'.'}[0-9]+
                E, // number with exponential   ->{D,I}{'e','E'}Integer+
                PI,// potential I               ->{'+','-'}
                PD,// potential D               ->Integer{'.'}
                PE,// potential E               ->{D,I}{'e','E'}{'+','-'}*
                F  // Fail
                };
    bool allow(char c){
        if('0' <= c && c <= '9')
            return true;
        char token[] = {'e', 'E', '.', '+', '-'};
        for(unsigned int i = 0; i < sizeof(token)/sizeof(char); ++i){
            if (c == token[i])
                return true;
        }
        return false;
    }

    bool isNumber(const char *s) {
        if(s == NULL)
            return false;
        while(*s == ' ')
            s++;
        string str(s);
        while(str.back() == ' ')
            str.pop_back();
        if(str.length() == 0)
            return false;
        bool firstDigit = false;
        for(unsigned int i = 0; i < str.length(); ++i){
            char c = str[i];
            if(!allow(c))
                return false;
            if(!firstDigit && '0' <= c && c <= '9')
                firstDigit = true;
        }
        if(!firstDigit)
            return false;
        // str.length > 0, all characters are allowed, at least one digit
        State state;
        firstDigit = false;
        // initialize state
        switch(str[0]){
            case '+':
            case '-':
                state = PI;
                break;
            case '.':
                state = PD;
                break;
            case 'e':
            case 'E':
                state = F;
                break;
            default: // [0-9]
                state = I;
                firstDigit = true;
        }

        for(unsigned int i = 1; i < str.length() && state != F; ++i){
            char c = str[i];
            if(c == '+' || c == '-'){
                switch(state){
                    case PE:
                    {
                        char prevChar = str[i-1];
                        if(prevChar != '+' || prevChar != '-')
                            state = PE;
                        else
                            state = F;
                        break;
                    }
                    default:
                        state = F;
                }
            }else if(c == 'e' || c == 'E'){
                switch(state){
                    case I:
                    case D:
                        state = PE;
                        break;
                    case PD:
                        if(firstDigit)
                            state = PE;
                        else
                            state = F;
                        break;
                    default:
                        state = F;
                }
            }else if(c == '.'){
                switch(state){
                    case I:
                    case PI:
                        state = PD;
                        break;
                    default:
                        state = F;
                }
            }else{ // c = [0-9]
                firstDigit = true;
                switch(state){
                    case I:
                    case PI:
                        state = I;
                        break;
                    case D:
                    case PD:
                        state = D;
                        break;
                    case E:
                    case PE:
                        state = E;
                }
            }
        }

        return state == I || state == D || state == PD || state == E;
    }
};

///
class Solution {
public:
      static const int INITIAL = 1;       //state 0
      static const int SIGN_INIT = 2;     //state 1
      static const int ZERO_INIT = 4;     //state 2
      static const int POS_INIT = 8;      //state 3
      static const int POINT = 16;        //state 4
      static const int DIGIT_POINT = 32;  //state 5
      static const int EXPO = 64;         //state 6
      static const int SIGN_EXPO = 128;   //state 7
      static const int DIGIT_EXPO = 256;  //state 8
      static const int INIT_POINT = 512;  //state 9
      static const int INVALID = 1024;    //wrong state
      static const int VALID = ZERO_INIT | POS_INIT | POINT | DIGIT_POINT | DIGIT_EXPO; // the valid state
 bool isNumber(const char *s) {

    int currentState = INITIAL;

    while(*s != '\0') {
        changeState(currentState, *s);
        ++ s;
        if(currentState & INVALID)
            return false;
    }
    if(currentState & VALID)
        return true;
    else
        return false;
}

void changeState(int &currentState, char ch) {
    switch(currentState) {
        case INITIAL: //state 0
            if(ch == ' ')
                currentState = INITIAL;
            else if(ch == '.')
                currentState = INIT_POINT;
            else if(ch == '+' || ch == '-')
                currentState = SIGN_INIT;
            else if(ch >= '1' && ch <= '9')
                currentState = POS_INIT;
            else if(ch == '0')
                currentState = ZERO_INIT;
            else
                currentState = INVALID;
            break;
        case SIGN_INIT: //state 1
            if(ch == '0')
                currentState = ZERO_INIT;
            else if(ch == '.')
                currentState = INIT_POINT;
            else if(ch >= '1' && ch <= '9')
                currentState = POS_INIT;
            else 
                currentState = INVALID;
            break; 
        case ZERO_INIT: //state 2 valid
            if(ch == '.') 
                currentState = POINT;
            else if(ch >= '0' && ch <= '9')
                currentState = POS_INIT;
            else if(ch == 'e' || ch == 'E')
                currentState = EXPO;
            else if(ch == ' ')
                currentState = VALID;
            else 
                currentState = INVALID;
            break;
        case POS_INIT: //state 3 valid
            if(ch == '.')
                currentState = POINT;
            else if(ch == 'e' || ch == 'E')
                currentState = EXPO;
            else if(ch >= '0' && ch <= '9')
                currentState = POS_INIT;
            else if(ch == ' ')
                currentState = VALID;
            else 
                currentState = INVALID;
            break;
        case POINT:
            if(ch >= '0' && ch <= '9')
                currentState = DIGIT_POINT;
            else if(ch == ' ')
                currentState = VALID;
            else if(ch == 'e' || ch == 'E')
                currentState = EXPO;
            else
                currentState = INVALID;
            break;
        case INIT_POINT:
            if(ch >= '0' && ch <= '9')
                currentState = DIGIT_POINT;
            else
                currentState = INVALID;
            break;
        case DIGIT_POINT: //state 5 valid
            if(ch >= '0' && ch <= '9')
                currentState = DIGIT_POINT;
            else if(ch == 'e' || ch == 'E')
                currentState = EXPO;
            else if(ch == ' ')
                currentState = VALID;
            else
                currentState = INVALID;
            break;
        case EXPO:
            if(ch == '+' || ch == '-')
                currentState = SIGN_EXPO;
            else if(ch >= '0' && ch <= '9')
                currentState = DIGIT_EXPO;
            else 
                currentState = INVALID;
            break;
        case SIGN_EXPO:
            if(ch >= '0' && ch <= '9')
                currentState = DIGIT_EXPO;
            else 
                currentState = INVALID;
            break;
        case DIGIT_EXPO:
            if(ch == ' ')
                currentState = VALID;
            else if(ch >= '0' && ch <= '9')
                currentState = DIGIT_EXPO;
            else
                currentState = INVALID;
            break;
        case VALID:
            if(ch != ' ')
                currentState = INVALID;
            break;
        default:break;
    }
}
///
bool isNumber(const char *s) {
        //remove any space at the beginning of s
        while (*s == ' ') s++;
        if (!*s) return false;
        const char *start = s;  //start is the new start of string

        //remove any space at the end of s
        while (*s) s++;
        s--;
        while (*s == ' ') s--;
        const char *end = s + 1;  //end is the new end of string

        bool hasNum = 0;  //has seen numeric number
        bool isSigned = 0;  //indicate a signed number with +/-
        bool isFloat = 0;  //indicate a float number with .
        bool isSci = 0;  //indicate a scientific representation with e
        for (const char *p = start; p != end; p++) {
            //mark a number for a numeric character
            if (*p >= '0' && *p <= '9') {
                hasNum = 1;
                continue;
            }

            //process a non-numeric number
            //+/- should only occur once for each number section 
            //and only at first position or right after e
            if (*p == '-' || *p == '+') {
                if (!isSigned && (p == start || *(p - 1) == 'e')) 
                    isSigned = 1;
                else return false;
            }
            //e should only occur once but there is at least one number before it
            else if (*p == 'e') {
                if (!isSci && hasNum) {
                    isSci = 1;
                    //reset those marks since after e a new number is coming with +/-
                    isSigned = hasNum = 0;
                }
                else return false;
            }
            //. can occur anywhere only once but not after e
            else if (*p == '.') {
                if (!isFloat && !isSci) isFloat = 1;
                else return false;
            }
            //not a number for other characters
            else return false;
        }

        //not a number if no number found after reaching the end
        if (!hasNum) return false;
        return true;
}
