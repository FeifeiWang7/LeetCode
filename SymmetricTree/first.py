class Solution:
    # @param {TreeNode} root
    # @return {boolean}
    def helper(self, a, b):
        if a is None and b is None:
            return True
        if a is None and b is not None:
            return False
        if a is not None and b is None:
            return False
        if a.val != b.val: 
            return False
        return self.helper(a.left, b.right) and self.helper(a.right,b.left)
    def isSymmetric(self, root):
        if root is None:
            return True
        return self.helper(root.left, root.right)
