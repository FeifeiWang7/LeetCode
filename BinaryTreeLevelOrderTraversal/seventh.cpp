BFS:

vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> levels;
        if(!root) return levels;
        queue<TreeNode*> toVisit;
        toVisit.push(root);
        int numLevelNodes = 1;
        while(!toVisit.empty()) {
            vector<int> level;
            for (int i = 0; i < numLevelNodes; i++) {
                TreeNode* node = toVisit.front();
                toVisit.pop();
                level.push_back(node -> val);
                if(node -> left) toVisit.push(node -> left);
                if(node -> right) toVisit.push(node -> right);
            }
            levels.push_back(level);
            numLevelNodes = toVisit.size();
        }
        return levels;
    }
DFS:

 vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> levels;
    if(!root) return levels;
    int curLevel = 1;
    bool nextLevel = true;
    while(nextLevel) {
        nextLevel = false;
        vector<int> level;
        levelTraverse(root, curLevel++, nextLevel, level);
        levels.push_back(level);
    }
    return levels;
}
void levelTraverse(TreeNode* node, int curLevel, bool& nextLevel, vector<int>& level) {
    if(!node) return;
    if(curLevel == 1) {
        level.push_back(node -> val);
        if(node -> left || node -> right) nextLevel = true;
    }
    else {
        levelTraverse(node -> left, curLevel - 1, nextLevel, level);
        levelTraverse(node -> right, curLevel - 1, nextLevel, level);
    }
}
