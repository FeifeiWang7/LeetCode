class Solution:
# @param root, a tree node
# @return a list of lists of integers
def levelOrderBottom(self, root):
    stack = []
    layer = 0
    if root is None:
        return []
    if len(stack) <= layer:
        stack.append([])
    stack[layer].append(root.val)
    def bsf(node, stack, layer):
        if node is None:
            return 
        if node is not None:
            #check if the it's a new level
            if len(stack) == layer:
                stack.append([])
            stack[layer].append(node.val)
            bsf(node.left, stack, layer+1)
            bsf(node.right, stack, layer+1)
    bsf(root.left, stack, layer+1)
    bsf(root.right, stack, layer+1)
    return stack[::-1]
