Use a List as Queue, then do the BFS iteratively.

# @param root, a tree node
# @return a list of lists of integers
def levelOrderBottom(self, root):
    if root == None:
        return []
    ans = []
    cur = []
    q = [root, None]
    while len(q) > 0:
        node = q.pop(0)
        if node == None:
            if len(cur) > 0:
                ans.insert(0, cur)
                cur = []
                q.append(None)
        else:
            cur.append(node.val)
            if node.left != None:
                q.append(node.left)
            if node.right != None:
                q.append(node.right)
    return ans
Donot use Queue, use two Lists to keep the current level and next level, the do the BFS iteratively.

# @param root, a tree node
# @return a list of lists of integers
def levelOrderBottom(self, root):
    if root == None:
        return []
    ans = []
    cur = [root]
    while len(cur) > 0:
        vals = []
        next = []
        for x in cur:
            vals.append(x.val)
            if x.left != None:
                next.append(x.left)
            if x.right != None:
                next.append(x.right)
        ans.insert(0, vals)
        cur = next
    return ans
Donot use Queue, use two Lists to keep the current level and next level, the do the BFS recursively.

# @param root, a tree node
# @return a list of lists of integers
def levelOrderBottom(self, root):
    if root == None:
        return []
    ans = []
    cur = [root]
    self.traverse(ans, cur)
    return ans


def traverse(self, ans, cur):
    if len(cur) == 0:
        return

    next = []
    for x in cur:
        if x.left != None:
            next.append(x.left)
        if x.right != None:
            next.append(x.right)

    self.traverse(ans, next)

    curVal = []
    for x in cur:
        curVal.append(x.val)
    ans.append(curVal)
