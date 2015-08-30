Iterative solution

class Solution {
public:
/*
iterative solution:
    if a tree is symmetric tree then all elements in one level will be palindrome
*/
bool isSymmetric(TreeNode* root) {
    if(NULL == root) {
        return true;
    }

    vector<TreeNode*> nodes;
    nodes.push_back(root);
    //begin index of current level
    size_t curBegin = 0;
    //end index of current level
    size_t curEnd = nodes.size();
    size_t b, e;
    while(curBegin < curEnd) {
        b = curBegin;
        e = curEnd - 1;
        while(b < e) {
            if(NULL==nodes[b] && NULL==nodes[e]) {
                b++;
                e--;
                continue;
            }
            if((NULL==nodes[b] && nodes[e]) || (NULL==nodes[e] && nodes[b]) || (nodes[b]->val != nodes[e]->val)) {
                return false;
            }
            //add new level elements
            nodes.push_back(nodes[b]->left);
            nodes.push_back(nodes[b]->right);

            b++;
            e--;
        }
        while(b < curEnd) {
            if(NULL == nodes[b]) {
                b++;
                continue;
            }
            nodes.push_back(nodes[b]->left);
            nodes.push_back(nodes[b]->right);
            b++;
        }

        //update current level begin and end
        curBegin = curEnd;
        curEnd = nodes.size();
    }

    return true;
}
};

Recursive solution

class Solution {
public:
//recursively solution
bool isSymmetric(TreeNode* root) {
    if(NULL == root) {
        return true;
    }

    return isChildSymmetric(root->left, root->right);
}

private:
bool isChildSymmetric(TreeNode* left, TreeNode* right) {
    if(NULL==left && NULL==right) {
        return true;
    }
    if(NULL==left || NULL==right || left->val!=right->val) {
        return false;
    }

    return (isChildSymmetric(left->left, right->right) && isChildSymmetric(left->right, right->left));
}
};
