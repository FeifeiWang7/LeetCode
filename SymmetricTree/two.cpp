RECURSIVE SOLUTION

class Solution {
    public:
       void recLR(TreeNode * root, vector<int> & temp){               
            if(root==NULL){
                temp.push_back(0);
                return;
            }
            temp.push_back(root->val);
            recLR(root->left,temp);
            recLR(root->right,temp);
        };

        void recRL(TreeNode * root, vector<int> & temp){               
            if(root==NULL){
                temp.push_back(0);
                return;
            }               
            temp.push_back(root->val);
            recRL(root->right,temp);
            recRL(root->left,temp);
        }

        bool isSymmetric(TreeNode* root) {                
        vector<int> a;
        vector<int> b;

        recLR(root,a);
        recRL(root,b);

        if(equal(a.begin(),a.end(),b.begin()))
            return true;
        else 
            return false;
        } 
    };
ITERATIVE SOLUTION

bool isSymmetric(TreeNode* root) {            
    queue<TreeNode*> bfs;        
    if(!root)return true;
    if(!root->left && !root->right)return true;      

    TreeNode *temp = root;
    bfs.push(root);

    while(!bfs.empty())
    {
        int i = bfs.size();
        vector<int> row;

        while(i){
            temp = bfs.front();                
            if(temp!=NULL)
                row.push_back(temp->val);
            else
                row.push_back(0);                
            bfs.pop();                
            if(temp)
            {
                bfs.push(temp->left);
                bfs.push(temp->right);
            }                
            i--;
        }

        vector <int> rev = row;
        reverse(rev.begin(), rev.end());            
        bool res  = equal(row.begin(),row.end(), rev.begin() );            

        if(!res)     
            return false;
   }        
    return true;            
    }
};

