class Solution:
    # @param {integer} rowIndex
    # @return {integer[]}
    def getRow(self, rowIndex):
        res = []
        for i in range(rowIndex+1):
            res.append(1)
            #range(start,end,step)
            for j in range(i,0,-1):
                if j==i:
                    res[j]=1
                else:
                    res[j] += res[j-1]
        return res

#####
# O(n*n) space
def getRow1(self, rowIndex):
    res = [[1 for _ in xrange(i+1)] for i in xrange(rowIndex+1)]
    for i in xrange(2, rowIndex+1):
        for j in xrange(1, i):
            res[i][j] = res[i-1][j-1] + res[i-1][j]
    return res[-1]

# O(n) space, each row from left to right
def getRow2(self, rowIndex):
    res = [1 for _ in xrange(rowIndex+1)]
    for i in xrange(2, rowIndex+1):
        pre = res[0]
        for j in xrange(1, i):
            cur = res[j]
            res[j] += pre
            pre = cur
    return res

# O(n) space, each row from right to left
def getRow(self, rowIndex):
    res = [1 for _ in xrange(rowIndex+1)]
    for i in xrange(2, rowIndex+1):
        for j in xrange(i-1, 0, -1):
            res[j] += res[j-1]
    return res

# math
def getRow(self, rowIndex):
    res = []
    for i in xrange(rowIndex+1):
        res.append(self.compute(rowIndex, i))
    return res

def compute(self, k, i):
    return math.factorial(k)/(math.factorial(i)*math.factorial(k-i))

# O(k) space
def getRow(self, rowIndex):
    res = [0] * (rowIndex+1)
    res[0] = 1
    for i in xrange(1, rowIndex+1):
        pre = res[:]
        for j in xrange(1, i+1):
            res[j] = pre[j-1] + pre[j]
    return res
