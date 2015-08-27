class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL)
            return (p == q);
        bool result = (p != NULL && q != NULL) && (p->val == q->val);
        return result && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

Rewrite to the following could be more concise:

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL)
            return (p == q);
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


Share my 0ms solution, recursive C++ code, O(1) space usage and O(n) time complexity

bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p == nullptr || q == nullptr ) return  p == q;
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
