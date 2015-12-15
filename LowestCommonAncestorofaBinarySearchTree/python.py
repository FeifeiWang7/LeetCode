class Solution(object):
def lowestCommonAncestor(self, root, p, q):
    if not root:
        return None
    #Different sides, return root
    if min(p.val,q.val) <= root.val <= max(p.val,q.val):
        return root
    if max(p.val,q.val) < root.val: # Go left
        return self.lowestCommonAncestor(root.left, p, q)
    if min(p.val,q.val) > root.val: # Go right
        return self.lowestCommonAncestor(root.right,p,q)

#####
recursive

    def lowestCommonAncestor(self, root, p, q):
    """
    :type root: TreeNode
    :type p: TreeNode
    :type q: TreeNode
    :rtype: TreeNode
    """
    if p==root or q==root or (p.val < root.val and q.val > root.val) or (q.val<root.val and p.val>root.val):
        return root.val
    elif p.val<root.val and q.val<root.val:
        return self.lowestCommonAncestor(root.left,p,q)
    else:
        return self.lowestCommonAncestor(root.right,p,q)
stack

def lowestCommonAncestor(self, root, p, q): 
    stack=[root]
    while stack:
        node=stack.pop()
        if p==node or q==node or (p.val < node.val and q.val > node.val) or (q.val<node.val and p.val>node.val):
            return node.val
        elif p.val<node.val and q.val<node.val:
            stack.append(node.left)
        else:
            stack.append(node.right)
queue

def lowestCommonAncestor(self, root, p, q):
    import Queue
    x=Queue.Queue()
    x.put(root)
    while not x.empty():
        node=x.get()
        if p==node or q==node or (p.val < node.val and q.val > node.val) or (q.val<node.val and p.val>node.val):
            return node.val
        elif p.val<node.val and q.val<node.val:
            x.put(node.left)
        else:
            x.put(node.right)
####
This solution only works when p and q are in the tree, and for this problem, it seems that's the case.

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return None
        if p==root or q==root:
            return root
        if p.val>q.val:
            p,q=q,p
        if p.val<root.val and q.val>root.val:
            return root
        if p.val>root.val:
            return self.lowestCommonAncestor(root.right, p, q)
        return self.lowestCommonAncestor(root.left, p, q)
##
def lowestCommonAncestor(self, root, p, q):
    if not root:
        return 
    # p and q are on the different side of root,
    # or at least one of them is root
    if (root.val-p.val)*(root.val-q.val)<=0:
        return root
    # both p and q are on the left side of root
    elif root.val > p.val and root.val > q.val:
        return self.lowestCommonAncestor(root.left, p, q)
    # both p and q are on the right side of root
    else:
        return self.lowestCommonAncestor(root.right, p, q)
#####
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @param {TreeNode} p
    # @param {TreeNode} q
    # @return {TreeNode}
    def lowestCommonAncestor(self, root, p, q):
        if root != None:
            if root.val not in (p.val, q.val):
                if root.val > p.val and root.val < q.val:
                    return root
                if root.val < p.val and root.val > q.val:
                    return root
                if root.val > p.val:
                    return self.lowestCommonAncestor(root.left, p, q)
                else:
                    return self.lowestCommonAncestor(root.right, p, q)
            else:
                return root
        else:
            return None
###
class Solution:
    # @param {TreeNode} root
    # @param {TreeNode} p
    # @param {TreeNode} q
    # @return {TreeNode}
    def lowestCommonAncestor(self, root, p, q):
        if not root or not p or not q:
            return None
        if (max(p.val, q.val) < root.val):
            return self.lowestCommonAncestor(root.left, p, q)
        elif (min(p.val, q.val) > root.val):
            return self.lowestCommonAncestor(root.right, p, q)
        else:
            return root
###
The best I could achive was 164 ms solution, but I saw in the stats that there is people that solved this problem in 136 ms. Can anyone share a solution faster than mine?

def lowest_common_ancestor(root, p, q):
    if p.val > q.val:
        p, q = q, p

    cur = root

    while True:
        for node in (p, q):
            if cur.val == node.val:
                return node
        if p.val < cur.val < q.val:
            return cur
        cur = cur.left if q.val < cur.val else cur.right
###
class Solution:
    # @param {TreeNode} root
    # @param {TreeNode} p
    # @param {TreeNode} q
    # @return {TreeNode}
    def lowestCommonAncestor(self, root, p, q):
        node = root
        if p == None or q == None: 
            return None
        while node:
            print node.val
            if p.val < node.val and q.val < node.val:
                node = node.left
            elif p.val > node.val and q.val > node.val:
                node = node.right
            else:
                break
        return node
###
class Solution:

def lowestCommonAncestor(self, root, p, q):
    while root:
        if root.val > p.val and root.val > q.val:
            root = root.left
        elif root.val < p.val and root.val < q.val:
            root = root.right
        else:
            return root
###
def lowestCommonAncestor(self, root, p, q):
    while root:
        if max(p.val, q.val) < root.val:
            root = root.left
        elif min(p.val, q.val) > root.val:
            root = root.right
        else:
            return root
    return None
