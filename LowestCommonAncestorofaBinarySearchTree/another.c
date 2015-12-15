struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *lca = root;
    struct TreeNode *p_next, *q_next;;
    while(lca != NULL) {
        if(p->val > lca->val)
            p_next = lca->right;
        else if(p->val == lca->val)
            p_next = lca;
        else 
            p_next = lca->left;
        if(q->val > lca->val)
            q_next = lca->right;
        else if(q->val == lca->val)
            q_next = lca;
        else
            q_next = lca->left;
        if(p_next != q_next)
            return lca;
        lca = p_next;
    }
    return lca;
}
///
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

        if (p->val<root->val && q->val<root->val)
            return lowestCommonAncestor(root->left,p,q);
        if (p->val>root->val && q->val>root->val)
            return lowestCommonAncestor(root->right,p,q);
        return root;
    }
