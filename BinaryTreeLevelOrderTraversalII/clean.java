public List<List<Integer>> levelOrderBottom(TreeNode root) {
    List<List<Integer>> result = new ArrayList<List<Integer>>();
    if(root == null) {
        return result;
    }
    LinkedList<TreeNode> q = new LinkedList<TreeNode>();
    q.add(root);
    while(!q.isEmpty()) {
        int size = q.size(); //get size of level first
        List<Integer> list = new ArrayList<Integer>();
        for(int i=0; i < size; i++) { 
            TreeNode node = q.remove();
            list.add(node.val);
            if(node.left != null) {
                q.add(node.left);
            } 
            if(node.right != null) {
                q.add(node.right);
            }
        }
        //inserts and reverses the list
        result.add(0,list);
    }
    return result;
}
