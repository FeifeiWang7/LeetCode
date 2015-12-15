/**
 * Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
  class Solution {
  void _levelOrder(queue<TreeNode*> &vc, vector<vector<int>> & res)
 {
    int n = vc.size();
    vector<int> t;
    for(int i = 0;i<n;++i)
    {
        t.push_back(vc.front()->val);
        if(vc.front()->left)vc.push(vc.front()->left);
        if(vc.front()->right)vc.push(vc.front()->right);
        vc.pop();
    }
   ///// (2)
    if(vc.size()>0)
    _levelOrder(vc, res);
    res.push_back(t);///// (1)
}

vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == NULL) return vector<vector<int>>();
    vector<vector<int>> res;
    queue<TreeNode*> vc;
    vc.push(root);
    _levelOrder(vc,res );
    return res;

}
 public:
       vector<vector<int>> levelOrderBottom(TreeNode* root) {
        return levelOrder(root);
 }
  };
actually,I just copy code from 'Binary Tree Level Order Traversal' and move code from place (2) to (1).
