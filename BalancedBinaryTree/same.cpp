int depth_max(TreeNode *root)
{
int ldepth,rdepth;
if(root==NULL)
    return 0;
ldepth=depth_max(root->left)+1;
rdepth=depth_max(root->right)+1;
return ldepth>rdepth?ldepth:rdepth;   
}

class Solution {
public:
bool isBalanced(TreeNode* root) {

if(root==NULL)
    return true;

if(isBalanced(root->left)&&isBalanced(root->right))
    if(abs(depth_max(root->left)-depth_max(root->right)) <=1)
        return true;
    else 
        return false;
else 
    return false;
}
};
/////
int helper(TreeNode* root, bool& res) {
    if(!root) return 0;
    int left = helper(root->left, res);
    int right = helper(root->right, res);
    if(abs(left - right) > 1) res = false;
    return left > right ? (left + 1) : (right + 1);
}

bool isBalanced(TreeNode* root) {
    if(!root) return true;
    bool ret = true;
    helper(root, ret);
    return ret;
}
