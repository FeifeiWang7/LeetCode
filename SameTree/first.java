public class Same_Tree {

public boolean isSameTree(TreeNode p, TreeNode q) {
    if (p == null || q == null) return p == q; // if they are null at the same time

    if (p.val != q.val) return false;

    return isSameTree(p.right, q.right) && isSameTree(p.left, q.left);
}
}


