class Solution {
public:
    bool isBalanced(TreeNode* root) {
        try{
            get_height(root);
            return true;
        }
        catch (UnbalancedTree& e){
            return false;
        }
    }

private:
    struct UnbalancedTree{};
    int get_height(TreeNode* root){
        if (root == NULL) return 0;
        int lh = get_height(root->left);
        int rh = get_height(root->right);
        if (lh <= rh){
            if (rh - lh>1) throw UnbalancedTree();
            return rh + 1;
        }
        else{
            if (lh - rh > 1) throw UnbalancedTree();
            return lh + 1;
        }

    }
};
