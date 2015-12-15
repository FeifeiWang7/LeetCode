My python solution using dictionary: The though is same as others, just using dictionary instead of array, the benefit is the accessing is much quicker and don't need convert the char to index.

class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        occur = {}
        i=j=k=0
        for i in s:
            if i not in occur:occur[i]=1
            else:
                occur[i]+=1
        for j in t:
            if j not in occur:return False
            else:
                occur[j]-=1
        for k in occur:
            if occur[k]>0:return False
        return True
#####
def isAnagram(self, s, t) :
    return sorted(s) == sorted(t)
#####
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        while s != '':
            if len(s) != len(t):
                return False
            tmp = s[0]
            s = s.replace(tmp, '')
            try:
                t = t.replace(tmp, '')
            except:
                return False

        if t != '':
            return False
        else:
            return True
###
def isAnagram1(self, s, t):
    dic1, dic2 = {}, {}
    for item in s:
        dic1[item] = dic1.get(item, 0) + 1
    for item in t:
        dic2[item] = dic2.get(item, 0) + 1
    return dic1 == dic2

def isAnagram2(self, s, t):
    dic1, dic2 = [0]*26, [0]*26
    for item in s:
        dic1[ord(item)-ord('a')] += 1
    for item in t:
        dic2[ord(item)-ord('a')] += 1
    return dic1 == dic2

def isAnagram3(self, s, t):
    return sorted(s) == sorted(t)
