# BFS + deque   
def maxDepth(self, root):
    if not root:
        return 0
    from collections import deque
    queue = deque([(root, 1)])
    while queue:
        curr, val = queue.popleft()
        if not curr.left and not curr.right and not queue:
            return val
        if curr.left:
            queue.append((curr.left, val+1))
        if curr.right:
            queue.append((curr.right, val+1))




DFS recursively and DFS with explicit stack:

# Recursively
def maxDepth1(self, root):
    if not root:
        return 0
    return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

# DFS    
def maxDepth(self, root):
    res = 0
    stack = [(root, 0)]
    while stack:
        node, level = stack.pop()
        if not node:
            res = max(res, level)
        else:
            stack.append((node.right, level+1))
            stack.append((node.left, level+1))
    return res
