# solutioin 1
def levelOrderBottom(self, root):
    if not root:
        return []
    level = [root]
    stack = []
    while level:
        stack.append([each.val for each in level])
        level = [node for each in level for node in (each.left, each.right) if node]
    return stack[::-1]

# solution 2
def levelOrderBottom(self, root):
    if not root:
        return []
    levels = [[root]]
    result = []
    while levels:
        curlevel = levels.pop()
        newlevel, curvalues = [], []
        for each in curlevel:
            if each:
                curvalues += [each.val]
                newlevel += [each.left, each.right]
        if curvalues:
            result.append(curvalues)
        if newlevel:
            levels.append(newlevel)
    return result[::-1]
