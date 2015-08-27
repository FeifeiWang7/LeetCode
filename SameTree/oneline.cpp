bool isSameTree(TreeNode *p, TreeNode *q) {
    return !p && !q ? true : (p && q && p->val == q->val ? isSameTree(p->left, q->left) && isSameTree(p->right, q->right) : false;
}

////
1. both NULL -> true
2. same values -> recursion
3. otherwise -> false
