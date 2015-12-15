def levelOrder(self, root):
    if root is None:
        return []
    q = [root]
    output = []
    while len(q):
        level = []
        for x in q:
            level.append(x.val)
        output.append(level)
        q2=[]
        for x in q:
            if x.left is not None:
                q2.append(x.left)
            if x.right is not None:
                q2.append(x.right)
        q = q2
    return output
