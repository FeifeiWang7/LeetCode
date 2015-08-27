A binary tree could be serialized either by preorder or level order traversal. Serialization means it produces the same code for the same trees and different codes for different trees. Thus, we can make use of this property to judge if two trees are the same.

Both preorder and level order traversal can be implemented by recursive or itervative way.

This might be another way to solve this problem. Not straight forward but easy as well.

/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        StringBuffer result_p = new StringBuffer();
        StringBuffer result_q = new StringBuffer();

        preOrder(p, result_p);
        preOrder(q, result_q);

        return result_p.toString().equals(result_q.toString());
    }

    public void preOrder(TreeNode root, StringBuffer result){
        if(root == null){
            result.append("#");
            return;
        }
        result.append(root.val);
        preOrder(root.left, result);
        preOrder(root.right, result);
    }
}
