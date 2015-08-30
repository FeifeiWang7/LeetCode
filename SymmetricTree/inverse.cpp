class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left,root->right);
        return root;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p==NULL)!=(q==NULL)) return false;
        if (p==NULL&&q==NULL) return true;
        if (p->val!=q->val) return false;
        if (isSameTree(p->left,q->left)&&isSameTree(p->right,q->right))
            return true;
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        invertTree(root->left);
        return isSameTree(root->left,root->right);
    }
};
