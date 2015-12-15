I use pair to store the TreeNode and it's level.

vector<vector<int> > levelOrder(TreeNode *root)
{
    vector<vector<int> > vec;
    if (root == NULL)
        return vec;

    queue<pair<TreeNode*, int> > queue;
    pair<TreeNode*, int> pair(root, 0);
    queue.push(pair);

    while (!queue.empty()) {
        pair = queue.front();
        queue.pop();
        int val = pair.first->val;
        int level = pair.second;

        if (vec.size() <= level)
            vec.push_back(vector<int>());
        vec[level].push_back(val);


        if (pair.first->left)
            queue.push(make_pair(pair.first->left, level+1));
        if (pair.first->right)
            queue.push(make_pair(pair.first->right, level+1));
    }

    return vec;
}
