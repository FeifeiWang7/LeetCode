public List<List<Integer>> levelOrder(TreeNode root) {
    List<List<Integer>> res = new ArrayList<>();
    if (root == null) {return res;}
    Queue<TreeNode> q = new LinkedList<>();
    Queue<Integer> level = new LinkedList<>();
    q.offer(root);
    level.offer(1);
    while (!q.isEmpty()) {
        TreeNode temp = q.poll();
        int tempLevel = level.poll();
        if (res.size() >= tempLevel) {res.get(tempLevel - 1).add(temp.val);}
        else {
            List<Integer> per = new ArrayList<>();
            per.add(temp.val);
            res.add(per);
        }
        if (temp.left != null) {q.offer(temp.left);level.offer(tempLevel + 1);}
        if (temp.right != null) {q.offer(temp.right);level.offer(tempLevel + 1);}
    }
    return res;
}
The idea is: since the question is related to the level, I think about the bfs firstly. Using a queue to store the TreeNode, and using another queue to store the level number. Once the number of level is smaller or equal to the size of result, which is the list, add the node's value to the existed list. Otherwise, create a new list, which means a new level.
