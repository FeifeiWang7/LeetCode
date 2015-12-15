// We definitely need to calculate the height of each node
// Actually when we calculate the height, we can perform the balance check at the same time
// this help function just did this
class Solution {
private:
    bool isBalancedTreeHelper(TreeNode* root,int&depth)
    {
        if(root==NULL)
        {
            depth = 0;
            return true;
        }
        int left,right;
        // Notice, the logic operation is shortcut
        // once the left tree is judged to be unbalanced, then the right tree will not be judged
        if(isBalancedTreeHelper(root->left,left) && isBalancedTreeHelper(root->right,right) && abs(left-right)<2){
            depth = max(left,right)+1;
            return true;
        }
        return false;
    }
public:
    bool isBalanced(TreeNode* root) {
        int depth;
        return isBalancedTreeHelper(root,depth);
    }
};
