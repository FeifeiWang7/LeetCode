public class Solution {

public List<List<Integer>> levelOrder(TreeNode root) {

    List<List<Integer>> result = new LinkedList<List<Integer>>();
     if(root == null){
        return result;
    }

    Queue<TreeNode> q = new LinkedList<TreeNode>();
    q.offer(root);

    while(!q.isEmpty()){
        int size = q.size();
        List<Integer> ls = new LinkedList<Integer>();

        for(int i = 0; i < size; i++){
            TreeNode node = q.poll();
            ls.add(node.val);               
            if(node.left != null){
                q.offer(node.left);
            }
            if(node.right != null){
                q.offer(node.right);
            }
        }

        result.add(ls);
    }

    return result;
}
}
