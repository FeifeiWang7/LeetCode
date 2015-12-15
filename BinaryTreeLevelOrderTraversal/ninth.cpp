vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > retVal;

    levelOrder(root, retVal, 0);

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
