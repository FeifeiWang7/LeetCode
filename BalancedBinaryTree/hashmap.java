public boolean isBalanced(TreeNode root) {
    HashMap<TreeNode, Integer> map = new HashMap<TreeNode, Integer>();
    map.put(null, 0);
    return helper(root, map);
}

private boolean helper(TreeNode root, HashMap<TreeNode, Integer> map) {
    if (root == null) return true;
    if (!helper(root.left, map) || !helper(root.right, map)) return false;
    int lh = map.get(root.left), rh = map.get(root.right);
    map.put(root, 1 + Math.max(lh, rh));
    return Math.abs(lh - rh) <= 1;
}
