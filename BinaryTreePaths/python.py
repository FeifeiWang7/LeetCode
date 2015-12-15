def binaryTreePaths(self, root):
    if not root:
        return []
    if not root.left and not root.right:
        return [str(root.val)]
    treepaths = [str(root.val)+'->'+path for path in self.binaryTreePaths(root.left)]
    treepaths += [str(root.val)+'->'+path for path in self.binaryTreePaths(root.right)]
    return treepaths
#####
def binaryTreePaths(self, root):
    if not root:
        return []
    return [str(root.val) + '->' + path
            for kid in (root.left, root.right) if kid
            for path in self.binaryTreePaths(kid)] or [str(root.val)]
###
Hi Stefan, This is the second time I have seen you using recursion in python like this, the first time was in different ways to add parenthesis, where you did:

def diffWaysToCompute(self, input):
    return [a+b if c == '+' else a-b if c == '-' else a*b
            for i, c in enumerate(input) if c in '+-*'
            for a in self.diffWaysToCompute(input[:i])
            for b in self.diffWaysToCompute(input[i+1:])] or [int(input)]
#####
def binaryTreePaths(self, root):
    def root2leaf(root):
        if not root:
            return []
        if not root.left and not root.right:
            return [[root.val]]
        if not root.right:
            return [[root.val]+item for item in root2leaf(root.left)]
        if not root.left:
            return [[root.val]+item for item in root2leaf(root.right)]
        left=root2leaf(root.left)
        right=root2leaf(root.right)
        return [[root.val]+item for item in root2leaf(root.left)]+[[root.val]+item for item in root2leaf(root.right)]

    if not root:
        return []
    t=root2leaf(root)
    res=[]
    for item in t:
        temp=str(item[0])
        if len(item)==1:
            pass
        else:
            for i in range(1,len(item)):
                temp+="->"+str(item[i])
        res.append(temp)
    return res
####
def binaryTreePaths(self, root): #56ms 
    result = []
    def getPaths(root, result, path=''):
        if not root:
            return result
        if not(root.left or root.right):
            result.append(path + `root.val`)
            return result
        getPaths(root.left, result, path + `root.val` + '->')
        getPaths(root.right, result, path + `root.val` +'->')
        return result
    return getPaths(root, result)
###
def binaryTreePaths(self, root):
    if root is None:
        return []
    answer, stack = [], [[root]]
    while stack:
        path = stack.pop()
        node = path.pop()
        path.append(str(node.val))
        if node.left is node.right is None:
            answer.append('->'.join(path))
        node.left and stack.append(path + [node.left])
        node.right and stack.append(path + [node.right])
    return answer
###
# dfs + stack
def binaryTreePaths1(self, root):
    if not root:
        return []
    res, stack = [], [(root, "")]
    while stack:
        node, ls = stack.pop()
        if not node.left and not node.right:
            res.append(ls+str(node.val))
        if node.right:
            stack.append((node.right, ls+str(node.val)+"->"))
        if node.left:
            stack.append((node.left, ls+str(node.val)+"->"))
    return res

# bfs + queue
def binaryTreePaths2(self, root):
    if not root:
        return []
    res, queue = [], collections.deque([(root, "")])
    while queue:
        node, ls = queue.popleft()
        if not node.left and not node.right:
            res.append(ls+str(node.val))
        if node.left:
            queue.append((node.left, ls+str(node.val)+"->"))
        if node.right:
            queue.append((node.right, ls+str(node.val)+"->"))
    return res

# dfs recursively
def binaryTreePaths(self, root):
    if not root:
        return []
    res = []
    self.dfs(root, "", res)
    return res

def dfs(self, root, ls, res):
    if not root.left and not root.right:
        res.append(ls+str(root.val))
    if root.left:
        self.dfs(root.left, ls+str(root.val)+"->", res)
    if root.right:
        self.dfs(root.right, ls+str(root.val)+"->", res)
###
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        if root==None:
            return []
        if root.left==None and root.right==None:
            return [str(root.val)]
        res=self.binaryTreePaths(root.left)+self.binaryTreePaths(root.right)
        return [str(root.val)+'->'+i for i in res]
###
Standard DFS solution:

class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        self.res = set() # avoid duplicate
        self.DFS(root, [])
        return list(self.res) 

    def DFS(self, root, buff):
        if not root: return # no need to process
        buff.append(root.val) # visit this node
        if root.left or root.right: # if not a leaf node
            self.DFS(root.left, buff)
            self.DFS(root.right, buff)
        else:
            self.res.add('->'.join(map(str, buff))) # leaf node, add the entire route
        buff.pop() # must erase after visiting this level
#####
class Solution(object):
lst = list()

def binaryTreePaths(self, root):
    """
    :type root: TreeNode
    :rtype: List[str]
    """
    if root is None:
        return []

    def binaryTreePathsRecur(root, s):
        if root.left is None and root.right is None:
            self.lst.append(s)
        if root.left is not None:
            sl = s + "->" + str(root.left.val)
            binaryTreePathsRecur(root.left, sl)
        if root.right is not None:
            sr = s + "->" + str(root.right.val)
            binaryTreePathsRecur(root.right, sr) 

    s = str(root.val)
    binaryTreePathsRecur(root, s)
    return self.lst




class Solution(object):

def binaryTreePaths(self, root):
    """
    :type root: TreeNode
    :rtype: List[str]
    """
    if root is None:
        return []

    lst = list()        
    def binaryTreePathsRecur(root, s):
        if root.left is None and root.right is None:
            lst.append(s)
        if root.left is not None:
            sl = s + "->" + str(root.left.val)
            binaryTreePathsRecur(root.left, sl)
        if root.right is not None:
            sr = s + "->" + str(root.right.val)
            binaryTreePathsRecur(root.right, sr) 

    s = str(root.val)
    binaryTreePathsRecur(root, s)
    return lst
The 2nd solution passed but the 1st failed, 1st shows "Input [1, 2], Output ['1', '1->2'], Expected ['1->2']", anyone knows why? I thought these two solutions are almost the same.


