The following is my AC solution Binary Tree Level Order Traversal II (II). It is only one difference from Binary Tree Level Order Traversal I (I). Note that for II, we do result.add(0, level), so every time the level is added at the beginning (index 0). For I, we only change this line to result.add(level). Simple!

public class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List result = new ArrayList();
        if (root == null) {
            return result;
        }
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            ArrayList<Integer> level = new ArrayList();
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode head = queue.poll();
                level.add(head.val);
                if (head.left != null) {
                  queue.offer(head.left);
                }
                if (head.right != null) {
                    queue.offer(head.right);
                }
            }
            result.add(0, level);
        }

        return result;
    }
}
