Each iteration, it checks whether two nodes are symmetric and then push (node1.left, node2.right), (node1.right, node2.left) to the end of queue.

class Solution:
# @param root, a tree node
# @return a boolean
def isSymmetric(self, root):
    if not root:
        return True

    dq = collections.deque([(root.left,root.right),])
    while dq:
        node1, node2 = dq.popleft()
        if not node1 and not node2:
            continue
        if not node1 or not node2:
            return False
        if node1.val != node2.val:
            return False
        # node1.left and node2.right are symmetric nodes in structure
        # node1.right and node2.left are symmetric nodes in structure
        dq.append((node1.left,node2.right))
        dq.append((node1.right,node2.left))
    return True


It seems that you don't need use deque in this case, Python queue (list) can accomplish this as well:

def isSymmetric(self, root):
    if not root:
        return True
    queue = []
    queue.append((root.left, root.right))
    while queue:
        l, r = queue.pop(0)
        if not l and not r:
            continue
        if not l or not r:
            return False
        if l.val != r.val:
            return False
        queue.append((l.left, r.right))
        queue.append((l.right, r.left))
    return True
