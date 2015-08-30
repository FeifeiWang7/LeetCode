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
        //return isImageRecursive(root->left,root->right);
        return isImageIterative(root->left,root->right);
    }
private:
    bool isImageRecursive(TreeNode* a, TreeNode* b){//recursively
        if((!a)&&(!b)) return true;
        if(!(a&&b)) return false;
        return ((a->val==b->val)&&(isImageRecursive(a->left,b->right))&&(isImageRecursive(a->right,b->left)));
    }
    bool isImageIterative(TreeNode* a, TreeNode* b){//iteratively
            vector<TreeNode*> stack_a,stack_b;
            TreeNode* pCur_a = a;
            TreeNode* pCur_b = b;

            while(pCur_a || !stack_a.empty()){ 
                stack_a.push_back(pCur_a); 
                stack_b.push_back(pCur_b);
                if(!pCur_b) return false;
                if(pCur_a->val != pCur_b->val) return false;
                pCur_a = pCur_a->left; 
                if(pCur_b)
                    pCur_b = pCur_b->right;  
                else return false;
                if((!pCur_a)&&(pCur_b)) return false;
                while(!pCur_a && !stack_a.empty()){ 
                    pCur_a = stack_a.back();
                    pCur_b = stack_b.back();  
                    stack_a.pop_back();
                    stack_b.pop_back();
                    pCur_a = pCur_a->right;
                    pCur_b = pCur_b->left;
                    if((!pCur_a)&&(pCur_b)) return false;
                }
            }
            if(pCur_b) return false;
            return true;
    }
 };

Cool, I get the similar code:

 bool isSymmetric(TreeNode* root) {
            if(root==nullptr) return true;
            return recrvisSymmetric(root->left, root->right);
        }

        bool recrvisSymmetric(TreeNode* left, TreeNode* right) {
            if( left == nullptr || right == nullptr ) return left == right;
            return (left->val == right->val) && recrvisSymmetric(left->left, right->right) && recrvisSymmetric(left->right, right->left);
        }

Cool, my code ends up as almost the same as yours, one line shorter thought :P

var isSymmetric = function(root) {
    function checkLeftRight(left, right) {
        if (left === null || right === null) return left === right;
        return left.val === right.val && checkLeftRight(left.left, right.right) && checkLeftRight(left.right, right.left);
    }

    return root ? checkLeftRight(root.left, root.right) : true;
};
