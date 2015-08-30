public class Solution {
public boolean isSymmetric(TreeNode root) {
    if(root==null) return true;
    List<TreeNode> queue = new ArrayList<>();
    TreeNode left=null, right=null;
    queue.add(root);
    while(!queue.isEmpty()) {
        int len = queue.size();
        for(int i=0; i<len;) {
            left = queue.get(i);
            queue.remove(0);
            if(len<2) {
                if(left.left==null^left.right==null) return false;
                if(left.left!=null) {
                    queue.add(left.left);
                    queue.add(left.right);
                }
            } else {
                right = queue.get(i);
                queue.remove(0);
                if(left.left==null^right.right==null) return false;
                if(left.right==null^right.left==null) return false;
                if(left.val!=right.val) return false;
                if(left.left!=null) queue.add(left.left);
                if(right.right!=null) queue.add(right.right);
                if(left.right!=null) queue.add(left.right);
                if(right.left!=null) queue.add(right.left);
            }
            len-=2;
        }
    }
    return true;
}
}
