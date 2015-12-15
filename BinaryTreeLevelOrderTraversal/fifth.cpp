Here in a while loop I'm always taking from one queue (Q1), and adding to another (Q2). When Q1 queue becomes empty, I know that the level is done. IF Q2 is also empty I know that whe whole BFS traversal is done, and exit, otherwise I switch Q1 and Q2 and start iterating over next level.

public class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Deque<TreeNode> queue = new LinkedList<TreeNode>();
        Deque<TreeNode> queue2 = new LinkedList<TreeNode>();
        List<Integer> list = null;
        if (root!=null){
            queue.add(root);
            list = new ArrayList<Integer>();
            result.add(list);
        }

        while (!queue.isEmpty()) {
            TreeNode n = queue.poll();
            list.add(n.val);
            TreeNode left = n.left;
            TreeNode right = n.right;

            if (left!=null){
                queue2.add(left);
            }
            if (right!=null){
                queue2.add(right);
            }

            if (queue.isEmpty() && !queue2.isEmpty()){
                Deque<TreeNode> tmp = queue;
                queue = queue2;
                queue2 = tmp;
                list = new ArrayList<Integer>();
                result.add(list);
            }
        }
        return result;
    }
}

