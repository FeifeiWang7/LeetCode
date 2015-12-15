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
    public boolean isBalanced(TreeNode root) {
        if(helper(root)==-1) return false;
        else return true;
    }
    private int helper(TreeNode root){
        if(root==null) return 0;
        int leftH=helper(root.left);
        if(leftH==-1 ) return -1;
        int rightH=helper(root.right);
        if( rightH ==-1) return -1;

        if(Math.abs(leftH-rightH)>1) return -1;

        return 1+Math.max(leftH,rightH);

    }
}
