def isIsomorphic(self, s,t):
    ds, dt= {}, {}
    if len(s) != len(t):
        return False
    for i in xrange(len(s)):
        if s[i] in ds:
            ds[s[i]] += [i]
        else:
            ds[s[i]] = [i]
        if t[i] in dt:
            dt[t[i]] += [i]
        else:
            dt[t[i]] = [i]
    return sorted(ds.values()) == sorted(dt.values())
###
class Solution(object):
def isIsomorphic(self, s, t):
    """
    :type s: str
    :type t: str
    :rtype: bool
    """
    s_set = set(s)
    t_set = set(t)
    if len(s_set) != len(t_set):
        return False
    else:
        if len(s) == 1:
            return True
        map_dict = {}
        for i in range(0,len(s)):
            if s[i] in map_dict:
                if map_dict[s[i]] != t[i]:
                    return False
            else:
                map_dict[s[i]] = t[i]
        return True
###
I try not to use zip but it takes 700ms :-(

class Solution(object):
def isIsomorphic(self, s, t):
    """
    :type s: str
    :type t: str
    :rtype: bool
    """
    if len(s) <= 1:
        return True
    dic1 = {}
    dic2 = {}
    for i in range(len(s)):
        if s[i] in dic1 and t[i] in dic2:
            continue
        dic1[s[i]] = t[i]
        dic2[t[i]] = s[i]
    comp1 = ''
    comp2 = ''
    for j in range(len(s)):
        comp1 += dic1[s[j]]
        comp2 += dic2[t[j]]
    return comp1 == t and comp2 == s
###
def isIsomorphic(self, s, t):
        st_map = {}
        ts_map = {}

        for i in range(len(s)):
            if s[i] not in st_map and t[i] not in ts_map:
                st_map[s[i]] = t[i]
                ts_map[t[i]] = s[i]
            elif st_map.get(s[i]) == t[i] and ts_map.get(t[i]) == s[i]:
                continue
            else:
                return False

        return True
####
def isIsomorphic1(self, s, t):
    d1, d2 = {}, {}
    for i, val in enumerate(s):
        d1[val] = d1.get(val, []) + [i]
    for i, val in enumerate(t):
        d2[val] = d2.get(val, []) + [i]
    return sorted(d1.values()) == sorted(d2.values())

def isIsomorphic2(self, s, t):
    d1, d2 = [[] for _ in xrange(256)], [[] for _ in xrange(256)]
    for i, val in enumerate(s):
        d1[ord(val)].append(i)
    for i, val in enumerate(t):
        d2[ord(val)].append(i)
    return sorted(d1) == sorted(d2)

def isIsomorphic3(self, s, t):
    return len(set(zip(s, t))) == len(set(s)) == len(set(t))

def isIsomorphic4(self, s, t): 
    return [s.find(i) for i in s] == [t.find(j) for j in t]

def isIsomorphic5(self, s, t):
    return map(s.find, s) == map(t.find, t)

def isIsomorphic(self, s, t):
    d1, d2 = [0 for _ in xrange(256)], [0 for _ in xrange(256)]
    for i in xrange(len(s)):
        if d1[ord(s[i])] != d2[ord(t[i])]:
            return False
        d1[ord(s[i])] = i+1
        d2[ord(t[i])] = i+1
    return True
###
def isIsomorphic(self, s, t):
        if s is None and t is None:
            return True
        if s == t:
            return True
        mp = {} # Dictionary to maintain mapping between the characters in both strings
        for i in range(len(s)):
            if s[i] in mp:
                if mp[s[i]] != t[i]: 
                    return False
            else:
                if t[i] in t[0:i]:
                    return False
                mp[s[i]] = t[i]
        return True
