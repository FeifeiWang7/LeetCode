The process works using 2 queues, one is the parent queue, the other one is the child queue.

Push root to the parent queue.
Push the child from the front parent queue.
Save the value of the front parent queue to a vector "lvl" and pop the parent queue.
If the parent queue is empty, push all the child queue to the parent queue (emptying the child queue), then save the "lvl" to the result variable.
Repeat from 2 until done.
:

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector <int> > res;
        vector <int> lvl;
        if(root == NULL)
            return res;
        queue <TreeNode*> st_par, st_chi;
        TreeNode* curr = root;
        st_par.push(curr);
        while(!st_par.empty()){
            curr = st_par.front();
            if(curr->left)
                st_chi.push(curr->left);
            if(curr->right)
                st_chi.push(curr->right);
            lvl.push_back(curr->val);
            st_par.pop();
            if(st_par.empty()){
                while(!st_chi.empty()){
                    st_par.push(st_chi.front());
                    st_chi.pop();
                }
                res.push_back(lvl);
                lvl.clear();
            }
        }
        return res;
    }
