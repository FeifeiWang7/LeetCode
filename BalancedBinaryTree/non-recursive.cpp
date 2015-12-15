using namespace std;

#define forLess(i, s, e)    for(int i = (s); i < int(e); ++i)
#define forto(i, s, e)  for(int i = (s); i <= int(e); ++i)

struct Node
{
    Node(TreeNode* r) : root(r), flag(false), lh(-1), rh(-1) {}
    TreeNode* root;
    bool flag;
    int lh, rh;
};

class Solution 
{
public:
    bool isBalanced(TreeNode* root) 
    {
        if(root == NULL)
            return true;
        stack<Node*> s;
        TreeNode *p = root;
        while(p != NULL || !s.empty()){
            if(p == NULL){
                Node *n = s.top();
                if(!n->flag){
                    p = n->root->right;
                    n->flag = true;
                }
                else{
                    if(n->root->left == NULL)
                        n->lh = 0;
                    if(n->root->right == NULL)
                        n->rh = 0;
                    if(abs(n->lh - n->rh) > 1)
                        return false;
                    s.pop();
                    if(!s.empty()){
                        int h = max(n->lh, n->rh) + 1;
                        if(!s.top()->flag)
                            s.top()->lh = h;
                        else
                            s.top()->rh = h;
                    }
                }
            }
            else{
                s.push(new Node(p));
                p = p->left;
            }
        }
        return true;
    }
};
