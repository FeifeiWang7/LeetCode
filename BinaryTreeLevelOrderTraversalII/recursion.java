public class Solution { public List<List> levelOrderBottom(TreeNode root) {

    List<List<Integer>> ret=new LinkedList<List<Integer>>();
    if(root==null){
        return ret;
    }
    int level=0;
    recursive(root,ret,level);
    return ret;

}

public void recursive(TreeNode root, List<List<Integer>> ret,int level){
    if(root==null){
        return;
    }
    if(level>=ret.size()){
        List<Integer> newlink=new LinkedList<Integer>();
        ret.add(0,newlink);
    }
    ret.get(ret.size()-level-1).add(root.val);
    recursive(root.left,ret,level+1);
    recursive(root.right,ret,level+1);
}
}
