public class Solution {
public boolean isSymmetric(TreeNode root) {
    return (root==null) || helper(root.left,root.right);
}

private boolean helper(TreeNode l, TreeNode r) {
    return (l==null || r==null) ? (l==r) : ((l.val==r.val) && helper(l.left,r.right) && helper(l.right,r.left));
}
}
