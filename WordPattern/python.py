map, string = {}, str.split()
    if len(string) != len(pattern):
        return False

    for letter, word in zip(pattern, string):
        if letter not in map:
            if word in map.values():
                    return False
            map[letter] = word
        elif map[letter] != word:
            return False

    return True
###
This problem is pretty much equivalent to Isomorphic Strings. Let me reuse two old solutions.

From here:

def wordPattern(self, pattern, str):
    s = pattern
    t = str.split()
    return map(s.find, s) == map(t.index, t)
From here:

def wordPattern(self, pattern, str):
    s = pattern
    t = str.split()
    return len(set(zip(s, t))) == len(set(s)) == len(set(t))

