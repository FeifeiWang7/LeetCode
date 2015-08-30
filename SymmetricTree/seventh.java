public boolean isSymmetric(TreeNode root) {
        if(root==null) return true;
        else return areSymmetric(root.left,root.right);
    }
    public static boolean areSymmetric(TreeNode t1, TreeNode t2) {
        if(t1==null && t2==null) return true;
        if(t1==null && t2!=null) return false;
        if(t1!=null && t2== null) return false;
        return t1.val==t2.val && areSymmetric(t1.left,t2.right) && areSymmetric(t1.right,t2.left);
    }
if root is null the tree is simmetric
else check if the left subtree and the right subtree are mirrored
two subtrees are mirrored if:

they are both null
or if:

the roots have the same value AND the left subtree of t1 is mirrored to the right subtree of t2 AND the right subtree of t1 is mirrored to the left subtree of t2
