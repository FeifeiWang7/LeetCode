I thought it could be better to store the heights of nodes which are calculated before. It should be more efficient than calculate node height multi-times. However the result shows always slower than before.

This is a "revised" method using map to store the results which are already calculated.

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        if (!isBalanced(root->left) || !isBalanced(root->right))
            return false;
        return abs(getHeight(root->left) - getHeight(root->right)) <= 1;
    }

private:
    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        if (heightMap.find(root) != heightMap.end())
            return heightMap[root];

        heightMap[root] = std::max(getHeight(root->left), getHeight(root->right)) + 1;
        return heightMap[root];
    }

    std::map<TreeNode *, int> heightMap;
};
