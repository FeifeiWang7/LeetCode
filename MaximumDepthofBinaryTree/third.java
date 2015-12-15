public class Solution {
public int maxDepth(TreeNode root) {
    Stack<TreeNode> stack=new Stack<TreeNode>();
    Stack<Integer> values=new Stack<Integer>();
    if(root==null)return 0;
    stack.push(root);
    int max=0;
    values.push(1);
    while(!stack.isEmpty()){
        TreeNode node=stack.pop();
        int value=values.pop();
        max=Math.max(value,max);
        if(node.right!=null){
            stack.push(node.right);
            values.push(value+1);
        }
        if(node.left!=null){
            stack.push(node.left);
            values.push(value+1);
        }
    }
    return max;
}
}
