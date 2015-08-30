/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> sk;
        sk.push(root->left);
        sk.push(root->right);

        TreeNode* pA, *pB;
        while(!sk.empty()) {
            pA = sk.top();
            sk.pop();
            pB = sk.top();
            sk.pop();

            if(!pA && !pB) continue;
            if(!pA || !pB) return false;
            if(pA->val != pB->val) return false;

            sk.push(pA->left);
            sk.push(pB->right);
            sk.push(pA->right);
            sk.push(pB->left);
        }

        return true;
    }
};
