public List<List<Integer>> levelOrderBottom(TreeNode root) {
    List<List<Integer>> res = new ArrayList<List<Integer>>();
    helper(root,0,res);
    return res;
}
public void helper(TreeNode root, int n, List<List<Integer>> res){
    if(root==null) return;
    if(res.size()<=n) res.add(0,new ArrayList<Integer>());
    res.get(res.size()-n-1).add(root.val);
    helper(root.left,n+1,res);
    helper(root.right,n+1,res);
}
