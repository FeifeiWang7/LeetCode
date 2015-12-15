def depthAndBalan(self, root):
    if root is None:
        return 1, True
    leftDep, leftBal = self.depthAndBalan(root.left)
    rightDep, rightBal = self.depthAndBalan(root.right)
    curBal = abs(leftDep - rightDep) <= 1
    return max(leftDep, rightDep)+1, leftBal and rightBal and curBal

def isBalanced(self, root):
    return self.depthAndBalan(root)[1]
