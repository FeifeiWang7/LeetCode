class Solution(object):
def compareVersion(self, version1, version2):
    """
    :type version1: str
    :type version2: str
    :rtype: int
    """
    v1 = version1.split('.')
    v2 = version2.split('.')

    i, M = 0, max(len(v1), len(v2))

    for i in range(M):
        n1 = int(v1[i]) if i < len(v1) else 0
        n2 = int(v2[i]) if i < len(v2) else 0

        if n1 != n2:
            return 1 if n1 > n2 else -1

    return 0

####
def compareVersion(self, version1, version2):
    v1, v2 = self.helper(version1), self.helper(version2)
    return 1 if v1 > v2 else (-1 if v1 < v2 else 0)

def helper(self, v):
    v = map(int, v.split("."))
    # tackle tailing 0 case: 1.0.0 vs 1
    i = len(v)-1
    while i >= 0 and v[i] == 0:
        i -= 1
    return v[:i+1]

###
def compareVersion(version1, version2):
    f1=map(lambda x: int(x) ,version1.split('.'))
    f2=map(lambda x: int(x) ,version2.split('.'))
    f1+=([0]*(len(f2)-len(f1)))
    f2+=([0]*(len(f1)-len(f2)))
    return 1 if a>b else (-1 if a<b else 0)
###
A little improvement in comprehension

def compareVersion(self, version1, version2):
    v1 = map(int, version1.split('.'))
    v2 = map(int, version2.split('.'))
    v1 += [0] * (len(v2)-len(v1))
    v2 += [0] * (len(v1)-len(v2))
    if v1 > v2:
        return 1
    if v1 < v2:
        return -1
    return 0
