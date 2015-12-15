class Solution:
# @param {TreeNode} root
# @return {integer[][]}
def levelOrder(self, root):
    q = []
    r = []
    if not root:
        return r
    q.append((root,0))
    while q:
        node,level = q.pop(0)
        if len(r) == level:
            r.append([node.val])
        else:
            r[level].append(node.val)
        if node.left:
            q.append((node.left,level+1))
        if node.right:
            q.append((node.right,level+1))
    return r
