public class Solution {
    public boolean isBalanced(TreeNode root) {
        return compareHeight(root,0)>=0;
    }

    public int compareHeight(TreeNode node, int h)
    {
        if(node==null) return h;
        int left_h = compareHeight(node.left,h+1);
        int right_h = compareHeight(node.right,h+1);

        return (left_h>=0 && right_h>=0 && Math.abs(left_h-right_h)<=1)?Math.max(left_h,right_h):-1;
    }
}
