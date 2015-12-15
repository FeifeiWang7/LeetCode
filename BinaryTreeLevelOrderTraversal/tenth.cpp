class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> >  result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> cur_vec;
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t==NULL) {
                result.push_back(cur_vec);
                cur_vec.resize(0);
                if (q.size() > 0) {
                    q.push(NULL);
                }
            } else {
                cur_vec.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {

        vector<vector<int>> res;
        vector<TreeNode*> v;

        if (!root) return res;

        v.push_back(root);

        long cur = 0, last = 1;

        while(cur < v.size()){
            last = v.size();
            vector<int> temp;
            while ( cur < last){
                temp.push_back(v[cur]->val);
                if (v[cur]->left) v.push_back(v[cur]->left);
                if (v[cur]->right) v.push_back(v[cur]->right);
                cur ++;
            }
            res.push_back(temp);
        }
        return res;
    }
};



class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        build_levels(root, res);
        return res;
    }
private:
    void build_levels(TreeNode* node, vector<vector<int> >& levels, int current=0 ) {
        if (node!=NULL) {
            if (levels.size()<= current) {
                levels.push_back(vector<int>()) ;
            }
            levels[current].push_back(node->val) ;
            build_levels(node->left, levels, current+1);
            build_levels(node->right, levels, current+1);
        }
    }
};
