public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null) return false;
        if(root.right==null && root.left == null && root.val == sum) return true;
        return hasPathSum(root.left,sum-root.val) || hasPathSum(root.right,sum-root.val);
}
//////
public boolean hasPathSum(TreeNode root, int sum) {
       if(root == null){return false;}
        if(root.left == null && root.right == null && sum == root.val)return true;
        return hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val);
}

/////
public class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null)return false;
        sum = sum - root.val;
        if(root.left==null && root.right==null){
            if(sum == 0)return true;
            else return false;
        }
        return hasPathSum(root.left,sum) || hasPathSum(root.right,sum);


    }


}
