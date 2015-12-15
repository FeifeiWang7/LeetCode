public class Solution { public List<List> levelOrder(TreeNode root) { if(root==null) return new ArrayList<List>();

     List<List<Integer>> result=new ArrayList<List<Integer>>();
     LinkedList<TreeNode> nodequeue=new LinkedList<TreeNode>();
     nodequeue.offer(root);
     TreeNode levellast=root;
     ArrayList<Integer> storeeachlevel=new ArrayList<Integer>();

     while(nodequeue.size()>0){
        TreeNode current=nodequeue.poll();
        storeeachlevel.add(current.val);
        if(current.left!=null) nodequeue.offer(current.left);
        if(current.right!=null) nodequeue.offer(current.right);

        if(current==levellast){
            result.add(storeeachlevel);
            storeeachlevel=new ArrayList<Integer>();
            levellast=nodequeue.peekLast();
        }

     }

     return result;
}
}
