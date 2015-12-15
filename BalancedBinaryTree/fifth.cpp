class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(root==NULL)
            return true;
        B = true;
        H(root);
        return B;
    }
private:
    bool B;
    int H(TreeNode *root){
        if(root==NULL)
            return 0;
        int lh = H(root->left);
        if(lh==-1)
            return -1;
        int rh = H(root->right);
        if(rh==-1)
            return -1;
        B = (abs(lh-rh)<=1);
        if(!B)
            return -1;
        return max(lh,rh)+1;
    }
};
