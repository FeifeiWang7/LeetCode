# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def hasPathSum(self, root, target):
        if root is None:
            return False

        nodes = [root]
        sums = [root.val]

        while nodes:
            newnodes = []
            newsums = []

            for n, s in itertools.izip(nodes, sums):
                left, right = n.left, n.right
                if left is not None:
                    newnodes.append(left)
                    newsums.append(left.val + s)
                if right is not None:
                    newnodes.append(right)
                    newsums.append(right.val + s)
                if left is None and right is None and s == target:
                    return True

            nodes = newnodes
            sums = newsums

        return False
