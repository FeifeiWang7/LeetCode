class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        nums = []
        while (n != 1):
            temp = n
            sumofdigits = 0
            while temp != 0:
                sumofdigits += (temp%10)**2
                temp /= 10
            n = sumofdigits
            if n in nums:
                return False
            nums.append(n)
        return True

###
def isHappy(self, n):
    while n >=10:
        s = 0
        str_n = str(n)
        for num in str_n:
            num = int(num)
            nn = num*num
            s += nn
        n = s
    return n== 1 or n == 7
#####
class Solution(object):
    def isHappy(self, n):

        if n == 1:
            return True;

        elif n == 4: 
            return False;

        return self.isHappy(sumDigitSquares(n));

def leastSignificantDigit(num):
    return num % 10;


def hasDigitsRemaining(num):
    return (num // 10) != 0;



def sumDigitSquares(num):

    sum = 0;

    while hasDigitsRemaining(num):
        sum += leastSignificantDigit(num)**2
        num //= 10;


    sum += num**2
    return sum;
#####
class Solution(object):
    def getHappy(self, n):
        if n / 10 == 0:
            return n ** 2

        tmp = 0
        while n != 0:
            digit = n % 10
            tmp += digit ** 2
            n = n / 10
        return tmp

    def isHappy(self, n):
        history = {}
        happy = self.getHappy(n)
        while happy != 1:
            history[happy] = True
            happy = self.getHappy(happy)

            if happy in history:
                return False
        return True
###
def isHappy(self, n):
    dic = {}
    while n:
        if 1 in dic:
            return True
        if n in dic:
            return False
        dic[n] = 0
        tmp = 0
        while n:
            tmp += (n%10)**2
            n //= 10
        n = tmp
##
def isHappy(self, n):
    while n > 4:
        res = 0
        while n:
            res = res + (n % 10)**2
            n /= 10  
        n = res    
    return n == 1
We can make it more simple, but it takes 4ms langer than the method above

def isHappy(self, n):
    res = 0
    while n:
        res = res + (n % 10)**2
        n /= 10  
    n = res    
    return self.isHappy(n) if n > 4 else n ==1
###
def isHappy(self, n):
    mem = set()
    while n != 1:
        n = sum([int(i) ** 2 for i in str(n)])
        if n in mem:
            return False
        else:
            mem.add(n)
    else:
        return True
####
For every number n, judge ii: 1. if n is Happy, return True 2. if n is not Happy: 1) if n has appeared, it is a circle, the input n won't be Happy, return False 2) if n hasn't appeared, make the new computed n to be n and see what happened.

class Solution:
# @param {integer} n
# @return {boolean}
def isHappy(self, n):
    ans = []
    temp = n
    while temp != 1:
        temp = self.compute(temp)
        if temp in ans:
            return False
        else:
            ans.append(temp)

    return True

def compute(self, n):
    str_n = str(n)
    temp = 0

    for i in str_n:
        temp += int(i) ** 2

    return temp
