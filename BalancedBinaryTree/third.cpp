The order of the logic is important here because we want to return quickly if we find out that one of the subtrees is not balanced. This doesn't appear to matter much for these test cases, but would help for sufficiently large trees.

class Solution {
public:
    int isBalancedHeight(TreeNode* root) {
        if (!root) { return -1; }
        auto lheight = isBalancedHeight(root->left);
        if (lheight == -2) { return -2; }
        auto rheight = isBalancedHeight(root->right);
        if (rheight == -2) { return -2; }
        return abs(lheight - rheight) > 1 ? -2 : max(lheight, rheight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return isBalancedHeight(root) != -2;
    }
};
//////
class Solution {
    public:
        int height(TreeNode *root) {
            if(root == NULL)return 0;
            return max(height(root->left), height(root->right)) + 1;
        }
        bool isBalanced(TreeNode* root) {
            if(root == NULL)return true;
            return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
        }
};

/////
class Solution {
public:
    int height(TreeNode *root)
    {
        if(root == NULL) return 0;
        int hl = height(root->left);
        int hr = height(root->right);
        if (hl == -1 || hr == -1 || abs(hl - hr) > 1) return -1;
        return max(hl, hr) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return height(root) != -1;
    }
};


///
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        if (abs(depth(root->left) - depth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int depth(TreeNode *node){
      if (!node) return 0;
      return max(depth(node->left) + 1, depth(node->right) + 1);
    }
};
