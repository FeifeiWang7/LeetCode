public class Solution {
    public boolean isBalanced(TreeNode root) {
        return height(root) != -1;
    }

    int height(TreeNode root) {
        if (root == null)
            return 0;
        int left = height(root.left);
        if(left == -1)
            return -1;
        int right = height(root.right);
        if(right == -1)
            return -1;
        if(Math.abs(left - right) < 2)
            return Math.max(left, right) + 1;
        return -1;
    }
}

