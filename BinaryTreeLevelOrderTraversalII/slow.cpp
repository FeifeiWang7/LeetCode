//
vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > retVal;

    levelOrder(root, retVal, 0);

    reverse(retVal.begin(), retVal.end());

    return retVal;
}

void levelOrder(TreeNode* root, vector<vector<int> > &v, int currLevel) {
    if (root == NULL) {
        return;
    }

    if (v.empty() || currLevel > (v.size() - 1)) {
        v.push_back(vector<int>());
    }

    v[currLevel].push_back(root->val);

    levelOrder(root->left, v, currLevel + 1);
    levelOrder(root->right, v, currLevel + 1);
}
//

I use insert to add in the front of the vector.

and use res.size()-level to find where the node should be in the res.

but insert really takes a lot of time.

In fact, it takes 70ms.

vector<vector<int>> res;
vector<int> tmp;

void helper(TreeNode *curr,int level){
    if(curr==NULL)return;
    int s=res.size();

    if(level==s){
        res.insert(res.begin(),tmp);
        s++;            
    }

    level++;

    res[s-level].push_back(curr->val);

    helper(curr->left,level);
    helper(curr->right,level);
}
vector<vector<int> > levelOrderBottom(TreeNode *root) {
    helper(root,0);
    return res;
}
