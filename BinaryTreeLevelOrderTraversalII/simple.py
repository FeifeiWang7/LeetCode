class Solution:
    # @param {TreeNode} root
    # @return {integer[][]}
    def levelOrderBottom(self, root):
        if root is None: return []
        levels = [[root]]
        results = []

        while levels:
            level = levels.pop()

            result_row = [node.val for node in level]
            results.insert(0, result_row)

            next_level = []
            for node in level:
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)

            if len(next_level) > 0:
                levels.append(next_level)

        return results
