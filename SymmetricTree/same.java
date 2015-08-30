/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null) return true;
        return isSymmetric(root.left, root.right);
    }

    public boolean isSymmetric(TreeNode left, TreeNode right) {
        if(left == null && right == null) return true;
        if(left == null || right == null) return false;
        if(left.val != right.val) return false;
        return isSymmetric(left.left, right.right) && isSymmetric(left.right, right.left);
    }
}

/////
We all know that the best way of solving this question is to check if the the sub-tree of the root is symmetric because it is easy to make it recursive. Like followed:

public class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null) 
             return true;
        return isSymmetric(root.left, root.right);
    }

    public boolean isSymmetric(TreeNode left, TreeNode right) {
        if(left == null && right == null) 
              return true;
        if(left == null || right == null) 
              return false;
        if(left.val != right.val) 
              return false;
        return isSymmetric(left.left, right.right) && isSymmetric(left.right, right.left);
    }
}
But if we have some other functions available, like copy(TreeNode) or invert(TreeNode) or isSameTree(TreeNode, TreeNode), we can also make it relatively more simple.

public class Solution {
    public boolean isSymmetric(TreeNode root) {
        TreeNode newRoot = copy(root);
        newRoot = invertTree(newRoot);
        return isSameTree(root, newRoot);
    }
    public TreeNode invertTree(TreeNode root){
        if(root == null)
            return root;
        if(root.left == null && root.right == null)
            return root;
        else{
            TreeNode temp = root.left;
            root.left = root.right;
            root.right = temp;
            invertTree(root.left);
            invertTree(root.right);
        }
        return root;
    }
    public TreeNode copy(TreeNode root){
        if(root == null)
            return null;
        TreeNode newRoot = new TreeNode(root.val);
        newRoot.left = copy(root.left);
        newRoot.right = copy(root.right);
        return newRoot;
    }
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null)
            return true;
        else if(p != null && q != null)
            return p.val == q.val && isSameTree(p.left,q.left) && isSameTree(p.right,q.right);
        else
            return false;
    }
}
Maybe it's long and ugly, but it is said that engineers are mostly not really good at finding a new way to solve a problem.


