pair<bool,int> helper(TreeNode* root){
    if(!root) return make_pair(true,0);
    pair<bool,int> l=helper(root->left);
    pair<bool,int> r=helper(root->right);
    return make_pair(l.first && r.first && ((abs(l.second-r.second))<=1),1+fmax(l.second,r.second));
}
bool isBalanced(TreeNode* root) {
    return helper(root).first;
}
