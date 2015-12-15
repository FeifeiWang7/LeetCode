Use queue and stack here. Start from original top down traversal with queue and build the reverse one with stack and push into the vector. The performance is not that bad comparing to using reverse(),just a different angle.

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if (root == NULL){
            return res;
        }
        queue<pair<TreeNode*, int> > q;
        stack<pair<TreeNode*, int> > st;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            if(node->right)
                q.push(make_pair(node->right, level + 1));
            if(node->left)
                q.push(make_pair(node->left, level + 1));
            st.push(make_pair(node, level));
            if(res.size() <= level){
                res.push_back(vector<int>());
            }
            q.pop();   
        }

        int depth = res.size() - 1;
        while(!st.empty()){
            TreeNode* node = st.top().first;
            int level = st.top().second;
            res[depth - level].push_back(node->val);
            st.pop();
        }

        return res;
    }
};
//another solution
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result,reverse;
    if(!root) return result;
    queue<TreeNode*> que;
    TreeNode* flag=NULL;
    que.push(root);
    que.push(flag);
    vector<int> level;
    while(!que.empty()){
        auto ptr=que.front();
        que.pop();
        if(!ptr){
            if(que.empty()){
                result.push_back(level);
            }
            else{
                result.push_back(level);
                level.clear();
                que.push(ptr);
            }
        }
        else{
            level.push_back(ptr->val);
            if(ptr->left)
               que.push(ptr->left);
            if(ptr->right)
               que.push(ptr->right);
        }
    }
    int size=result.size();
    for(int i=0;i<size;++i){
        reverse.push_back(result.back());
        result.pop_back();
    }
    return reverse;
}
