class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        for (; i < s.size() && s[i] == ' '; i++);

        if (i < s.size() && s[i] == '-' || s[i] == '+') i++;

        bool digit = false;

        for (; i < s.size() && isdigit(s[i]); i++) digit = true;

        if (i < s.size() && s[i] == '.') i++;

        for (; i < s.size() && isdigit(s[i]); i++) digit = true;

        if (i < s.size() && (s[i] == 'e' || s[i] == 'E') && digit) {
            i++;
            digit = false;
            if (i < s.size() && (s[i] == '-' || s[i] == '+')) i++;
        }

        for (; i < s.size() && isdigit(s[i]); i++) digit = true;

        for (; i < s.size() && s[i] == ' '; i++);

        return i == s.size() && digit;
    }
};
///
class Solution {
    enum State{
        BEGIN = 0,
        AFTER_OP = 1,
        INIT,
        AFTER_NUM_DOT,
        AFTER_DOT,
        AFTER_DOT_NUM,
        AFTER_E,
        AFTER_E_OP,
        AFTER_E_NUM
    };

    struct StateMachine {
        map<char, int> conToState;
        bool canEnd;
    };
public:
    bool isNumber(string s) {
        int size = s.size();
        if(size == 0) return false;

        s = deleteSpace(s);
        size = s.size();
        if(size == 0) return false;

        vector<StateMachine> stateMachines;
        initStateMachine(stateMachines);
        StateMachine curMachine = stateMachines[BEGIN];

        for(int i = 0; i < size; i ++) {
            map<char, int>::iterator iter = curMachine.conToState.find(s[i]);
            if(iter == curMachine.conToState.end()) return false;
            curMachine = stateMachines[iter->second];
        }
        if(curMachine.canEnd) return true;
        return false;
    }

    void initStateMachine(vector<StateMachine>& stateMachines) {
        for(int i = 0; i < 9; i ++) {
            StateMachine sm;
            stateMachines.push_back(sm);
        }

        batchInsert(stateMachines[BEGIN], AFTER_OP, "+-");
        batchInsert(stateMachines[BEGIN], INIT, "0123456789");
        batchInsert(stateMachines[BEGIN], AFTER_DOT, ".");
        stateMachines[BEGIN].canEnd = false;

        batchInsert(stateMachines[AFTER_OP], INIT, "0123456789");
        batchInsert(stateMachines[AFTER_OP], AFTER_DOT, ".");
        stateMachines[AFTER_OP].canEnd = false;

        batchInsert(stateMachines[INIT], AFTER_NUM_DOT, ".");
        batchInsert(stateMachines[INIT], INIT, "0123456789");
        batchInsert(stateMachines[INIT], AFTER_E, "e");
        stateMachines[INIT].canEnd = true;

        batchInsert(stateMachines[AFTER_NUM_DOT], AFTER_DOT_NUM, "0123456789");
        batchInsert(stateMachines[AFTER_NUM_DOT], AFTER_E, "e");
        stateMachines[AFTER_DOT].canEnd = true;

        batchInsert(stateMachines[AFTER_DOT], AFTER_DOT_NUM, "0123456789");
        stateMachines[AFTER_DOT].canEnd = false;

        batchInsert(stateMachines[AFTER_DOT_NUM], AFTER_DOT_NUM, "0123456789");
        batchInsert(stateMachines[AFTER_DOT_NUM], AFTER_E, "e");
        stateMachines[AFTER_DOT_NUM].canEnd = true;

        batchInsert(stateMachines[AFTER_E], AFTER_E_OP, "+-");
        batchInsert(stateMachines[AFTER_E], AFTER_E_NUM, "0123456789");
        stateMachines[AFTER_E].canEnd = false;

        batchInsert(stateMachines[AFTER_E_OP], AFTER_E_NUM, "0123456789");
        stateMachines[AFTER_E_OP].canEnd = false;

        batchInsert(stateMachines[AFTER_E_NUM], AFTER_E_NUM, "0123456789");
        stateMachines[AFTER_E_NUM].canEnd = true;
    }

    void batchInsert(StateMachine& src, int des, string cons) {
        for(int i = 0; i < cons.length(); i ++) {
            src.conToState[cons[i]] = des;
        }
    }

    string deleteSpace(string& s) {
        int i, j;
        for(i = 0; i < s.size(); i ++) {
            if(s[i] != ' ') break;
        }

        for(j = s.size() - 1; j >= 0; j --) {
            if(s[j] != ' ') break;
        }

        string res = s.substr(i, j - i + 1);
        return res;
    }
};
////
There are two possible expressions for this problem:

bs* sign d+ [dot d] [e sign d+] bs
bs* sign [d] dot d+ [e sign d+] bs
The part in [ ... ] is alternative.

class Solution {
public:
    void getBs(string& s, int& i){
        while(i<s.length() && s[i] == ' ') 
            ++i;
    }
    void getSign(string& s, int &i){
        if(i<s.length() && (s[i]=='+' || s[i]=='-'))
            i++;
    }
    bool getDigit(string& s, int&i){
        int j=i;
        while(i<s.length() && isdigit(s[i]))
            ++i;
        return (i!=j);
    }
    bool getDot(string& s, int&i){
        if(i<s.length() && s[i]=='.')
            i++;
    }
    bool getE(string& s, int&i){
        if(i<s.length() && (s[i]=='e' || s[i]=='E'))
            i++;
    }
    bool isNumber(string s) {
        int i=0;
        bool integer=false,decimal=false;
        getBs(s, i);
        getSign(s,i);
        // getBs(s,i);
        if(getDigit(s,i)){
            integer = true;
        }

        if(getDot(s,i)){
            if(getDigit(s,i)) 
                decimal = true;
        }
        if(getE(s,i)){
            getSign(s,i);
            if(!getDigit(s,i)) return false;
        }
        getBs(s,i);
        if(i!= s.length()) return false;
        if(integer == false &&  decimal==false) return false;
        return true;
    }
};
///////
bool isNumber(string s) {
    if(s.empty()) return false;
    int i=0,len=s.size(),count_point=0,count_num=0,count_e=0;
    while(i<len && s[i]==' ') ++i;
    if(i<len && (s[i]=='+' || s[i]=='-')) ++i;
    while(i<len && ((s[i]>='0' && s[i]<='9') || s[i]=='.'))
        s[i++]=='.'?++count_point:++count_num;
    if(count_point>1 || count_num<1) return false;
    if(i<len && s[i]=='e'){
        ++i;
        if(i<len && (s[i]=='+' || s[i]=='-')) ++i;
        while(i<len &&(s[i]>='0' && s[i]<='9')) {++i;++count_e;}
        if(count_e<1) return false;
    }
    while(i<len && s[i]==' ') ++i;
    return i==len;
}
////
class Solution {
    // Check if s[pos] is in `cset',if s[pos] in cset, move pos forward
    int parse_char(string &s,int &pos, const string &cset){
        if (pos < s.length() && cset.find(s[pos]) != -1){
            pos++;
            return 1;
        }
        return 0;
    }
    int parse_sig(string &s,int &pos){
        return parse_char(s,pos,"-+");
    }
    int parse_dot(string &s,int &pos){
        return parse_char(s,pos,".");
    }
    int parse_real(string &s,int &pos){
        // 1.1   1.    .1   1  are all valid
        int n1 = parse_int(s,pos);
        int n2 = parse_dot(s,pos);
        int n3 = parse_int(s,pos);
        if (n1 || (n2 && n3)) return 1;
        return 0;
    }
    int parse_e(string &s,int &pos){
        return parse_char(s,pos,"eE");
    }
    int parse_int(string &s,int &pos){
        // return 1 if at least 1 integer is consumed.
        if (parse_char(s,pos,"0123456789")){
            while (parse_char(s,pos,"0123456789")) ;
            return 1;
        }
        return 0;
    }
    int parse_space(string &s,int &pos){
        while (parse_char(s,pos," "));
        return 1;
    }
public:
    bool isNumber(string s) {
        int pos = 0;
        parse_space(s,pos);
        parse_sig(s,pos);
        if (!parse_real(s,pos)) return 0;
        if (parse_e(s,pos)){
            parse_sig(s,pos);
            if (!parse_int(s,pos))
                return 0;
        }
        parse_space(s,pos);
        return s.length() == pos;
    }
};
//////
bool isNumber(string s) {
    long PosOfPoint = 0, PosOfE = 0;
    if (s.size() == 0) return false;

    while (s[0] == ' ') s.erase(s.begin());   //get rid of white space from beginning
    while (s[s.size()-1] == ' ') s.erase(s.end()-1);  //get rid of white space from tail
    if (s[0] == '-' || s[0] == '+') s.erase(s.begin());  //get rid of '+' and '-'

    PosOfPoint = s.find('.');
    if( -1 != PosOfPoint) { //rule out "1 ." or ".  1"
        if (((PosOfPoint+1 < s.size()) && ('0' <= s[PosOfPoint+1] && s[PosOfPoint+1] <= '9') ) || 
              ((PosOfPoint-1 >= 0) && ('0' <= s[PosOfPoint-1] && s[PosOfPoint-1] <= '9')))
            s[PosOfPoint] = '0';
        else return false;
    }

    PosOfE = s.find_first_of("eE");
    if (PosOfE == s.size()-1 || PosOfE == 0) return false; //rule out "e1" or "1e"
    if (PosOfE != -1) { //rule out "e+" or "e-"
        s[PosOfE] = '0';
        if ((s[PosOfE+1] == '-' || s[PosOfE+1] == '+') && PosOfE+1 < s.size()-1) s[PosOfE+1] = '0';
    }
    //rule out "1e3.2"
    if(PosOfPoint >= 0 && PosOfE >= 0 && PosOfE < PosOfPoint) return false; 
    for (unsigned int i = 0; i < s.size(); i++)
        if (s[i] < '0' || s[i] > '9') return false;

    return true;
}
/////
bool isDig(char c){return c>='0'&&c<='9';}
bool isAlp(char c){return (c>='a'&&c<='f')||(c>='A'&&c<='F');}
bool isSgn(char c){return c=='+'||c=='-';}
bool isValid(string s){
    if(s.size()==0||isSgn(s.back())||s.back()=='e')return false;
    if(s.back()=='.'&&(s.size()==1||isSgn(s[s.size()-2])))return false;
    return true;
}
bool isNumber(string s) {
    int beg=0,end=int(s.size())-1,mode=0;
    while(s[beg]==' '&&beg<s.length())beg++;
    while(s[end]==' '&&end>=0)end--;
    if(beg>end)return false;
    s=s.substr(beg,end-beg+1);
    if(s.size()>2&&s[0]=='0'&&s[1]=='x'){
        mode=2;
        s=s.substr(2,s.size()-2);
    }
    bool fgSgn=true,fgPnt=true;
    int posE=0;
    for(int i=0;i<s.size();i++){
        if(isDig(s[i])||(mode==2&&isAlp(s[i])))fgSgn=false;
        else if(mode!=2&&fgSgn&&isSgn(s[i]))fgSgn=false;
        else if(mode!=1&&fgPnt&&s[i]=='.'){fgPnt=false; fgSgn=false;}
        else if(mode==0&&s[i]=='e'){
            fgSgn=true; mode=1; posE=i;
            if(!isValid(s.substr(0,i)))return false;
        }
        else return false;
    }
    if(!isValid(s.substr(posE,s.size()-posE)))return false;
    return true;
}
/////
The idea is to TRY go through the string and see if we can finally arrive at the end of string or not. In the middle we return false if two cases happen:

1. there is no number at all
2. after e/E there is no integer
I grouped codes into small functions and give them recognizable names so that it is easier to see the pattern:

class Solution {
public:
    bool isNumber(const char *s) {
        skipSpace(s);
        skipSign(s);
        if(!hasNumber(s)) return false; // there's no number at all so return false

        if(*s!='\0' && (*s=='e' || *s=='E')) {
            s++;
            skipSign(s);
            if(!hasInteger(s)) return false; // after e/E no integer then return false
        }
        skipSpace(s);
        return *s=='\0';
    }
private:
    void skipSpace(const char*& s) {
        while(*s!='\0' && *s==' ') s++;
    }
    void skipSign(const char*& s) {
        if(*s!='\0' && (*s=='+' || *s=='-')) s++;
    }
    // returns true if has a number like 7, 8., 9.1, 0.8, ...
    bool hasNumber(const char*& s) { 
        int len = 0;
        while(*s!='\0' && isdigit(*s)) {s++; len++;}
        if(*s!='\0' && *s=='.') s++;
        while(*s!='\0' && isdigit(*s)) {s++; len++;}
        return len!=0;
    }
    // returns true if has an integer
    bool hasInteger(const char*& s) {
        int len = 0;
        while(*s!='\0' && isdigit(*s)) {s++; len++;}
        return len!=0;
    }

};
/////
First let me talk about some requirements.

There could be unlimited space before and after number.

There could be one '+' or '-' before number.

(left).(right) The expression before or after dot could be null, but not both.

(left)e(+/-)(right)

(1) The expression before e could be a float number.

(2) The right expression must be a positive integer.

(3) Both left and right expression couldn't be null.

(4) There could be a '+' or '-' after e.

Here's the code with comments. I hope these save your time~

bool isNumber(const char *s) {
    bool left = true;
    // ignore the space before start
    while (*s == ' ') s++;

    // There could be 1 '+'/'-' before the first number
    if (*s && (*s == '+' || *s == '-')) s++;

    // the first element could be . or number, (there must be a number before e, so e is not valid)
    if (*s == '.'){
        left = false;
    }
    else if (*s < 48 || *s > 57){
        return false;
    }
    else {
        while (*s >= 48 && *s <= 57) s++;
    }

    // after first step, all the number before . or e has been processed.
    // 3 cases, all the number is over; . ; e
    if (!*s || *s == ' '){}
    // there could be a '+'/'-' after e. But after that, the remaining number must be a positive integer (no ., no e, no +-).
    else if (*s == 'e'){
        s++;
        if (*s == '+' || *s == '-') s++;
        if (!*s || *s == ' ') return false;
        while (*s >= 48 && *s <= 57) s++;
    }
    // the dot is a little bit complicated
    // (1) The left or right part of . could be null, but not both (So I used bool left to record that).
    // (2) after dot, check if left is empty, if left is empty, then the right side must be a number.
    // (3) if left is not empty, then the right side could be a number with e. Repeat the case above.
    else if (*s == '.'){
        s++;
        if ((*s < 48 || *s > 57) && !left) return false;
        while (*s >= 48 && *s <= 57) s++;
        if (*s == 'e') {
            s++;
            if (*s == '+' || *s == '-') s++;
            if (!*s || *s == ' ') return false;
            while (*s >= 48 && *s <= 57) s++;
        }
    }
    // other case return false;
    else return false;

    // deal with the space after all the number
    while (*s && *s == ' ') s++;

    // Still not end? Goodbye!
    if (*s) return false;

    // Succeed.
    return true;
}
///////
class Solution {
public:
bool isNumber(const char *s) {
    while(*s == ' ')    //trim preceding spaces
        s++;
    string str(s);
    while(str.back() == ' ')    //trim ending spaces
        str.pop_back();
    if (str.empty()) return false;
    bool dig = false;
    for (int i=0; i<str.length(); i++)
        if (isdigit(str[i]))
        {
            dig = true;
            break;
        }
    if (!dig) return false; //no actual number exists
    if (!isdigit(str.back()) && str.back()!='.')
        return false;  //only allow ending number and '.'
    stringstream ss(str);
    long double dbl;
    ss >> dbl;
    if (ss.rdstate() & stringstream::eofbit)
        return true;

    return false;
}
};
///////
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
/////////////
We can solve this problem with a dfa. In my opinion, there are 11 different statuses. For each status, there are 6 out edges at most, which are space, '+' or '-', '.' ,'e' , '0'~'9', and other characters. So, we can link these statuses by considering 6 out edges at most. Here is my solution with a DFA.

class Solution {
public:
    bool isNumber(const char *s) {
        int move[15][256]={0};

    /* 15 stands for the number of status ( 11, exactly) . 
The default next status for each status is status 0, which means an infeasible final status. 
256 stands for all the characters. 
move[i][j]=k means if the current status is i, the status will change into k if an character j appears.
The state transition table is shown as follows. */

        move[1][' '] = 1;
        move[1]['+'] = 2;
        move[1]['-'] = 2;
        move[1]['.'] = 3;
        for(int i='0';i<='9';++i)move[1][i]=4;

        move[2]['.'] = 3;
        for(int i='0';i<='9';++i)move[2][i]=4;

        for(int i='0';i<='9';++i)move[3][i]=5;

        move[4]['e'] = 6;
        move[4]['.'] = 10;
        for(int i='0';i<='9';++i)move[4][i]=4;

        move[5]['e'] = 6;
        for(int i='0';i<='9';++i)move[5][i]=5;

        move[6]['+'] = 7;
        move[6]['-'] = 7;
        for(int i='0';i<='9';++i)move[6][i]=8;

        for(int i='0';i<='9';++i)move[7][i]=8;

        for(int i='0';i<='9';++i)move[8][i]=8;

        move[10]['e'] = 6;
        for(int i='0';i<='9';++i)move[10][i]=5;

        move[10][' '] = 9;
        move[4][' '] = 9;
        move[5][' '] = 9;
        move[8][' '] = 9;
        move[9][' '] = 9;

        /* Start with status 1. And we can scan the string only once.*/
        int status = 1;
        for(int i=0;s[i]!='\0';++i)
        {
            status = move[status][s[i]];
        }

        /* statuses 10, 4, 5, 8 and 9 are feasible final statuses */
        return status==10||status==4||status==5||status==8||status==9;
    }
};
///////
The idea is pretty straightforward. A valid number is composed of the significand and the exponent (which is optional). As we go through the string, do the following things one by one:

skip the leading whitespaces;
check if the significand is valid. To do so, simply skip the leading sign and count the number of digits and the number of points. A valid significand has no more than one point and at least one digit.
check if the exponent part is valid. We do this if the significand is followed by 'e'. Simply skip the leading sign and count the number of digits. A valid exponent contain at least one digit.
skip the trailing whitespaces. We must reach the ending 0 if the string is a valid number.
=======================================================

bool isNumber(const char *s) 
{
    int i = 0;

    // skip the whilespaces
    for(; s[i] == ' '; i++) {}

    // check the significand
    if(s[i] == '+' || s[i] == '-') i++; // skip the sign if exist

    int n_nm, n_pt;
    for(n_nm=0, n_pt=0; (s[i]<='9' && s[i]>='0') || s[i]=='.'; i++)
        s[i] == '.' ? n_pt++:n_nm++;       
    if(n_pt>1 || n_nm<1) // no more than one point, at least one digit
        return false;

    // check the exponent if exist
    if(s[i] == 'e') {
        i++;
        if(s[i] == '+' || s[i] == '-') i++; // skip the sign

        int n_nm = 0;
        for(; s[i]>='0' && s[i]<='9'; i++, n_nm++) {}
        if(n_nm<1)
            return false;
    }

    // skip the trailing whitespaces
    for(; s[i] == ' '; i++) {}

    return s[i]==0;  // must reach the ending 0 of the string
}
////
This solution implement a classical old-school state machine, its advantage is that it can quickly solve any type of syntax, the disadvantage is that it can be hard to maintain.

{

class Solution {

public:

bool isNumber(const char *s) {

    _State state = STATE_BEGIN;

    do
    {
        switch(state)
        {
            case STATE_BEGIN:
                state = _testBegin(*s);
                break;

            case STATE_SIGN:
                state = _testSign(*s);
                break;

            case STATE_INTEGRAL:
                state = _testIntegral(*s);
                break;

             case STATE_DOT:
                state = _testDot(*s);
                break;

             case STATE_DOT_NO_INTEGRAL:
                state = _testDotNoIntegral(*s);
                break;

             case STATE_DECIMAL:
                state = _testDecimal(*s);
                break;

            case STATE_E:
                state = _testE(*s);
                break;

            case STATE_EXPONENTIAL:
                state = _testExponential(*s);
                break;

            case STATE_EXPONENTIAL_SIGN:
                state = _testExponentialSign(*s);
                break;

             case STATE_END:
                state = _testEnd(*s);
                break;

            default:
                assert(false);
                break;
        }
        ++s;
    }
    while( int(state) >= int(STATE_BEGIN) );

    assert(state == STATE_SUCCESS
           || state == STATE_FAILURE);

    return state == STATE_SUCCESS;
}
private:

enum _State
{
    STATE_FAILURE,
    STATE_SUCCESS,
    STATE_BEGIN,
    STATE_SIGN,
    STATE_INTEGRAL,
    STATE_DOT_NO_INTEGRAL,
    STATE_DOT,
    STATE_DOT_BEGIN,
    STATE_DECIMAL,
    STATE_E,
    STATE_EXPONENTIAL_SIGN,
    STATE_EXPONENTIAL,
    STATE_END
};

static _State _testBegin(char ch)
{
    switch(ch)
    {
        case ' ':
        case '\t':
            return STATE_BEGIN;
        case '+':
        case '-':
            return STATE_SIGN;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return STATE_INTEGRAL;
        case '.':
            return STATE_DOT_NO_INTEGRAL;
        default:
            return STATE_FAILURE;
    }
}

static _State _testSign(char ch)
{
    switch(ch)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return STATE_INTEGRAL;
        case '.':
            return STATE_DOT_NO_INTEGRAL;
        default:
            return STATE_FAILURE;
    }
}

static _State _testIntegral(char ch)
{
    switch(ch)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return STATE_INTEGRAL;
        case '.':
            return STATE_DOT;
        case 'e':
            return STATE_E;
        case ' ':
        case '\t':
            return STATE_END;
        case 0:
            return STATE_SUCCESS;
        default:
            return STATE_FAILURE;
    }
}

static _State _testDot(char ch)
{
    switch(ch)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return STATE_DECIMAL;
        case ' ':
        case '\t':
            return STATE_END;
        case 'e':
            return STATE_E;
        case 0:
            return STATE_SUCCESS;
        default:
            return STATE_FAILURE;
    }
}

static _State _testDotNoIntegral(char ch)
{
    switch(ch)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return STATE_DECIMAL;
        default:
            return STATE_FAILURE;
    }
}

static _State _testDecimal(char ch)
{
    switch(ch)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return STATE_DECIMAL;
        case 'e':
            return STATE_E;
        case ' ':
        case '\t':
            return STATE_END;
        case 0:
            return STATE_SUCCESS;
        default:
            return STATE_FAILURE;
    }
}

static _State _testE(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return STATE_EXPONENTIAL_SIGN;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return STATE_EXPONENTIAL;
        default:
            return STATE_FAILURE;
    }
}

static _State _testExponentialSign(char ch)
{
    switch(ch)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return STATE_EXPONENTIAL;
        default:
            return STATE_FAILURE;
    }
}

static _State _testExponential(char ch)
{
    switch(ch)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return STATE_EXPONENTIAL;
        case ' ':
        case '\t':
            return STATE_END;
        case 0:
            return STATE_SUCCESS;
        default:
            return STATE_FAILURE;
    }
}

static _State _testEnd(char ch)
{
    switch(ch)
    {
        case ' ':
        case '\t':
            return STATE_END;
        case 0:
            return STATE_SUCCESS;
        default:
            return STATE_FAILURE;
    }
}
}; }
//////
class Solution {


public:

    /**
     * Given a string, returns true if it describes a valid floating point
     * number.
     */
    bool isNumber(const char *s)
    {

        // We choose to describe the status diagram through an abstract model
        // in order to make the code easier to maintain in case the grammar
        // have to be changed.

        // Another nice extra is that we can have the same code checking several
        // different formats by just changing the status diagram.

        const Graph& graph = loadGraphForFloats(); // A status diagram specific
                                                   // for float numbers.

        // Executes the state machine:
        Node node = NODE_BEGIN;
        while(true)
        {
            const char CH = *s; // Current character.

            // Takes the edges for the current node:
            const Edges& edges = graph.at(int(node));

            // The first edge is reserved for the string terminator:
            auto edge_it = begin(edges);
            if (0 == CH)
            {
                assert(edge_it->first == 0);
                node = edge_it->second;
                break;
            }
            ++edge_it; // Next edge.

            // For each further edge:
            auto edge_end = end(edges);
            while(edge_it != edge_end)
            {
                // Is the current char valid for the current edge?
                if (charInside(CH, edge_it->first))
                {
                    node = edge_it->second; // Yes, pass tp the next node.
                    break;
                }
                ++edge_it; // Next edge.
            }

            // No valid edges found?
            if (edge_it == edge_end)
            {
                node = NODE_FAILURE; // The current character is invalid.
                break;
            }

            ++s; // Next character.
        }

        return node == NODE_SUCCESS;
    }

private:

    enum Node
    {
        NODE_BEGIN,
        NODE_SIGN,
        NODE_DOT,
        NODE_DIGITS,
        NODE_DOT2,
        NODE_DIGITS2,
        NODE_E,
        NODE_SIGN2,
        NODE_DIGITS3,
        NODE_END,

        NODE_FAILURE,
        NODE_SUCCESS,
    };

    typedef vector<pair<const char *, Node> > Edges; // A list of edges.
    typedef vector<Edges> Graph; // The status diagram graph.

    static const Graph& loadGraphForFloats( )
    {
        // A simbolic description of the state diagram:
        // -for each node
        //    - for each expected character
        //      - describes the next node
        static Graph graph = {
            /* BEGIN */ {
                { 0, NODE_FAILURE },
                { " \t", NODE_BEGIN },
                { "+-", NODE_SIGN },
                { ".", NODE_DOT },
                { "0123456789", NODE_DIGITS }
            },
            /* SIGN */ {
                { 0, NODE_FAILURE },
                { ".", NODE_DOT },
                { "0123456789", NODE_DIGITS }
            },
            /* DOT */ {
                { 0, NODE_FAILURE },
                { "0123456789", NODE_DIGITS2 }
            },
            /* DIGITS */ {
                { 0, NODE_SUCCESS },
                { ".", NODE_DOT2 },
                { "0123456789", NODE_DIGITS },
                { "e", NODE_E },
                { " \t", NODE_END }
            },
            /* DOT2 */ {
                { 0, NODE_SUCCESS },
                { "0123456789", NODE_DIGITS2 },
                { "e", NODE_E },
                { " \t", NODE_END }
            },
            /* DIGITS2 */ {
                { 0, NODE_SUCCESS },
                { "0123456789", NODE_DIGITS2 },
                { "e", NODE_E },
                { " \t", NODE_END }
            },
            /* E */ {
                { 0, NODE_FAILURE },
                { "+-", NODE_SIGN2 },
                { "0123456789", NODE_DIGITS3 }
            },
            /* SIGN2 */ {
                { 0, NODE_FAILURE },
                { "0123456789", NODE_DIGITS3 }
            },
            /* DIGITS3 */ {
                { 0, NODE_SUCCESS },
                { "0123456789", NODE_DIGITS3 },
                { " \t", NODE_END }
            },
            /* END */ {
                { 0, NODE_SUCCESS },
                { " \t", NODE_END }
            },
        };

        return graph;
    }

    // Is target_ch contained by str?
    static bool charInside(char target_ch, const char *str)
    {
        char ch = *str;
        while(ch != 0
              && ch != target_ch)
        {
            ++str;
            ch = *str;
        }

        return ch != 0;
    }

};

/////
class Solution {
public:
bool isNumber(const char *s) {
    bool point = false, notation = false;
    int len = strlen(s);
    int start = 0, end = len;

    for(int i = start; i < end; i++)
        if(s[i] == ' ')     start++;
        else                break;
    for(int i = end - 1; i >= 0; i--)
        if(s[i] == ' ')     end--;
        else                break;
    if(start >= end)        return false;

    if(s[start] == '+' || s[start] == '-')
        start++;

    if(s[start] == '.' && ((s[start + 1] < '0') || (s[start + 1] > '9')))
        return false;//special case  '.'

    /* this case is right in this problem
    if(s[start] > '9'|| s[start] < '0')
        return false;// in case ".0887"
    */

    if(s[start] == 'e') return false;

    for(int i = start; i < end; i++){
        if(s[i] <= '9' && s[i] >= '0')  continue;
        else if(s[i] == '.'){
            start = i + 1;// ex: 904.[4]2
            point = true;
            break;
        }
        else if(s[i] == 'e'){
            start = i + 1;
            if(s[start] == '+' || s[start] == '-')
                start++;
            notation = true;
            break;
        }
        else    return false;
    }

    if(point){
        if(start >= end)                        return true; //ex:  "90932."
        //if(s[start] > '9' || s[start] < '0')    return false;

        for(int i = start; i < end; i++){
            if(s[i] <= '9' && s[i] >= '0')  continue;
            else if(s[i] == 'e'){
                start = i + 1;
                if(s[start] == '+' || s[start] == '-')
                    start++;
                notation = true;
                break;
            }
            else    return false;
        }
    }

    if(notation){
        if(start >= end)                            return false;
        else if(s[start] > '9' || s[start] < '0')   return false;

        for(int i = start; i < end; i++)
            if(s[i] <= '9' && s[i] >= '0')  continue;
            else                            return false;
    }
    return true;
}
};
////
class Solution {
public:
    bool isNumber(string str) {
        int state=0, flag=0; // flag to judge the special case "."
        while(str[0]==' ')  str.erase(0,1);//delete the  prefix whitespace 
        while(str[str.length()-1]==' ') str.erase(str.length()-1, 1);//delete the suffix whitespace
        for(int i=0; i<str.length(); i++){
            if('0'<=str[i] && str[i]<='9'){
                flag=1;
                if(state<=2) state=2;
                else state=(state<=5)?5:7;
            }
            else if('+'==str[i] || '-'==str[i]){
                if(state==0 || state==3) state++;
                else return false;
            }
            else if('.'==str[i]){
                if(state<=2) state=6;
                else return false;
            }
            else if('e'==str[i]){
                if(flag&&(state==2 || state==6 || state==7)) state=3;
                else return false;
            }
            else return false;
        }
        return (state==2 || state==5 || (flag&&state==6) || state==7);
    }
};
////
class Solution {
public:
    bool isNumber(string s) {
        while(!s.empty() && s[0] == ' ')
        {
            s.erase(s.begin());
        }
        while (!s.empty() && s[s.size()-1] == ' ')
        {
            s.erase(s.end()-1);
        }

        if(s.empty())
        return false;

        int state = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '-' || s[i] == '+')
            {
                if(state == 0 || state == 3)
                {
                    state ++;
                }
                else
                {
                    return false;
                }
            }

            else if(s[i] == '.')
            {
                if( state == 2)
                {   
                    state = 7;
                }
                else if(state == 0|| state == 1)
                {
                    state = 6;
                }
                else
                {
                    return false;
                }

            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                if(state == 1 || state == 4 || state == 6)
                {
                    state ++;
                }
                else if(state == 0 || state == 3)
                {
                    state = state+2;
                }
            }
            else if(s[i] == 'e' || s[i] == 'E')
            {
                if(state == 2 ||  state == 7)
                {
                    state = 3;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        if(state == 2|| state == 7 || state == 5)
        return true;


        return false;

    }
};
//////
class Solution {
public:
    // can be also solved by DFA
    bool isNumber(const char *s) {
        bool has_dot = false, has_e = false, has_num = false;

        while (*s == ' ') s++;                                  // filter prefix ' '
        if (*s == '-' || *s == '+') s++;                        // filter operator '+' or '-'

        while (*s && *s != ' ') {
            if ((*s == 'e' || *s == 'E') && !has_e) {           // filter 'e'
                has_e = has_dot = true;
                if (!has_num) return false;                     // there should be a number before 'e'
                if (*(s + 1) == '-' || *(s + 1) == '+') s++;
                if (!isdigit(*(s + 1))) return false;
            } else if (*s == '.' && !has_dot) has_dot = true;
            else if (isdigit(*s)) has_num = true;
            else return false;
            s++;
        }

        while (*s) if (*s++ != ' ') return false;               // filter suffix ' '

        return has_num;
    }
};
////
This problem give me a good chance to convey the importance of good design. The problem is very vogue. The point here is not how you design a algorithm, it is how you handle all cases well. There is no a clear standard for whether is a number valid, is it .50 , 39. a legal float point number? Are there only valid formats given by the example? Is hex format such as 0x12ab legal? How about if we need to add another format such as roman number like "I, II , IV" as legal format. I found all solution are just plug logic into one function, there are lots of switch case, if else in there. It is problematic, easy for bugs, difficult to add new features, and of course, in-reusable, and here I propose a design to handle this problem easily and nicely.

First we we can give out an interface for this problem:

interface NumberValidate {

    boolean validate(String s);
}
for any string, we call validate and it return whether the given string is a valid number. Follow we can create concrete implementation for this interface, such as IntegeValidator, FloatValidator, ScienceValidator. and then using chain of responsibility design patter (from book of GOF) , chain all those validator into a list, and feed the string to each one, if there is one validator return true, then the string is a valid number.

The design has two advantages, one is easy to fix, for any corner cases or bug, we can locate the problem to specific validator, the effect of changing one validator will not sprint out to the all system, we call this as "encapsulation".

Second is easy to extend, if we need to verify hex format or roman number format , we just need to create new validator and add to the chain, we call this advantage as "close for modification open for extension".

Follow is code for the passed design:

interface NumberValidate {

    boolean validate(String s);
}

abstract class  NumberValidateTemplate implements NumberValidate{

public boolean validate(String s)
    {
        if (checkStringEmpty(s))
        {
            return false;
        }

        s = checkAndProcessHeader(s);

        if (s.length() == 0)
        {
            return false;
        }

        return doValidate(s);
    }

    private boolean checkStringEmpty(String s)
    {
        if (s.equals(""))
        {
            return true;
        }

        return false;
    }

    private String checkAndProcessHeader(String value)
    {
        value = value.trim();

        if (value.startsWith("+") || value.startsWith("-"))
        {
            value = value.substring(1);
        }


        return value;
    }



    protected abstract boolean doValidate(String s);
}

class NumberValidator implements NumberValidate {

    private ArrayList<NumberValidate> validators = new ArrayList<NumberValidate>();

    public NumberValidator()
    {
        addValidators();
    }

    private  void addValidators()
    {
        NumberValidate nv = new IntegerValidate();
        validators.add(nv);

        nv = new FloatValidate();
        validators.add(nv);

        nv = new HexValidate();
        validators.add(nv);

        nv = new SienceFormatValidate();
        validators.add(nv);
    }

    @Override
    public boolean validate(String s)
    {
        for (NumberValidate nv : validators)
        {
            if (nv.validate(s) == true)
            {
                return true;
            }
        }

        return false;
    }


}

class IntegerValidate extends NumberValidateTemplate{

    protected boolean doValidate(String integer)
    {
        for (int i = 0; i < integer.length(); i++)
        {
            if(Character.isDigit(integer.charAt(i)) == false)
            {
                return false;
            }
        }

        return true;
    }
}

class HexValidate extends NumberValidateTemplate{

    private char[] valids = new char[] {'a', 'b', 'c', 'd', 'e', 'f'};
    protected boolean doValidate(String hex)
    {
        hex = hex.toLowerCase();
        if (hex.startsWith("0x"))
        {
            hex = hex.substring(2);
        }
        else
        {
            return false;
        }

        for (int i = 0; i < hex.length(); i++)
        {
            if (Character.isDigit(hex.charAt(i)) != true && isValidChar(hex.charAt(i)) != true)
            {
                return false;
            }
        }

        return true;
    }

    private boolean isValidChar(char c)
    {
        for (int i = 0; i < valids.length; i++)
        {
            if (c == valids[i])
            {
                return true;
            }
        }

        return false;
    }
}

class SienceFormatValidate extends NumberValidateTemplate{

protected boolean doValidate(String s)
    {
        s = s.toLowerCase();
        int pos = s.indexOf("e");
        if (pos == -1)
        {
            return false;
        }

        if (s.length() == 1)
        {
            return false;
        }

        String first = s.substring(0, pos);
        String second = s.substring(pos+1, s.length());

        if (validatePartBeforeE(first) == false || validatePartAfterE(second) == false)
        {
            return false;
        }


        return true;
    }

    private boolean validatePartBeforeE(String first)
    {
        if (first.equals("") == true)
        {
            return false;
        }

        if (checkHeadAndEndForSpace(first) == false)
        {
            return false;
        }

        NumberValidate integerValidate = new IntegerValidate();
        NumberValidate floatValidate = new FloatValidate();
        if (integerValidate.validate(first) == false && floatValidate.validate(first) == false)
        {
            return false;
        }

        return true;
    }

private boolean checkHeadAndEndForSpace(String part)
    {

        if (part.startsWith(" ") ||
                part.endsWith(" "))
        {
            return false;
        }

        return true;
    }

    private boolean validatePartAfterE(String second)
    {
        if (second.equals("") == true)
        {
            return false;
        }

        if (checkHeadAndEndForSpace(second) == false)
        {
            return false;
        }

        NumberValidate integerValidate = new IntegerValidate();
        if (integerValidate.validate(second) == false)
        {
            return false;
        }

        return true;
    }
}

class FloatValidate extends NumberValidateTemplate{

   protected boolean doValidate(String floatVal)
    {
        int pos = floatVal.indexOf(".");
        if (pos == -1)
        {
            return false;
        }

        if (floatVal.length() == 1)
        {
            return false;
        }

        NumberValidate nv = new IntegerValidate();
        String first = floatVal.substring(0, pos);
        String second = floatVal.substring(pos + 1, floatVal.length());

        if (checkFirstPart(first) == true && checkFirstPart(second) == true)
        {
            return true;
        }

        return false;
    }

    private boolean checkFirstPart(String first)
    {
        if (first.equals("") == false && checkPart(first) == false)
        {
            return false;
        }

        return true;
    }

    private boolean checkPart(String part)
    {
       if (Character.isDigit(part.charAt(0)) == false ||
                Character.isDigit(part.charAt(part.length() - 1)) == false)
        {
            return false;
        }

        NumberValidate nv = new IntegerValidate();
        if (nv.validate(part) == false)
        {
            return false;
        }

        return true;
    }
}

public class Solution {
    public boolean isNumber(String s) {
        NumberValidate nv = new NumberValidator();

        return nv.validate(s);
    }
}

class Solution {
public:
    bool isNumber(string s) {
        char fsm[10][128];
        memset(fsm, 10, sizeof(fsm));
        for (char i = '0'; i <= '9'; i++) {
            fsm[0][i] = 1;
            fsm[1][i] = 1;
            fsm[2][i] = 3;
            fsm[3][i] = 3;
            fsm[5][i] = 3;
            fsm[6][i] = 1;
            fsm[7][i] = 8;
            fsm[8][i] = 8;
            fsm[2][i] = 8;
            fsm[9][i] = 8;
        }
        fsm[0][' '] = 0;
        fsm[1][' '] = 4;
        fsm[3][' '] = 4;
        fsm[4][' '] = 4;
        fsm[8][' '] = 4;
        fsm[1]['e'] = 2;
        fsm[3]['e'] = 7;
        fsm[1]['.'] = 3;
        fsm[0]['.'] = 5;
        fsm[0]['-'] = 6;
        fsm[0]['+'] = 6;
        fsm[6]['.'] = 5;
        fsm[7]['+'] = 9;
        fsm[7]['-'] = 9;
        fsm[2]['+'] = 9;
        fsm[2]['-'] = 9;
        int state = 0;
        for (auto c : s) {
            state = fsm[state][c];
            if (state > 9) {
                return false;
            }
        }
        if (state == 1 || state == 3 || state == 4 ||state == 8 ) {
            return true;
        } else {
            return false;
        }
    }
};
