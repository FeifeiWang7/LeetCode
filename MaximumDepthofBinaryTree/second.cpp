Well, this problem has the highest acceptance rate among all OJ problems. It has a very easy 1-line reursive solution. I am not sure whether this one can be called "DFS" so I only call it "recursive".

class Solution { 
public:
    int maxDepth(TreeNode* root) {
        return root ? 1 + max(maxDepth(root -> left), maxDepth(root -> right)) : 0;
    }
};
Well, you may also solve it using a level-order traversal (BFS) with a queue.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if (!root) return depth;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) {
            depth++;
            int n = level.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = level.front();
                level.pop();
                if (node -> left) level.push(node -> left);
                if (node -> right) level.push(node -> right);
            }
        }
        return depth; 
    } 
};
