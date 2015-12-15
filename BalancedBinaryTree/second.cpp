/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*          TreeNode *left;
*     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
 */
      class Solution {
     int maxDepth(TreeNode* root) {
      if(root==NULL)return 0;
      if(root->left == NULL && root->right ==NULL) return 1;
      int x = maxDepth(root->left);
      int y = maxDepth(root->right);
      if(x==0)return y+1;
      if(y==0)return x+1;
      return x>y?x+1:y+1;

}
public:
   bool isBalanced(TreeNode* root) {
      if(root == NULL)return true;
      return abs(maxDepth(root->left)-maxDepth(root->right))<=1 && isBalanced(root->left) &&    isBalanced(root->right);


}
 };
I found: a tree is balance means: 1: the depth ( max depth) differ between left and right child is no bigger than 1 2: left and right child is balance tree too.
