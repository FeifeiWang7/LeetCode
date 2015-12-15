class Solution {
public:
bool isBalanced(TreeNode* root) {
    solution1(root); 
    return chk;
    //return solution2(root, height); 
}
private:
bool chk = true;
int height = 0;
int solution1(TreeNode *root){
    if(root == NULL) return 0;
    int left = solution1(root->left);
    int right = 0;
    if(chk){
        right = solution1(root->right);
        if(abs(left - right) > 1) chk = false;
    }
    return max(left, right) + 1;
}
bool solution2(TreeNode *root, int &height){
    if(!root){
        height = 0;
        return true;
    }
    int left, right;
    if(!solution2(root->left, left) || !solution2(root->right, right) || abs(left - right) > 1) return false;
    height = max(left, right) + 1;
    return true;
}
};
