class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def levelOrderBottom(self, root):
        #not allowed to reverse the list
        result = []
        if root == None:
            return result
        def bfsbottomup(result, prev):
            if prev == []:
                return
            temp = []
            cur = []
            for node in prev:
                temp.append(node.val)
                if node.left != None:
                    cur.append(node.left)
                if node.right != None:
                    cur.append(node.right)
            bfsbottomup(result, cur)
            result.append(temp)
        bfsbottomup(result, [root])
        return result
