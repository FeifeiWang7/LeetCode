class Solution(object):
    def titleToNumber(self, s):
        res = 0
        length = len(s)

        for i, c in enumerate(s):
            res += (ord(c) - 64) * 26 ** (length - i - 1)
        return res

#####
def titleToNumber(self, s):
    res = 0
    for i in s:
        res = res*26 + ord(i)-ord('A')+1
    return res
