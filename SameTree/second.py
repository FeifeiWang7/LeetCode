# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param p, a tree node
    # @param q, a tree node
    # @return a boolean
    def isSameTree(self, p, q):
        if (not p and q) or (not q and p) or (p and q and p.val != q.val):#one of p and q is None or the their have different value
            return False
        elif (not p and not q):#both p and q are None
            return True
        else:
            return (self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right))
