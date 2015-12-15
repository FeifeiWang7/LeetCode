class Solution { public:

bool hasPathSum(TreeNode* root, int sum) {
    if(root == NULL ){
        return false;
    }
    if(sum == root->val && root->left== NULL && root->right == NULL){
        return true;
    }
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
};

///
/*
    bool hasPathSum(TreeNode* root, int sum) {
        if( !root ) return false;
        if( root->val == sum && root->left == NULL && root->right == NULL ) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
*/
    bool hasPathSum(TreeNode* root, int sum) {
        if( !root ) return false;

        stack<pair<TreeNode*,int> > s;
        s.push(make_pair(root, sum));
        int val;
        TreeNode* p;

        while( !s.empty() ) {
            p = s.top().first;
            val = s.top().second;
            s.pop();
            if( p->left == NULL && p->right == NULL && p->val == val ) 
                return true;
            if( p->right ) 
                s.push(make_pair(p->right, val - p->val));
            if( p->left ) 
                s.push(make_pair(p->left, val - p->val));
        }
        return false;
    }
