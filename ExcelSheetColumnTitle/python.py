class Solution:
# @param {integer} n
# @return {string}
    def convertToTitle(self, n):
        result = ''
        if n > 26:
            result = self.convertToTitle((n - 1)/ 26)
        result += chr(65 + (n - 1) % 26)
        return result
####recursion

#### iteration
class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = ''
        base = ord('@')
        while n:
            c = n % 26
            t = chr(c + base) if c else 'Z'
            n = (n - 1) / 26
            s = t + s
        return s

###
Conversion from 10-ary numbers to 26-ary numbers. The tricky part is the lack of the equivalent number '0' in the 26-ary system.

def convertToTitle(self, n):
    r = ''
    while(n>0):
        n -= 1
        r = chr(n%26+65) + r
        n /= 26
    return r

###
class Solution:
    # @return a string
    def convertToTitle(self, num):
        alph = ''.join(map(chr, range(65, 91)))
        return (self.convertToTitle((num-1)/len(alph)) if num>len(alph) else '' )+alph[(num-1)%len(alph)]
