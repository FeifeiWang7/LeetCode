class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL and q==NULL) return true;
        else if(p!=NULL and q!=NULL){
            if(p->val==q->val and isSameTree(p->left,q->left) and isSameTree(p->right,q->right)) {
                return true;
            }
        } else  return false;
    }
};
