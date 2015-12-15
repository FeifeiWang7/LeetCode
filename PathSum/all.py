# DFS Recursively 
def hasPathSum1(self, root, sum):
    res = []
    self.dfs(root, sum, res)
    return any(res)

def dfs(self, root, target, res):
    if root:
        if not root.left and not root.right:
            if root.val == target:
                res.append(True)
        if root.left:
            self.dfs(root.left, target-root.val, res)
        if root.right:
            self.dfs(root.right, target-root.val, res)

# DFS with stack
def hasPathSum2(self, root, sum):
    if not root:
        return False
    stack = [(root, root.val)]
    while stack:
        curr, val = stack.pop()
        if not curr.left and not curr.right:
            if val == sum:
                return True
        if curr.right:
            stack.append((curr.right, val+curr.right.val))
        if curr.left:
            stack.append((curr.left, val+curr.left.val))
    return False

# BFS with queue
def hasPathSum(self, root, sum):
    if not root:
        return False
    queue = [(root, sum-root.val)]
    while queue:
        curr, val = queue.pop(0)
        if not curr.left and not curr.right:
            if val == 0:
                return True
        if curr.left:
            queue.append((curr.left, val-curr.left.val))
        if curr.right:
            queue.append((curr.right, val-curr.right.val))
    return False


////
# Recursively 
def hasPathSum1(self, root, sum):
    if not root:
        return False
    if root and not root.left and not root.right and root.val == sum:
        return True
    return self.hasPathSum(root.left, sum-root.val) or self.hasPathSum(root.right, sum-root.val)

# DFS + stack   
def hasPathSum(self, root, sum):
    stack = [(root, sum)]
    while stack:
        node, value = stack.pop()
        if node:
            if not node.left and not node.right and node.val == value:
                return True
            stack.append((node.right, value-node.val))
            stack.append((node.left, value-node.val))
        else:
            continue
    return False




////
class Solution:
    # @param {TreeNode} root
    # @param {integer} sum
    # @return {boolean}
    def hasPathSum(self, root, sum):
        if root is None: return False
        cur_sum = sum - root.val
        if cur_sum == 0 and is_leaf(root): return True

        return self.hasPathSum(root.left, cur_sum) or \
                self.hasPathSum(root.right, cur_sum)

def is_leaf(root):
    return not root.left and not root.right
/////
def hasPathSum(self, root, sum):
    if not root:
        return False
    if not root.left and not root.right:
        if sum == root.val:
            return True
    return self.hasPathSum(root.left, sum-root.val) or self.hasPathSum(root.right, sum-root.val)
