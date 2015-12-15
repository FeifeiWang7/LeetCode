public class Solution {

    void traverse(TreeNode root,List<List<Integer>> result,int height){
        if(root!=null){
            if(result.size()==height){
                result.add( new ArrayList());
            }
            result.get(height).add(root.val);

            traverse(root.left,result,height+1);
            traverse(root.right,result,height+1);

        }
    }
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if(root==null) return result;
        traverse(root,result,0);
        return result;
    }
}
