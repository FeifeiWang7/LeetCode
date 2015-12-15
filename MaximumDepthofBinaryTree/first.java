public class Solution {
  public int maxDepth(TreeNode root) {
          return root==null?0:1+ Math.max(root.left==null?0:maxDepth(root.left),root.right==null?0:maxDepth(root.right));
  }
}
