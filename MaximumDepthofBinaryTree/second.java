public class Solution {

int maxDepth = 0 ;

public int maxDepth(TreeNode root) {

    searchTree(root , 1);

    return maxDepth ;

}

public void searchTree(TreeNode root , int depth){

    if(root==null)
        return ;

    if(depth > maxDepth)
        maxDepth = depth ;

    if(root.left != null) 
        searchTree(root.left, depth+1 ) ; 

    if(root.right != null)
        searchTree(root.right, depth+1 );


}
}
