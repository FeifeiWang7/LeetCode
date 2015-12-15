# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {integer[][]}
    def levelOrderBottom(self, root):
        levels, result = [[root]], []

        while levels:
            curLevel, curValues, nextLevel = levels.pop(0), [], []
            for node in curLevel:
                if node:
                    curValues.append(node.val)
                    nextLevel += [node.left, node.right]

            if curValues:
                levels.append(nextLevel)
                result.append(curValues)

        return result[::-1]
