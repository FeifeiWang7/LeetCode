public class Solution {
    public ArrayList<ArrayList<Integer>> levelOrderBottom(TreeNode root) {
        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
        ArrayList<ArrayList<Integer>> list2 = new ArrayList<ArrayList<Integer>>();
        if(root==null){
           return list; 
        }
        // Stack<TreeNode> stack = new Stack<TreeNode>();
        // stack.push(root);

        Queue<TreeNode> queue = new LinkedList<TreeNode>();

        queue.offer(root);

        while(!queue.isEmpty()){
            ArrayList<Integer> level = new ArrayList<Integer>();
            int size = queue.size();
            for(int i=0; i<size; i++){
                TreeNode head = queue.poll();
                level.add(head.val);
                if(head.left!=null){
                    queue.offer(head.left);
                }
                if(head.right!=null){
                    queue.offer(head.right);
                }
            }

            list2.add(level);
        }
        for(int i=list2.size()-1; i>=0; i--){
            list.add(list2.get(i));
        }

        return list;

    }
}
