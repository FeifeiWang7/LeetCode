public List<List<Integer>> levelOrder(TreeNode root) {
    List<List<Integer>> result = new ArrayList<List<Integer>>();
    if(root==null) return result;
    ArrayList<TreeNode> level = new ArrayList<TreeNode>();
    level.add(root);

    while(!level.isEmpty()){
        ArrayList<Integer> values = new ArrayList<Integer>();
        for(int i=0; i<level.size(); i++){
            values.add(level.get(i).val);
        }
        result.add(values);
        ArrayList<TreeNode> nextlevel = new ArrayList<TreeNode>();
        for(int j=0 ;j<level.size(); j++){
            if(level.get(j).left!=null) nextlevel.add(level.get(j).left);
            if(level.get(j).right!=null) nextlevel.add(level.get(j).right);
        }
        level = nextlevel;
    }
    return result;
}
