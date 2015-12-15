Actually we can just use code for "Binary Tree Level Order Traversal" and 1) add a list reverse at the end, or 2) change "append at end" to "insert from front"

from collections import deque
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
        traversal, queue = [], deque([root])
        while queue:
            level, num = [], len(queue)
            # just get all nodes currently in queue out
            for i in range(num):
                node = queue.popleft()
                if node:
                    level.append(node.val)
                    queue.append(node.left)
                    queue.append(node.right)
            # insert at the head
            if level:
                traversal.insert(0, level)

        return traversal
