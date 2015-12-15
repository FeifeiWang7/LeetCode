public static boolean isBalancedDFS(TreeNode root){
    HashMap<TreeNode, Integer> visited = new HashMap<TreeNode, Integer>();
    LinkedList<TreeNode> stack = new LinkedList<TreeNode>();
    int path = 0;
    if( root != null ) stack.push(root);
    while( !stack.isEmpty() ){
        TreeNode top = stack.peek();
        if( !visited.containsKey(top) ){
            visited.put(top, ++path);
            if( top.right != null && !visited.containsKey(top.right) ) stack.push(top.right);
            if( top.left  != null && !visited.containsKey(top.left ) ) stack.push(top.left);
        } else {
            int leftLevel  = top.left  == null? path: visited.get(top.left);
            int rightLevel = top.right == null? path: visited.get(top.right);
            if( Math.abs(leftLevel-rightLevel) > 1 ) return false;
            else visited.put(top, Math.max(leftLevel, rightLevel));
            --path;
            stack.pop();
        }
    }
    return true;
}
