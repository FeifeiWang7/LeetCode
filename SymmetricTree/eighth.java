First. We can define a binary tree by mid-order and post-order or pre-order and mid-order, the mirror tree is same to the origin tree. So we can check these two trees' mid-order and post-order are all same?

public boolean isSymmetric(TreeNode root) {
        if (root==null)
            return true;
        return getMidOrderSeq(root).equals(getReMidOrderSeq(root))&&getPostOrderSeq(root).equals(getRePostOrderSeq(root));
    }

    public String getMidOrderSeq(TreeNode node) {
        if (node == null) {
            return "";
        }
        return getMidOrderSeq(node.left) + node.val + getMidOrderSeq(node.right);
    }
    public String getReMidOrderSeq(TreeNode node) {
        if (node == null) {
            return "";
        }
        return getReMidOrderSeq(node.right) + node.val + getReMidOrderSeq(node.left);
    }
    public String getPostOrderSeq(TreeNode node) {
        if (node == null) {
            return "";
        }
        return getPostOrderSeq(node.left) +getPostOrderSeq(node.right)+ node.val ;
    }
    public String getRePostOrderSeq(TreeNode node) {
        if (node == null) {
            return "";
        }
        return getRePostOrderSeq(node.right) +getRePostOrderSeq(node.left)+ node.val ;
    }
Second. Normal recursion.

 public boolean isSymmetric(TreeNode root) {
        if (root == null)
            return true;
        return isSymmetric(root, root);

    }

    public boolean isSymmetric(TreeNode left, TreeNode right) {
        if (left == null || right == null) {
            return left == right;
        }
        return left.val == right.val && isSymmetric(left.left, right.right) && isSymmetric(left.right, right.left);
    }
Third. Iteration.

public boolean isSymmetricIter(TreeNode root) {
        if (root == null || (root.left == null && root.right == null))
            return true;
        Stack<TreeNode> leftStack = new Stack<>();
        Stack<TreeNode> rightStack = new Stack<>();
        leftStack.push(root.left);
        rightStack.push(root.right);
        while (!leftStack.isEmpty() && !rightStack.isEmpty()) {
            TreeNode left = leftStack.pop();
            TreeNode right = rightStack.pop();
            if (left == null && right == null) {
                continue;
            }
            if (left == null || right == null)
                return false;
            if (left.val != right.val)
                return false;
            leftStack.push(left.left);
            rightStack.push(right.right);
            leftStack.push(left.right);
            rightStack.push(right.left);
        }
        return true;
    }

