public class Solution {
    public int maxDepth(TreeNode root) {
        if(root == null)
            return 0;
        int level = 0;
        Queue<TreeNode> inorder = new LinkedList<TreeNode>();
        inorder.offer(root);
        while(!inorder.isEmpty()){
            int size = inorder.size();
            level++;
            //go through one level at a time
            for(int i = 0; i < size; i++){
                TreeNode next = inorder.poll();
                if(next.left != null){
                    inorder.offer(next.left);
                }
                if(next.right != null){
                    inorder.offer(next.right);
                }
            }

        }
        return level;
    }
}
