class Solution {
    void _innerDepth(TreeNode* root,int depth){
        if(m <= depth || !root){
            return;
        }
        if(!root->left && !root->right && m > depth){
            m = depth;
            return;
        }

        _innerDepth(root->left,depth + 1);
        _innerDepth(root->right,depth + 1);
    }
    int m;
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        m = 0xfffffff;
        _innerDepth(root,1);

        return m;
    }
};

///bfs
int minDepth(TreeNode* root) 
{
    if (!root)
        return 0;
    int dp = 1;
    queue<TreeNode*> mp;
    mp.push(root);
    mp.push(0);
    while (!mp.empty())
    {
        TreeNode* t = mp.front();
        mp.pop();
        if (t)
        {
            if (!t->left && !t->right)
                return dp;
            if (t->left)
                mp.push(t->left);
            if (t->right)
                mp.push(t->right);
        }
        else if (!mp.empty())
        {
            mp.push(0);
            ++dp;
        }
    }
    return dp;
}

///
This problem is just similar to Minimum Depth of Binary Tree.

The first solution also uses recursion (not sure whether it can be called DFS).

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!(root -> left)) return minDepth(root -> right) + 1;
        if (!(root -> right)) return minDepth(root -> left) + 1;
        return min(minDepth(root -> left), minDepth(root -> right)) + 1;
    }
}; 
Well, the above code may be compressed into 1 line using nested conditional statements. But I tend to keep its logic clear.

The second solution adopts a level-order traversal (BFS) with a queue. We use two bool variables lt and rt to detect leaf nodes.

class Solution {
public:
    int minDepth(TreeNode* root) {
        int depth = 0;
        if (!root) return depth;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) {
            depth++;
            int n = level.size();
            for (int i = 0; i < n; i++) {
                bool lt = true, rt = true;
                TreeNode* node = level.front();
                level.pop();
                if (node -> left) level.push(node -> left);
                else lt = false;
                if (node -> right) level.push(node -> right);
                else rt = false;
                if (!lt && !rt) return depth;
            }
        }
    } 
};

