class Solution:
# @return a list of lists of integers
def generate(self, numRows):
    lists = []
    for i in range(numRows):
        lists.append([1]*(i+1))
        if i>1 :
            for j in range(1,i):
                lists[i][j]=lists[i-1][j-1]+lists[i-1][j]
    return lists
###

class Solution(object):
def generate(self, numRows):
    """
    :type numRows: int
    :rtype: List[List[int]]
    """
    if numRows <= 0:
        return []
    triangle = [[1]]
    for i in range(1, numRows):
        row = [0] + triangle[-1] + [0]
        triangle.append([row[j]+row[j+1] for j in range(i+1)])
    return triangle

###

class Solution(object):
    def generate(self, numRows):
        n= numRows
        if n==0: return []
        if n==1: return [[1]]
        l = [[] for i in xrange(n)]
        l[0].append(1)
        for i in xrange(1,n):
            l[i].append(1)
            for j in xrange(1, len(l[i-1])):
                l[i].append(l[i-1][j-1]+l[i-1][j])
            l[i].append(1)
        return l
