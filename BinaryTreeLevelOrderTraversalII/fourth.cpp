class Solution {
public:
    int height(TreeNode *root){
        if(root==NULL)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
    void fill_level(vector<int>* v,TreeNode* root,int level){
        if(root==NULL)
            return;
        if(level==1)
        {
            (*v).push_back(root->val);
            return ;
        }
        level=level-1;
        if(root->left!=NULL)
            fill_level(v,root->left,level);
        if(root->right!=NULL)
            fill_level(v,root->right,level);
        return ;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> level_order;
        for(int i=height(root);i>0;--i)
        {
            vector<int> v;
            fill_level(&v,root,i);
            level_order.push_back(v);
        }
        return level_order;
    }
}; 
