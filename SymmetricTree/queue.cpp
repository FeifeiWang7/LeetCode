bool isSymmetric(TreeNode *root) {
    if(root == nullptr)
    return true;

    TreeNode *p_l = root->left;
    TreeNode *p_r = root->right;

    if(p_l == nullptr && p_r == nullptr)
    {
        return true;
    }
    else if(p_l == nullptr || p_r == nullptr)
    {
        return false;
    }
    queue<TreeNode*> ql;
    ql.push(p_l);
    queue<TreeNode*> qr;
    qr.push(p_r);

    while(!ql.empty() && !qr.empty())
    {
        TreeNode *cl = ql.front();
        TreeNode *cr = qr.front();

        if(cl->val != cr->val)
        {
            return false;
        }

        ql.pop();
        qr.pop();

        if(cl->left!=nullptr && cr->right != nullptr) 
        {
            ql.push(cl->left);
            qr.push(cr->right);
        }
        else if(cl->left!=nullptr || cr->right != nullptr)
        {
            return false;
        }

        if(cl->right!=nullptr && cr->left != nullptr) 
        {
            ql.push(cl->right);
            qr.push(cr->left);
        }
        else if(cl->right!=nullptr || cr->left != nullptr)
        {
            return false;
        }

    }

    return true;
}

