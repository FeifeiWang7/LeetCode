public List<List<Integer>> levelOrderBottom(TreeNode root) {
    List<List<Integer>> list = new ArrayList<>();
    traverse(list, 0 , root);
    return list;
}

private void traverse(List<List<Integer>> list, int level, TreeNode node){
    if(node == null) return;
    if(list.size() - 1 < level) list.add(0, new ArrayList<Integer>());
    list.get(list.size() - level - 1).add(node.val);
    traverse(list, level + 1, node.left);
    traverse(list, level + 1, node.right);
}
