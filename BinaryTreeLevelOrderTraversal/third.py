def levelOrder(self, root):
    res = []
    self.dfs(root, 0, res)
    return res

def dfs(self, root, level, res):
    if not root:
        return 
    if len(res) < level+1:
        res.append([])
    res[level].append(root.val)
    self.dfs(root.left, level+1, res)
    self.dfs(root.right, level+1, res)




Python solutions: DFS recursively, DFS with stack, BFS with queue.

# DFS recursively
def levelOrder1(self, root):
    res = []
    self.dfs(root, 0, res)
    return res

def dfs(self, root, level, res):
    if not root:
        return 
    if len(res) < level+1:
        res.append([])
    res[level].append(root.val)
    self.dfs(root.left, level+1, res)
    self.dfs(root.right, level+1, res)

# DFS + stack I   
def levelOrder2(self, root):
    if not root:
        return []
    res, stack = [], [(root, 0)]
    while stack:
        curr, level = stack.pop()
        if len(res) < level + 1:
            res.append([])
        res[level].append(curr.val)
        if curr.right:
            stack.append((curr.right, level+1))
        if curr.left:
            stack.append((curr.left, level+1))
    return res

# DFS + stack II  
def levelOrder3(self, root):
    res, stack = [], [(root, 0)]
    while stack:
        curr, level = stack.pop()
        if curr:
            if len(res) < level + 1:
                res.append([])
            res[level].append(curr.val)
            stack.append((curr.right, level+1))
            stack.append((curr.left, level+1))
    return res

# BFS + queue
def levelOrder4(self, root):
    res, queue = [], [(root, 0)]
    while queue:
        curr, level = queue.pop(0)
        if curr:
            if len(res) < level+1:
                res.append([])
            res[level].append(curr.val)
            queue.append((curr.left, level+1))
            queue.append((curr.right, level+1))
    return res

# BFS + deque
def levelOrder(self, root):
    from collections import deque
    res, queue = [], deque([(root, 0)])
    while queue:
        curr, level = queue.popleft()
        if curr:
            if len(res) < level+1:
                res.append([])
            res[level].append(curr.val)
            queue.append((curr.left, level+1))
            queue.append((curr.right, level+1))
    return res

