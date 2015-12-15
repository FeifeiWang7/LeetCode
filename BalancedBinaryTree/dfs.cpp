class Solution {
    int balanceness(TreeNode *root) { // return depth if balanced, else -1
        if(!root) return 0;
        int ld=balanceness(root->left);
        if(ld>=0) {
            int rd=balanceness(root->right);
            if(rd>=0 && std::abs(ld-rd)<2) return 1+std::max(ld,rd);
        }
        return -1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return balanceness(root)>=0;
    }
};
