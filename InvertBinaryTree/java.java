public TreeNode invertTree(TreeNode root) {

    if(root == null) return root;

    Queue q = new LinkedList<TreeNode>();
    q.add(root);

    while(!q.isEmpty()){
        TreeNode node = (TreeNode)q.remove();
        TreeNode tempRight = null, tempLeft = null;
        if(node.right != null){
            q.add(node.right);
            tempRight = node.right; 
        } 
        if(node.left != null){
            q.add(node.left);
            tempLeft = node.left;
        }
        node.left = tempRight;  
        node.right = tempLeft;
    }

    return root;
}
