def levelOrder(self, root):
    res,next=[],[]
    if root:
        temp=[root]
    else:
        return res
    res.append(temp)
    while 1:
        for v in temp:
            if v.left:
                next.append(v.left)                
            if v.right:
                next.append(v.right)
        if next==[]:
            break
        res.append(next)
        temp=list(next)
        next=[]
    return [[v.val for v in x] for x in res]
