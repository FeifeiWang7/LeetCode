public class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        return p != null && q != null && p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    } }


Same code for reference

public boolean isSameTree(TreeNode p, TreeNode q) {
    // base case
    if(p==null || q==null) return p==null && q==null;
    // recursion
    return p.val==q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
}
