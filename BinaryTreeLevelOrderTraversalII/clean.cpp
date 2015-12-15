My ideas are simple: maintain 2 vectors for father nodes and children nodes, update them downward line by line until reaching the tree bottom.

/** * Definition for a binary tree node. * struct TreeNode { * int val; * TreeNode left; * TreeNode *right; * TreeNode(int x) : val(x), left(NULL), right(NULL) {} * }; */ class Solution { public: vector<vector> levelOrderBottom(TreeNode root) {

   vector<vector<int> > ans;

   if (!root) return ans;

   vector<TreeNode*> vfathers,vsons;//two vectors are used to record 2 levels of nodes

   vfathers.push_back(root);//initially, vfathers is root

  vector<int> p;
  p.push_back(root->val);
  ans.push_back(p); 

for(;;){
   for (auto it=vfathers.begin(); it!=vfathers.end(); ++it){//traverse the fathers
       if ((*it)->left) vsons.push_back((*it)->left);//if any sons, then push it to the vsons vector
       if ((*it)->right) vsons.push_back((*it)->right);
   }

   if (vsons.size()==0) {reverse(ans.begin(),ans.end());return ans;} //if no sons, it means bottom of the tree
   else { // if sons exist, then record it
       vector <int> pp;
       for (auto it =vsons.begin(); it!=vsons.end(); ++it)
       {
          pp.push_back((*it)->val);//push all the sons values to the tmp vec pp
      }
       ans.push_back(pp);
       pp.clear();
      //evolution sons succeed fathers
      vfathers=vsons;
      vsons.clear();
   }

}
}
};


