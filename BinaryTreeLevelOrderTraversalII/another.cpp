class Solution {
public:

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if(root==NULL)
    {
        vector<vector<int> > v(0,vector<int> (0,0));
        return v;
    }
 vector<vector<int> > v;
 queue<TreeNode *> q;
 q.push(root);
 q.push(NULL);
 while(!q.empty())
 {

     vector<int > a;
     {
         while(q.front()!=NULL)
         {
             root=q.front();
             a.push_back(q.front()->val);
            q.pop();
             if(root->left)
             q.push(root->left);
             if(root->right)
             q.push(root->right);
         }
         q.pop();

         v.push_back(a);
         a.clear();
         if(q.empty())
         break;
          q.push(NULL);
     }
 }
reverse(v.begin(),v.end());
 return v;
}
};
