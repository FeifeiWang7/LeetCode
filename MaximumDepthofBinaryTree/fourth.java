// iteration method
public int maxDepth(TreeNode root) {
    int max = 0;
    if (root == null) {return 0;}
    Stack<TreeNode> path = new Stack<>();
    Stack<Integer> sub = new Stack<>();
    path.push(root);
    sub.push(1);
    while (!path.isEmpty()) {
        TreeNode temp = path.pop();
        int tempVal = sub.pop();
        if (temp.left == null && temp.right == null) {max = Math.max(max, tempVal);}
        else {
            if (temp.left != null) {
                path.push(temp.left);
                sub.push(tempVal + 1);
            }
            if (temp.right != null) {
                path.push(temp.right);
                sub.push(tempVal + 1);
            }
        }
    }
    return max;
}
// recursion method
public int maxDepth(TreeNode root) {
    if (root == null) return 0;
    return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
}
