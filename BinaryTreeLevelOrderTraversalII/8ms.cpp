class Solution { public: vector<vector> levelOrderBottom(TreeNode* root) { stack<vector> myStack; queue<TreeNode> myQ; queue<TreeNode> myQ_nextLevel;

    vector<vector<int>> result;
    if (root == NULL) return result;

    myQ.push(root);
    vector<int> temp;

    while (!myQ.empty()) {
        temp.push_back(myQ.front()->val);
        if (myQ.front()->left) {
            myQ_nextLevel.push(myQ.front()->left);
        }
        if (myQ.front()->right) {
            myQ_nextLevel.push(myQ.front()->right);
        }
        myQ.pop();
        if (myQ.empty()) {
            myStack.push(temp);
            temp.clear();
            swap(myQ, myQ_nextLevel);
        }
    }

    while (!myStack.empty()) {
        result.push_back(myStack.top());
        myStack.pop();
    }

    return result;
}
};


