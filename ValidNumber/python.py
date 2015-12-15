class Solution:
# @param s, a string
# @return a boolean
def removeSpaces(self,s):
    n = len(s)
    i = 0
    j = n-1
    while i < n and s[i] == ' ':
        i+=1
    while j > -1 and s[j] == ' ':
        j-=1
    return s[i:j+1]

def isNumber(self, s):
    s = self.removeSpaces(s)
    n = len(s)
    if n == 0:
        return False
    i = 0
    dotFlag = False
    EFlag = False
    hasDigit = False
    hasSign = False
    while i < n:
        if s[i].isdigit():
            i+=1
            hasDigit = True
            hasSign = True
        elif not dotFlag and s[i]=='.':
            i+=1
            dotFlag = True
            hasSign = True
        elif hasDigit and not EFlag and (s[i]=='e' or s[i]=='E'):
            i+=1
            dotFlag = True
            EFlag = True
            hasDigit = False
            hasSign = False
        elif not hasDigit and not hasSign and (s[i]=='+' or s[i]=='-'):
            i+=1
            hasSign = True
        else:
            return False
    if hasDigit:
        return True
    else:
        return False
######
class Stream:
    def __init__(self, text):
        self.text = text
        self.position = 0
    def getCurr(self):
        if self.position < len(self.text):
            return self.text[self.position]
        else:
            return None
    def advance(self, n):
        self.position += n
    def getState(self):
        return self.position
    def setState(self, state):
        self.position = state

def char(c):
    def f(stream):
        if stream.getCurr() == c:
            stream.advance(1)
            return True
        else:
            return False
    return f

def parser_or(p1, p2):
    def f(stream):
        return p1(stream) or p2(stream)
    return f

def anychar(cs):
    def f(stream):
        curr = stream.getCurr()
        for c in cs:
            if c == curr:
                stream.advance(1)
                return True
        return False
    return f

def maybe(p):
    def f(stream):
        p(stream)
        return True
    return f

def many1(p):
    def f(stream):
        count = 0
        while(p(stream)):
            count += 1
        return count > 0
    return f

def many(p):
    def f(stream):
        while(p(stream)):
            pass
        return True
    return f

def digit(stream):
    curr = stream.getCurr()
    for c in "0123456789":
        if c == curr:
            stream.advance(1)
            return True
    return False

def seq(ps):
    def f(stream):
        startstate = stream.getState()
        for p in ps:
            if not p(stream):
                stream.setState(startstate)
                return False
        return True
    return f

whitespace = many(char(' '))
end = char(None)
uintP = many1(digit)
digits = many(digit)
dot = char('.')
sign = maybe(parser_or(char('-'), char('+')))
exponentPart = seq([char('e'), sign, uintP])
decimalPart  = seq([dot, digits])
floatWithDigitBefore = seq([uintP, dot, digits])
floatWithDigitAfter  = seq([digits, dot, uintP])
floatP = parser_or(floatWithDigitBefore, floatWithDigitAfter)
numberP = seq([whitespace, sign, parser_or(floatP, uintP), maybe(exponentPart), whitespace, end])

def tp(parser, text): # test parser
    stream = Stream(text)
    return parser(stream)

class Solution:
    def isNumber(self, n):
        return numberP(Stream(n))
#######
class Solution:

    digits = set(map(chr, apply(range, [ord('0'), ord('9')+1])))
    #digits = set("0123456789")

    # @param s, a string
    # @return a boolean
    def isNumber(self, s):
        r'[-+]?((\d+\.)|(\d+\.\d+)|(\.\d+)|(\d+))(e[-+]?\d+)?'
        ns = s.strip()

        def f1(x):
            '[-+]?'
            if type(x) is bool:
                return x
            else:
                if 0 == len(x):
                    return False
                else:
                    if x[0] in ('-', '+'):
                        return x[1:]
                    else:
                        return x

        def f2(x):
            '((\d+\.)|(\d+\.\d+)|(\.\d+)|(\d+))(e..'
            if type(x) is bool:
                return x
            else:
                xs = x.split('e')
                sxs = (set(xs[0]) - set('.'))
                if xs[0].count('.') < 2 and 0 < len(sxs) and sxs.issubset(self.digits) and x.count('e') < 2:
                    if len(xs) == 1:
                        return True
                    else:
                        if 0 < len(xs[1]):
                            return xs[1]
                        else:
                            return False
                else:
                    return False

        def f3(x):
            '\d+'
            if type(x)is bool:
                return x
            else:
                return (0 < len(x) and set(x).issubset(self.digits))

        return f3(f1(f2(f1(ns))))
####
class Solution:
# @param s, a string
# @return a boolean
def isNumber(self, s):
    num_s=s.strip().lower()
    (_start, _num1, _e, _signed_e, _null_point, _num_point, _num2, _num3)=range(8)
    state=_start
    for c in num_s:
        if state==_start:
            if c=='.':
                state=_null_point
            elif c=='-' or c=='+':
                state=_start
            elif ord(c)>=48 and ord(c)<=57:
                state=_num1
            else:
                return False
        elif state==_num1:
            if c=='.':
                state=_num_point
            elif c=='e':
                state=_e
            elif ord(c)>=48 and ord(c)<=57:
                state=_num1
            else:
                return False
        elif state==_null_point:
            if ord(c)>=48 and ord(c)<=57:
                state=_num2
            else:
                return False
        elif state==_num_point:
            if ord(c)>=48 and ord(c)<=57:
                state=_num2
            elif c=='e':
                state=_e
            else:
                return False
        elif state==_num2:
            if ord(c)>=48 and ord(c)<=57:
                state=_num2
            elif c=='e':
                state=_e
            else:
                return False
        elif state==_e:
            if ord(c)>=48 and ord(c)<=57:
                state=_num3
            elif c=='-' or c=='+':
                state=_signed_e
            else:
                return False
        elif state==_signed_e:
            if ord(c)>=48 and ord(c)<=57:
                state=_num3
            else:
                return False
        elif state==_num3:
            if ord(c)>=48 and ord(c)<=57:
                state=_num3
            else:
                return False
    if state==_num_point or state==_num1 or state==_num2 or state==_num3:
        return True
    else:
        return False
#####
class Solution:
    # @param {string} s
    # @return {boolean}
    def isNumber(self, s):
        s = s.strip(" ")
        if not s: return False
        return self.isUnsigned(s) or \
               (s[0] in ['-','+'] and self.isUnsigned(s[1:]))

    def isUnsigned(self, s):
        return self.isDigits(s) or self.isDecimal(s) or self.isScientific(s)

    def isDigits(self, s):
        if not s: return False
        for i in s:
            if i not in "0123456789":
                return False
        return True

    def isScientific(self, s):
        pE = s.find("e")
        if pE==-1: 
            return False 
        else:
            before = (self.isDigits(s[:pE]) or self.isDecimal(s[:pE]))
            after = self.isDigits(s[pE+1:]) or (bool(s[pE+1:]) and \
                    s[pE+1] in ['-','+'] and self.isDigits(s[pE+2:]))
            return (before and after)


    def isDecimal(self, s):
        pDot = s.find(".")
        if pDot==-1: 
            return False 
        else:
            before = self.isDigits(s[:pDot])
            after = self.isDigits(s[pDot+1:])
            return (before and after) or \
                   (not s[:pDot] and after) or \
                   (before and not s[pDot+1:])

