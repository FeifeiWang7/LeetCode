Use queue1 to scan current level, use queue2 to store its children, after queue 1 is empty, replace queue1 with queue2 until no children left, and add list to list. Any comment will be appreciated.

public List<List<Integer>> levelOrderBottom(TreeNode root) {
    List<List<Integer>> nodesList = new ArrayList<List<Integer>>();
    if(root==null){
        return nodesList;
    }
    LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
    queue.add(root);
    LinkedList<TreeNode> queue2 = new LinkedList<TreeNode>();
    List<Integer> list = new ArrayList<Integer>();

    while(!queue.isEmpty()){
        TreeNode node = queue.pollFirst();
        list.add(node.val);
        if(node.left!=null)
            queue2.add(node.left);
        if(node.right!=null)
            queue2.add(node.right);
        if(queue.isEmpty()){
            queue = new LinkedList<>(queue2);
            queue2.clear();
            List<Integer> l = new ArrayList<Integer>(list);
            nodesList.add(0, l);
            list.clear();
        }
    }
    return nodesList;
}
