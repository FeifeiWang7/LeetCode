# DFS
def minDepth1(self, root):
    if not root:
        return 0
    if None in [root.left, root.right]:
        return max(self.minDepth(root.left), self.minDepth(root.right)) + 1
    else:
        return min(self.minDepth(root.left), self.minDepth(root.right)) + 1

# BFS   
def minDepth(self, root):
    if not root:
        return 0
    queue = collections.deque([(root, 1)])
    while queue:
        node, level = queue.popleft()
        if node:
            if not node.left and not node.right:
                return level
            else:
                queue.append((node.left, level+1))
                queue.append((node.right, level+1))

#iterative
def minDepth(self, root):
        q = [(root,1)] if root else []
        while q:
            n, depth = q.pop(0)
            if None == n.left == n.right:
                return depth
            if n.left: q.append((n.left, depth+1))
            if n.right: q.append((n.right, depth+1))
        return 0
