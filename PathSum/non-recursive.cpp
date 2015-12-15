bool hasPathSum(TreeNode* root, int sum) {
    if(!root) return false;

    TreeNode *tmp = root, *last = NULL;
    stack<TreeNode*> s;

    while(tmp || !s.empty()) {
        if(tmp) {
            s.push(tmp);
            sum -= tmp->val;
            tmp = tmp->left;
        }
        else {
            TreeNode *topNode = s.top();
            if(!(topNode->left) && !(topNode->right) && !sum) return true;
            else if(topNode->right && last!=topNode->right) tmp = topNode->right;
            else { last = topNode; s.pop(); sum += topNode->val; }
        }
    }
    return false;
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
    vector<TreeNode *> path;
    set<TreeNode *> mark;
    TreeNode *temp = root;
    int curSum = 0;

    if(root == NULL)return false;

    path.push_back(temp);
    curSum += temp->val;
    mark.insert(temp);

    while(path.size()) {
    temp = path.back();

    if (temp->left != NULL || temp->right != NULL ) {
        //only have left leaf
        if(temp->right == NULL) {
        if( mark.find( temp->left ) == mark.end()){
            path.push_back(temp->left);
            curSum += temp->left->val;
            mark.insert(temp->left);
        }
        else {
            curSum -= temp->val;
            path.pop_back();
        }
        }
        //only have right leaf
        else if(temp->left == NULL) {
        if( mark.find( temp->right ) == mark.end()){
            path.push_back(temp->right);
            curSum += temp->right->val;
            mark.insert(temp->right);
        }
        else {
            curSum -= temp->val;
            path.pop_back();
        }
        }
        //have both left and right leaf
        else {
        if( mark.find( temp->left ) == mark.end()){
            path.push_back(temp->left);
            curSum += temp->left->val;
            mark.insert(temp->left);
        }
        else if( mark.find( temp->right) == mark.end() ){
            path.push_back(temp->right);
            curSum += temp->right->val;
            mark.insert(temp->right); 
        }
        else {
            curSum -= temp->val;
            path.pop_back();
        }
        }
    }
    //have null left and right leaf(no valid child)
    else {
        //come to leaf now , so put the dujdgement here
        if(curSum == sum)return true;
        curSum -= temp->val;
        path.pop_back();
    }
    }
    return false;
    }
};
