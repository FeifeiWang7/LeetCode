public List<List> levelOrderBottom(TreeNode root) {

    List<List<Integer>> level_nodes = new ArrayList<List<Integer>>();

    if(root==null){
        return level_nodes;
    }

    Stack<List<Integer>> buffer = new Stack<List<Integer>>(); //Because we want a reversed output

    Queue<TreeNode> nodes = new LinkedList<TreeNode>();
    nodes.add(root);

    while(nodes.size()!=0){

        int level_length = nodes.size();
        List<Integer> vals = new ArrayList<Integer>();

        while(level_length!=0){
            TreeNode temp = nodes.poll();

            if(temp.left!=null)nodes.add(temp.left);
            if(temp.right!=null)nodes.add(temp.right);

            vals.add(temp.val);
            level_length--;
        }

        buffer.push(vals);
    }

    while(!buffer.empty()){
        level_nodes.add(buffer.pop());
    }

    return level_nodes;
}
