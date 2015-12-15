class ALVNode{
    int depth;
    boolean isFirst=true;
    TreeNode left;
    TreeNode right;

    public ALVNode(TreeNode node){
        this(node,0);
    }

    public ALVNode(TreeNode node,int depth){
        this.left=node.left;
        this.right=node.right;
        this.depth=depth;
    }
}

public class Solution {
    public boolean isBalanced(TreeNode root) {
        if(root==null) return true;
        Stack<ALVNode> stack=new Stack<>();
        HashMap<TreeNode,ALVNode> map=new HashMap<>();
        ALVNode node=new ALVNode(root);
        map.put(root,node);
        do{
            stack.push(node);
            while (node.left!=null){
                map.put(node.left,node=new ALVNode(node.left));
                stack.push(node);
            }

            while (!stack.empty()){
                node=stack.pop();
                if(node.isFirst){
                    node.isFirst=false;
                    stack.push(node);
                    if(node.right!=null){
                        map.put(node.right, node = new ALVNode(node.right));
                        break;
                    }
                }else{
                    int left=node.left!=null?map.get(node.left).depth:0;
                    int right=node.right!=null?map.get(node.right).depth:0;
                    if(Math.abs(right-left)>=2) return false;
                    node.depth=Math.max(left,right)+1;
                    map.remove(node.left);
                    map.remove(node.right);
                }
            }
        }while (!stack.empty());
        return true;
    }
}
