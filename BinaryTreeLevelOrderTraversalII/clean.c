struct LinkedIntNode
{
    int val;
    struct LinkedIntNode *next;
};

struct LinkedInts
{
    int count;
    struct LinkedIntNode *head;
};

struct TreeTraversalResult
{
    int levelLimit;
    struct LinkedInts *levels;
};

void initTreeResult(struct TreeTraversalResult *r, int level)
{
    r->levelLimit = level;
    r->levels = malloc(sizeof(struct LinkedInts) * level);
    memset(r->levels, 0 , sizeof(struct LinkedInts) * level);
}

void addTreeNode(struct TreeTraversalResult *r, int val, int level)
{
    if(r->levelLimit < level + 1)
    {
        struct LinkedInts *newLevels = malloc(sizeof(struct LinkedInts) * (level + 10));
        memset(newLevels, 0, sizeof(struct LinkedInts) * (level + 10));
        memmove(newLevels, r->levels, sizeof(struct LinkedInts) * r->levelLimit);
        r->levelLimit = level + 10;
        r->levels = newLevels;
    }
    struct LinkedIntNode *node = malloc(sizeof(struct LinkedIntNode));
    node->val = val;
    node->next = r->levels[level].head;
    r->levels[level].head = node;
    r->levels[level].count++;
}

void traversal(struct TreeNode* node, int curLevel, struct TreeTraversalResult *r)
{
    addTreeNode(r, node->val, curLevel);
    if (node->left)
    {
        traversal(node->left, curLevel + 1, r);
    }
    if (node->right)
    {
        traversal(node->right, curLevel + 1, r);
    }
}
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if(root == NULL) return NULL;
    struct TreeTraversalResult result;
    initTreeResult(&result, 200);
    traversal(root, 0, &result);
    int i;
    for(i = 0; i < result.levelLimit; ++i)
    {
        if(result.levels[i].count == 0) break;
    }
    int **resultArray = malloc(sizeof(int *) * i);
    *columnSizes = malloc(sizeof(int) * i);
    *returnSize = i;
    int tmp;
    for(int j = i - 1, n = 0; j >= 0; --j, ++n)
    {
        (*columnSizes)[n] = tmp = result.levels[j].count;
        resultArray[n] = malloc(sizeof(int) * tmp);
        struct LinkedIntNode *node = result.levels[j].head;
        for(int k = tmp - 1; k >= 0; k--)
        {
            *(resultArray[n]+k) = node->val;
            node = node->next;
        }
    }
    return resultArray;
}



////
without these data structure containers,it's a little painful.when come to algorithm I do like to write it in C. but when standard container is needed anyway. using C++ would make life easier. below is my accepted solution, just reverse the result of levelOrder

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if(!root)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    vector<int> v;
    while(!q.empty()){
        int n=q.size();
        while(n>0){
            auto node=q.front();
            v.push_back(node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            q.pop();
            --n;
        }
        res.emplace_back(v);
        v.clear();
    }
    reverse(res.begin(),res.end());
    return res;
}
