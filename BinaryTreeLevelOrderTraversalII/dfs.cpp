For me it's more straightforward to use DFS rather than BFS, and it's time efficiency is also good. Actually in this solution the most tricky part is to dynamically increase the size of vector (answer) but not the problem solving itself..

class Solution {
public:
    void recurFunc(TreeNode* node, int depth, vector<vector<int>>& answer)
    {
        for (auto i = answer.size(); i <= depth; ++i)
        {
            vector<int> emptyVec;
            answer.push_back(emptyVec);
        }
        answer[depth].push_back(node->val);

        if (node->left)
            recurFunc(node->left, depth+1, answer);
        if (node->right)
            recurFunc(node->right, depth+1, answer);

        return;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;

        if (root)
        {
            recurFunc(root, 0, ret);
            reverse(ret.begin(), ret.end());
        }
        return ret;
    }
};

//
The basic idea is to first find the depth of the tree using dfs. The variable count is used to indicate the current level. Once the level is found , create a vector of the size maximum level (here its variable max).

Then traverse again, this time additionally store the values in the vector. Note here we can directly give the index for insertion. For a normal level order traversal, we have to use index i instead of max-i-1 .

class Solution
{
public: int max=0;
        void dfs(TreeNode *root,int i,vector<vector<int>> &lst)
        {
            lst[max-i-1].push_back(root->val);   // push back at max-current level

            if(root->left!=NULL)
             dfs(root->left,i+1,lst);
            if(root->right!=NULL)
             dfs(root->right,i+1,lst);

        }
        void dfs2(TreeNode *root,int i)   // find the maximum level
        {
             if(max<i) max=i;

            if(root->left!=NULL)
             dfs2(root->left,i+1);
            if(root->right!=NULL)
             dfs2(root->right,i+1);

        }
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {  
        vector<vector<int>> lst;
        if(root==NULL) return lst;

        dfs2(root,1);
       lst.resize(max);
        dfs(root,0,lst);
        return lst;
    }
};
