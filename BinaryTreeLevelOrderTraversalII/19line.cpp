class Solution {
protected:
    vector<vector<int>> ans;
    void dfs(TreeNode *root, int height){
        if (root == NULL) 
            return;
        while (ans.size() <= height)
            ans.push_back(vector<int>());
        ans[height].push_back(root->val);
        dfs(root->left, height + 1);
        dfs(root->right, height + 1);
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       dfs(root, 0);
       reverse(ans.begin(), ans.end());
        return ans;    
    }
};
