cal the depth from the leaf to a tree node, judge if it is balanced and store it in each node.

class Solution:
    # @param {TreeNode} root
    # @return {boolean}
    def isBalanced(self, root):
        if root == None: return True
        stack = []
        p = root
        while p != None or len(stack) > 0:
            while p != None:
                    stack.append((0,p))
                    p = p.left
            lr, p = stack.pop()
            if p.right != None:
                if lr == 0:
                    stack.append((1,p))
                    p = p.right
                    continue
                r = p.right.val
            else:
                r = 0
            if p.left == None:
                l = 0
            else:
                l = p.left.val

            if (r-l) in range(-1,2):
                p.val = max(r,l)+1
                p = None
            else:
                return False

        return True
