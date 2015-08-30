// iterative, do parent-left-right and parent-right-left simultaneously

bool isSymmetric(TreeNode* root) {
    std::stack<TreeNode*> stnl;
    std::stack<TreeNode*> stnr;
    stnl.push(root), stnr.push(root);
    TreeNode *p, *q;
    while(!stnl.empty()) {
        p=stnl.top(), q=stnr.top();
        if((!p^!q) || p && q && p->val!=q->val) break;
        stnl.pop(), stnr.pop();
        if(p && q) {
            stnl.push(p->left), stnl.push(p->right);
            stnr.push(q->right), stnr.push(q->left);
        }
    }
    return stnl.empty();
}
// recursive

class Solution {
    bool helper(TreeNode* pl, TreeNode* pr) {
        return (!pl&&!pr) || (pl&&pr) && pl->val==pr->val && helper(pl->right, pr->left) && helper(pl->left,pr->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return !root || helper(root->left,root->right);
    }
};

