My solution is just a level order traversal but there is some twist. I am doing level order and using queue for that and while traversing I am pushing the level order elements in the stack and after this , i just pop the elements from the stack.

So , I am using a queue and stack but the space complexity is quite large ..O(2n).

Can someone please suggest some idea I can improve the code using queue and stack only.. THanks

/**
     * Definition for binary tree
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     * };
     */
    class Solution {
    public:
        vector<vector<int> > levelOrderBottom(TreeNode *root) {
            vector<vector <int> > print;
            vector<int> level;
            queue<TreeNode*> qp;
            stack<TreeNode*> sp;

            if(root == NULL)
                return print;

            qp.push(root);
            qp.push(NULL);
            // NULL is used to separate the levels
            while(!qp.empty()){
                TreeNode *temp = qp.front();  
                qp.pop();
                if(temp == NULL){ 
                    if(!qp.empty()){
                        sp.push(temp);
                        qp.push(NULL);
                    }
                }else{
                    sp.push(temp); // pushing the node in the stack
                    if(temp->right)
                        qp.push(temp->right);
                    if(temp->left)
                        qp.push(temp->left);
                }
     //           sp.push(temp);
            }
            while(1){
                if(sp.empty()){ // if stack is empty , it means there is last level left
                    print.push_back(level);
                    break;
                }
                TreeNode *temp = sp.top();
                sp.pop();
                if(temp == NULL){
                    print.push_back(level);
                    level.clear();
                }else{
                    level.push_back(temp->val);
                }

            }

            return print;

        }
    };

