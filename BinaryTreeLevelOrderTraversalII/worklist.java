This solution is nearly identical to the traditional 'Level Order traversal' only difference is the DataStructure used to hold the data. Instead of Using an ArrayList and appending each level after the other I used a LinkedList and added each new level to the head of the LinkedList.

public class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if(root == null) return new LinkedList<List<Integer>>();
        List<List<Integer>> levels = new LinkedList<List<Integer>>();
        Queue<TreeNode> q = new LinkedList<TreeNode>(); 
        q.add(root);

        while(!q.isEmpty()){
            List<Integer> list = new ArrayList<Integer>(); 
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode node = q.remove();
                list.add(node.val);
                if(node.left != null) q.add(node.left);
                if(node.right != null) q.add(node.right);
            }
            ((LinkedList)levels).addFirst(list);
        }
        return levels;
    }
}
