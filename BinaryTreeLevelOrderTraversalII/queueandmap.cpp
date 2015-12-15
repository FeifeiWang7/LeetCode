void levelOrderBottom(TreeNode *root) {
   vector<vector<int>>  ivvec;
  if(root == NULL)  return ivvec;
  queue<pair<TreeNode*,int>> q;
  map<int,vector<int>>  imap;
  int level=0;
  q.push(make_pair(root,level));
  while(!q.empty())
  {
      TreeNode *Node = (q.front().first);
      int flevel = (q.front().second);
      imap[flevel].push_back(Node->val);
      q.pop();
      if(Node->left !=NULL)
          q.push(make_pair(Node->left,flevel+1));
      if(Node->right !=NULL)
          q.push(make_pair(Node->right,flevel+1));    
  }
  for(auto iter = imap.rbegin();iter != imap.rend();iter++)
  {
      ivvec.push_back(iter->second);
  }
 return ivvec;
}
