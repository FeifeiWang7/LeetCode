Integer aux(TreeNode rt)
{
    if ( rt == null) return 0;
    Integer left = aux(rt.left),
            right = aux(rt.right);

    if ( left == null || right == null)
        return null;
    else
    {
        if ( left - right >= -1 && left - right <= 1 )
            return 1 + (left > right ? left : right);
        else
            return null;
    }
}
public boolean isBalanced(TreeNode rt) {
    return aux(rt)!=null;
}
