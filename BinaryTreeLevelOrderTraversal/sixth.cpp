vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> Que;
    if (!root)
    {
        return res;
    }
    Que.push(root);
    while (!Que.empty())
    {
        vector<int> element;
        int Size = Que.size();
        while (Size--)
        {
            TreeNode* cur = Que.front();
            Que.pop();
            element.push_back(cur->val);
            if (cur->left)
            {
                Que.push(cur->left);
            }
            if (cur->right)
            {
                Que.push(cur->right);
            }
        }
        res.push_back(element);    
    }
    return res;
}


class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root == NULL)    return res;
        deque<TreeNode*> dq;
        dq.push_back(root);
        int nums_nowlayer, nums_nextlayer = 1;
        while(!dq.empty())
        {
            nums_nowlayer = nums_nextlayer;
            nums_nextlayer = 0;

            vector<int> val(nums_nowlayer);
            int idx = 0;
            // deal with the ith layer
            while(nums_nowlayer--)
            {
                // get the queue first element
                TreeNode* r = dq.front();
                val[idx++] = r->val;
                if(r->left != NULL)
                {
                    dq.push_back(r->left);
                    ++ nums_nextlayer;
                }
                if(r->right != NULL)
                {
                    dq.push_back(r->right);
                    ++ nums_nextlayer;
                }
                dq.pop_front();
            }
            res.push_back(val);
        }
        return res;
    }
};
