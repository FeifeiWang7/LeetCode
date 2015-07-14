class Solution:
    # @return a string
    def countAndSay(self, n):
        if n == 1:
            return '1'
        x = '1'
        while n > 1:
            x = self.count(x)
            n -= 1
        return x

    def count(self,x):
        m = list(x)
        ans =[]
        m.append(None)
        i , j = 0 , 0
        while i < len(m)-1:
            j += 1
            if m[j] != m[i]:
                ans += [ j-i, m[i] ]
                i = j
        return ''.join(str(s) for s in ans)
