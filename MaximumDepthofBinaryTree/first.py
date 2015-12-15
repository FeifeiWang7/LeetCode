class Solution:
    # @param {TreeNode} root
    # @return {integer}
    def maxDepth(self, root):
        if not root:
            return 0
        return 1+max(self.maxDepth(root.left), self.maxDepth(root.right))
