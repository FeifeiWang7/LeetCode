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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> nodes;
        if(!root)
            return nodes;

        stack<vector<int>> s;
        queue<TreeNode*> q;
        q.push(root);

        while(1){
            int nodecount = q.size();
            vector<int> levelnodes;
            if(nodecount == 0)
                break;

            while(nodecount > 0){
                TreeNode *p = q.front();
                q.pop();
                levelnodes.push_back(p->val);
                nodecount--;
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            // one level complete
            s.push(levelnodes);
        }
        // now push elements to the nodes vector
        while(s.size()){
            nodes.push_back(s.top());
            s.pop();
        }


        return nodes;

    }    
};`
