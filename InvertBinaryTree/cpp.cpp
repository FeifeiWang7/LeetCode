TreeNode* invertTree(TreeNode* root) {
    if (root==NULL) return NULL;
    TreeNode* tmp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tmp);
    return root;
}
////
TreeNode* invertTree(TreeNode* root) { TreeNode* p = root; stack<TreeNode*> st; stack ft;

    while(p!=NULL||!st.empty()){
        while(p!=NULL){
            st.push(p);
            ft.push(true);
            p=p->left;
        }
        if(!st.empty()){
            p=st.top();
            bool f=ft.top();
            if(f){
                ft.pop();
                ft.push(false);
                p=p->right;
            }else{
                st.pop();
                ft.pop();
                TreeNode* tmp=p->left;
                p->left=p->right;
                p->right=tmp;
                p=NULL;
            }
        }
    }//end while
    return root;
}
///////
The recursion version:

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        TreeNode * right_backup = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(right_backup);
        return root;
    }
};
The iteration version (using stack to simulate the recursion, with the same simple implementation (one loop, check the NULL node at the beginning of each "recursion", etc., to make it simple and clear)

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode * probe = s.top();
            s.pop();
            if (!probe) continue;
            swap(probe->left, probe->right);
            s.push(probe->left);
            s.push(probe->right);
        }
        return root;
    }
};
