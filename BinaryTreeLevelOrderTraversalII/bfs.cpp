vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int> > r;
    vector<int> level;
    queue<TreeNode*> q;
    queue<TreeNode*> l;
    if( !root ) return r;
    q.push(root);
    while( !q.empty() ) {
        root = q.front();
        q.pop();
        level.push_back(root->val);

        if( root->left ) 
            l.push(root->left);

        if( root->right )
            l.push(root->right);

        if( q.empty() ) {
            r.push_back(level);
            level.resize(0);
            //copy(l.begin(), l.end(), q.begin());
            while( !l.empty() ) {
                q.push(l.front());
                l.pop();
            }
        }

    }
    reverse(r.begin(),r.end());
    return r;
}
It's very simple. I think we can optimize it by without copying the second queue elements. But I didn't find a way till now
///

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL) return result;
    stack<vector<int>> level_tmp;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> level;
        size_t size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
        }
        level_tmp.emplace(move(level));
    }
    while (!level_tmp.empty()) {
        result.emplace_back(move(level_tmp.top()));
        level_tmp.pop();
    }
    return vector<vector<int>>(result);
}


///anther
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL) return ret;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int l = q.size();
            vector<int> curlayer;
            for (int i = 0; i < l; i++) {
                TreeNode *cur = q.front();
                q.pop();
                curlayer.push_back(cur->val);
                if (cur->left != NULL) q.push(cur->left);
                if (cur->right != NULL) q.push(cur->right);
            }
            ret.push_back(curlayer);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
