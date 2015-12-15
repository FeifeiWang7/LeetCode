class Solution(object):
def reverseBits(self, n):
    """
    :type n: int
    :rtype: int
    """
    newnum = 0
    l = 31
    while l >= 0:
        res = n % 2
        if res == 1:
            newnum += 2 ** l 
        n /= 2
        l -= 1
    return newnum

####
class Solution(object):
    def reverseBits(self, n):
        n = ((n & 0xFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16)
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8)
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4)
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2)
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1)
        return n
#####
class Solution(object):
def reverseBits(self, n):
    """
    :type n: int
    :rtype: int
    """
    res = []
    for i in xrange(32):
        if (n>>(i+1)) == 0:
            if n>>i == 0:
                res.append(0)
            else:
                res.append(1)
        elif (n>>i) / (n>>(i+1)) == 2 and (n>>i) % (n>>(i+1)) == 0:
            res.append(0)
        else:
            res.append(1)
    return reduce(lambda x, y: x*2 + y, res)


####
def reverseBits(self, n):
    num,initial,mul=0,str(bin(n))[2:],1
    for i in initial:
        if i =='1':
            num+=mul
        mul*=2
    num*=int(pow(2,32-len(initial)))
    return num
########
Can anyone figure out the reason of (1), (2) on the code? It's erroneous when do bit operation for Python int data type. It seems there is no unsigned int data type in Python.

def reverseBits1(self, n):
    return int(bin(n)[2:].rjust(32, '0')[::-1], 2)

def reverseBits2(self, n):
    bit = [0] * 32
    i = 0
    while n:
        bit[i] = n % 2
        n /= 2
        i += 1
    res = 0
    for i in xrange(32):
        res = res*2 + bit[i]
    return res

def reverseBits3(self, n):
    res = 0
    for i in xrange(32):
        # (1) should not be res = res<<1 + (n>>1)&1, why???
        res = res*2 + n%2
        n /= 2
    return res

def reverseBits4(self, n):
    res = 0
    for i in xrange(32):
        # (2) here "int" should not be omitted, why??? 
        res = int(res<<1) + int((n>>i)&1) 
    return res

def reverseBits(self, n):
    res = 0
    for i in xrange(32):
        res += ((n>>i)&1)*(1<<(31-i))
    return res

(1): The proper replacement for n%2 is n&1, not (n>>1)&1. And because + has higher precedence, you need parentheses: res = (res<<1) + (n&1)

(2): The "int" can be omitted. One or even both of them. I assume you also omitted the parentheses?
##########
def reverseBits(self, n):
    num=0
    for k in range(0, 32):
        num*=2 
        if (n%2==1):
            num+=1
        n/=2
    return num

#####
different mind, similar speed.

    def reverseBits(self, n):
        res,scale=0,2**31
        while n>0:
            res,scale,n=res+n%2*scale,scale/2,n/2
        return res
#######
class Solution:
    # @param n, an integer
    # @return an integer
    def __init__(self):
        self.m = None
        self._calc_reverse_map()

    def _calc_reverse_map(self):
        self.m = [0] * (2 ** 8)
        for i in range(2 ** 8):
            self.m[i] = self._reverse(i) >> 24

    def _reverse(self, n):
        res = 0
        for i in range(0, 32):
            if n & (1 << (31 - i)):
                res |= 1 << i
        return res

    def reverseBits(self, n):
        m = self.m
        return m[(n & 0xFF)] << 24 \
             | m[(n >> 8) & 0xFF] << 16 \
             | m[(n >> 16) & 0XFF] << 8 \
             | m[(n >> 24) & 0XFF]
