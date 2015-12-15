class Solution {
public:
    vector <int> path;
    vector <string> ans;
    string makePath() {
        string res;
        for (int i = 0; i < path.size(); i++) {
            res += to_string(path[i]);
            if (i + 1 != path.size()) res += "->";
        }
        return res;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        traversal(root);
        return ans;
    }
    void traversal(TreeNode * node) {
        if (!node) return;
        path.push_back(node->val); // add to the pass

        if (!node->left && !node->right) 
            ans.push_back(makePath());

        traversal(node->left);
        traversal(node->right);
        path.pop_back();    // delete from the pass
    }
};
//////
recursive methods is easy to finish.

class Solution { public:

void helper(TreeNode*node, vector& res, string output){

  if(node == NULL) return;

  if(node->left == NULL && node->right == NULL){
      output += to_string(node->val);
      res.push_back(output);
      return;
  }

  output +=  to_string(node->val) + "->";

  if(node->left){
      helper(node->left,res,output);
  }

  if(node->right){
      helper(node->right,res,output);
  }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if(root == NULL) return res;

    string output;

    TreeNode* node = root;

    helper(node,res,output);

    return res;
}
};

=================================

For the iterative, it is not as intuitive. Here I use a vector<TreeNode*> to store all the nodes in one path, and check the last node of this vector, if the last node is an leaf node, then we construct the string of the values in this path. The idea is to use a queue to store all the possible paths ( using vector for each path)

class Solution { public: vector binaryTreePaths(TreeNode* root) {

    vector<string> res;
    if(root == NULL) return res;
    queue<vector<TreeNode*>> q;

    vector<TreeNode*> cur;
    cur.push_back(root);
    q.push(cur);

    while(!q.empty()){

        int qsize = q.size();

        for(int i = 0; i<qsize; i++){
            cur = q.front();
            q.pop();

            TreeNode* last = cur[cur.size()-1];

            if(last->left != NULL && last->right ==NULL){

                cur.push_back(last->left);
                q.push(cur);

            }else  if(last->left == NULL && last->right !=NULL){
                cur.push_back(last->right);
                q.push(cur);

            }else if(last->left != NULL && last->right != NULL){
                cur.push_back(last->left);
                q.push(cur);
                cur.pop_back();
                cur.push_back(last->right);
                q.push(cur);

            }else if(last->left == NULL && last->right == NULL){

                string output = "";

                for(int i = 0; i < cur.size(); i++){

                    if(i!=cur.size()-1){
                        output += to_string(cur[i]->val) + "->";
                    }else{
                        output += to_string(cur[i]->val);
                    }
                }
                res.push_back(output);
            }
        }
    }
    return res;
}
};
///
void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
    if(!root->left && !root->right) {
        result.push_back(t);
        return;
    }

    if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
    if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if(!root) return result;

    binaryTreePaths(result, root, to_string(root->val));
    return result;
}
///great solution. I shared the same idea with yours. But my solution showed run rime error, can anyone tell me the reason?

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    std::vector<string> rootPaths(TreeNode* root, string str, std::vector<string> res) {
        if(!root->left && !root->right) {
            res.push_back(str);
            return res;
        }
        if(root->left) {
            res = rootPaths(root->left, str + "->" + to_string(root->left->val), res);
        }
        if(root->right) {
            res = rootPaths(root->right, str + "->" + to_string(root->right->val), res);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<string> res;
        if(!root) {
            return res;
        }
        res = rootPaths(root, to_string(root->val), res);
        return res;
    }
};
///
Hi, I solved the question with the normal recursive code, I wonder if we could have the solution with O(1) space? I wonder if we could solve it with morris traversal ... to get to the O(1) solution?

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        string result="";
        binaryTreePaths(root, results, result);
        return results;
    }
private:
    void binaryTreePaths(TreeNode* root, vector<string>& results, string result){
        if(root==NULL)
            return;    
        result=result+to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            results.push_back(result);
            return;
        }

        if(root->left!=NULL)
            binaryTreePaths(root->left, results, result+"->");
        if(root->right!=NULL)
            binaryTreePaths(root->right, results, result+"->");
    }
///
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if (!root) return {};
        auto la(binaryTreePaths(root->left));
        auto lb(binaryTreePaths(root->right));
        la.insert(la.end(), lb.begin(), lb.end());
        if (la.empty())
            return {to_string(root->val)};
        for (auto &s : la)
            s = to_string(root->val) + "->" + s;
        return la;
    }
};
///
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (!root) return ret;
        if (!root->left && !root->right) return {to_string(root->val)};
        auto lv = binaryTreePaths(root->left);
        auto rv = binaryTreePaths(root->right);
        for (auto &s : lv) ret.push_back(to_string(root->val)+"->" + s);
        for (auto &s : rv) ret.push_back(to_string(root->val)+"->" + s);
        return ret;
    }
};
///The basic idea is to start from root and add it to the current path, then we recursively visit its left and right subtrees if they exist; otherwise, we have reached a leaf node, so just add the current path to the result paths.

The code is as follows.

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string path;
        treePaths(root, path, paths);
        return paths;
    }
private:
    void treePaths(TreeNode* node, string path, vector<string>& paths) {
        if (!node) return;
        path += path.empty() ? to_string(node -> val) : "->" + to_string(node -> val);
        if (!(node -> left) && !(node -> right)) {
            paths.push_back(path);
            return;
        }
        if (node -> left) treePaths(node -> left, path, paths);
        if (node -> right) treePaths(node -> right, path, paths);
    }
}; 
///
class Solution {
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> res;
        if (!root) {
            return res;
        }
        std::string str = std::to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(str);
            return res;
        }
        if (root->left) {
            binaryTreePathsHelper(root->left, res, str);
        }
        if (root->right) {
            binaryTreePathsHelper(root->right, res, str);
        }
        return res;
    }
private:
    void binaryTreePathsHelper(TreeNode *root, std::vector<std::string> &res, std::string str) {
        str += "->" + std::to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(str);
            return;
        }
        if (root->left) {
            binaryTreePathsHelper(root->left, res, str);
        }
        if (root->right) {
            binaryTreePathsHelper(root->right, res, str);
        }
    }
};
///
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> currentPath;
        size_t currentIndex = 0;
        binaryTreePathsRecursive(root, result, currentPath, currentIndex);
        return result;
    }

    void binaryTreePathsRecursive(const TreeNode* root, vector<string>& paths, vector<int>& currentPath, size_t currentIndex)
    {
        if(root == NULL) return;

        if(currentIndex + 1 > currentPath.size()) currentPath.push_back(root->val);
        else currentPath[currentIndex] = root->val;
        ++currentIndex;

        if(root->left == NULL && root->right == NULL) // leaf found - add the current path
        {
            ostringstream oss;
            for(size_t i = 0; i < currentIndex - 1; ++i) oss << currentPath[i] << "->";
            oss << currentPath[currentIndex - 1];
            paths.push_back(oss.str());
            return;
        }

        binaryTreePathsRecursive(root->left, paths, currentPath, currentIndex);
        binaryTreePathsRecursive(root->right, paths, currentPath, currentIndex);
    }
};
//////
The recursive solution is trivial.

class Solution 
{
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> paths;
        // If root is NULL, return an empty path vector.
        if (root == nullptr)
        {
            return paths;
        }

        // Get the path vector starting from the left child.
        vector<string> leftPaths = binaryTreePaths(root->left);
        // Concatenate root with the left paths to generate 
        // the paths starting from root.
        for (auto& lp : leftPaths)
        {
            paths.push_back(to_string(root->val) + "->" + lp);
        }

        // Get the path vector starting from the right child.
        vector<string> rightPaths = binaryTreePaths(root->right);
        // Concatenate root with the right paths to generate 
        // the paths starting from root.
        for (auto& rp : rightPaths)
        {
            paths.push_back(to_string(root->val) + "->" + rp);
        }

        // In case that both leftPaths and rightPaths are empty, 
        // i.e., root is a leaf, root itself is a path.
        if (paths.empty())
        {
            paths.push_back(to_string(root->val));
        }

        return paths;
    }
};
The iterative solution essentially uses the depth-first search to find all the paths from root to leaves. Compared with the breadth-first search approach, this approach doesn't need to have a vector of vectors to keep the paths from root to the nodes at the current level. Besides the result vector of strings, this approach just needs one vector which keeps one path from root to the current node and one unordered set which keeps all the nodes that have been visited during the depth-first search. Thus, with respect the space complexity, the depth-first search is more efficient than the breadth-first search.

class Solution 
{
    // Generate the path string from the TreeNode val vector.
    string GetPathStringFromNums(vector<int> &pathVal)
    {
        int n = pathVal.size();
        string res;
        // For the nodes except the last node, we need to 
        // append "->" to the node values.
        for (int i = 0; i < n - 1; i++)
        {
            res += (to_string(pathVal[i]) + "->");
        }

        if (n > 0)
        {
            res += to_string(pathVal[n - 1]);
        }

        return res;
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> paths;
        // If root is NULL, return an empty path vector immediately.
        if (root == nullptr)
        {
            return paths;
        }

        // pathVal is a vector of TreeNode values along a path 
        // starting from root.
        vector<int> pathVal({root->val});

        // st is the stack used for the depth-first search.
        stack<TreeNode*> st;
        st.push(root);

        // visitedNodes keeps all the nodes which have been visited 
        // during the depth-first search. In other words, it keeps 
        // all the nodes which have ever been pushed into the stack.
        unordered_set<TreeNode*> visitedNodes({root});

        // Do the depth-first search until the stack is empty.
        while (!st.empty())
        {
            TreeNode *curr = st.top();

            if ((curr->left == nullptr) && (curr->right == nullptr))
            {
                // curr is a leaf, so the current path is a path from 
                // root to a leaf and add it to paths.
                paths.push_back(GetPathStringFromNums(pathVal));

                // Remove the leaf node from pathVal which will end at 
                // the parent node of curr.
                pathVal.pop_back();

                st.pop();
            }
            else 
            {
                // curr is not leaf, so we need to go down at least one 
                // level.

                // First we try pushing the left child if it hasn't 
                // been visited.
                if (curr->left != nullptr)
                {
                    auto itLeft = visitedNodes.find(curr->left);
                    if (itLeft == visitedNodes.end())
                    {
                        st.push(curr->left);
                        pathVal.push_back(curr->left->val);

                        visitedNodes.insert(curr->left);
                        continue;
                    }
                }

                // We reach here because either the left child doesn't 
                // exist or the left child has been visited. Then we try 
                // pushing the right child if it hasn't been visited.
                if (curr->right != nullptr)
                {
                    auto itRight = visitedNodes.find(curr->right);
                    if (itRight == visitedNodes.end())
                    {
                        st.push(curr->right);
                        pathVal.push_back(curr->right->val);

                        visitedNodes.insert(curr->right);
                        continue;
                    }
                }

                // The nodes in the subtree below curr have all been 
                // visited, so remove curr from pathVal which will end 
                // at the parent node of curr.
                pathVal.pop_back();
                st.pop();
            }
        }

        return paths;
    }
};

///
(1)Recursion, if root is empty, return, if root is a leaf, then return cur+root->val, if root has childrens, then do recursion on each child, with cur updated to cur + root->val +"->"

class Solution {
    void dfs(vector<string> &res, TreeNode *root, string cur)
    {
        if(!root->left && !root->right) res.push_back(cur  + std::to_string(root->val));
        else
        {
            if(root->left) dfs(res, root->left,  cur  + std::to_string(root->val)+"->");
            if(root->right) dfs(res, root->right, cur  + std::to_string(root->val)+"->");
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root)  dfs(res, root, "");
        return res;
    }
};
(2) DFS Version using a stack Using a stack (the element is a pair of the current node pointer and the string recording the path from root to the current node). The logic is the same as (1)

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        TreeNode *curNode;
        string curPath;
        stack<pair<TreeNode*, string>> liveNodes;
        if(root) liveNodes.push(make_pair(root, ""));
        while(!liveNodes.empty())
        {
            curNode = liveNodes.top().first;
            curPath    = liveNodes.top().second;
            liveNodes.pop();
            if(!curNode->left && !curNode->right)
            {
                res.push_back(curPath + std::to_string(curNode->val));
            }
            else
            {
                if(curNode->left)  liveNodes.push(make_pair(curNode->left, curPath + std::to_string(curNode->val)+ "->"));
                if(curNode->right) liveNodes.push(make_pair(curNode->right, curPath + std::to_string(curNode->val)+ "->"));
            }
        }
        return res;
    }
};
(3) BFS queue based solution. It prints all the paths in an ascending order of the path length

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        queue<pair<TreeNode*, string>> liveNodes[2];
        int cur=0, next=1;
        TreeNode* curNode;
        string curPath;
        vector<string> res;

        if(root) liveNodes[cur].push(make_pair(root, ""));
        while(!liveNodes[cur].empty())
        {
            curNode = liveNodes[cur].front().first;
            curPath = liveNodes[cur].front().second;
            liveNodes[cur].pop();
            if(!curNode->left && !curNode->right) res.push_back(curPath + std::to_string(curNode->val));
            else{
                if(curNode->left)  liveNodes[next].push(make_pair(curNode->left,  curPath + std::to_string(curNode->val) + "->"));
                if(curNode->right) liveNodes[next].push(make_pair(curNode->right, curPath + std::to_string(curNode->val) + "->"));
            }
            if(liveNodes[cur].empty()) swap(cur, next);
        }
        return res;
    }
};

///
class Solution {
public:
    void gatherPath(TreeNode* root, vector<vector<int> >&res, vector<int> vec){
        vec.push_back(root->val); //push this node
        if(!root->left && !root->right){ //if this is leaf then push the vector formed so far to result
            res.push_back(vec);
            return;
        }
        //recurse through left and right
        if(root->left) gatherPath(root->left,res,vec);
        if(root->right) gatherPath(root->right,res,vec);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> op; //return variable
        vector<vector<int> > res; //for gathering paths
        vector<int> vec;
        if(root==NULL) {return {};} // handling special case
        gatherPath(root,res,vec); //recursive function to gather all paths
        //transforming the integer vector to the "pretty print" string
        for(int i=0;i<res.size();i++){
            string s;
            for(int j=0;j<res[i].size();j++){
                s += to_string(res[i][j]) + "->";
            }
            s.erase(s.length()-2); //to delete off the hanging redundant "->"
            op.push_back(s);
        }
        return op;
    }
};
///
void DFS(TreeNode* root, string path, vector<string>& res) {
    if(root->left == NULL && root->right==NULL) {
        res.push_back(path);
        return;
    }
    if(root->left)
        DFS(root->left, path+ "->" + to_string(root->left->val), res);            
    if(root->right)
        DFS(root->right, path + "->" + to_string(root->right->val), res);
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if(root==NULL)
        return res;
    string path = to_string(root->val);
    DFS(root, path, res);
    return res;
}
///
class Solution {
    vector<string> mypaths;
public:
    void helper(TreeNode *root, string path){
        if(!root->left && !root->right){
            path=path+to_string(root->val);
            mypaths.push_back(path);
        }
        else if(!root->left && root->right){
            path=path+to_string(root->val)+"->";
            helper(root->right,path);
        }
        else if(root->left && !root->right){
            path=path+to_string(root->val)+"->";
            helper(root->left, path);
        }
        else{
            path=path+to_string(root->val)+"->";
            string path2=path;
            helper(root->left,path);
            helper(root->right,path2);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root){
            string path;
            helper(root,path);
        }
        return mypaths;

    }
};
/////
This is a DFS problem. The idea is to maintain a path to current node. This path can only store the node values on the path since we only need to output the values. You can do it either recursively or iteratively. For recursion, you can pass the current path by reference or use a member variable. For iteration, it is more obvious. Here I use iterations and a vector to store the path.

We need to maintain a correct length of path vector according to the current level of the traversal. For recursion, you can passing the level by a parameter. For iteration, you can passing the level along with the node on the stack. I use a pair to pairing node and level number to store the correct level number.

Any words?

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        vector<int> path;
        stack< pair<TreeNode*, int> > s;
        s.push(make_pair(root, 0));
        while (!s.empty()) {
            int level = s.top().second;
            path.resize(level);
            TreeNode * node = s.top().first;
            s.pop();
            path.push_back(node->val);
            if (!node->left && !node->right) {
                string pathstr;
                for (int i = 0; i < path.size(); ++i) {
                    pathstr += to_string(path[i]) + ((i != path.size() - 1) ? "->" : "");
                }
                result.push_back(pathstr);
            } else {
                if (node->right) s.push(make_pair(node->right, level + 1));
                if (node->left) s.push(make_pair(node->left, level + 1));
            }
        }
        return result;
    }
};
///
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        string s;
        if (!root) return v;
        binaryTreePaths(root, s, v);
        return v;
    }
    void binaryTreePaths(TreeNode* r, string s, vector<string>& v) {
        if (!r) return;
        stringstream ss;
        ss << r->val;
        if (!r->left && !r->right) {
            v.push_back(s.empty()?(s+ss.str()):(s+'-'+'>'+ss.str()));
            return;
        }
        binaryTreePaths(r->left, s.empty()?(s+ss.str()):(s+'-'+'>'+ss.str()), v);
        binaryTreePaths(r->right, s.empty()?(s+ss.str()):(s+'-'+'>'+ss.str()), v);
    }
};
//////
typedef enum{L,R} tagtype;

struct stacknode
{
    TreeNode* ptr;
    tagtype tag;
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if(root == NULL)
            return res;
        TreeNode* p = root;
        stacknode x;
        stack<stacknode> s;

        do
        {
            while(p)
            {
                x.ptr = p;
                x.tag = L;
                s.push(x);
                path.push_back(p->val);
                p = p->left;
            }
            while(!s.empty() && s.top().tag == R)
            {
                x = s.top();
                s.pop();
                p = x.ptr;

                if(p->right == NULL && p->left == NULL)
                {
                    string t;
                    for(int i =0;i<path.size();i++)
                    {
                        if(i == 0)
                            t += std::to_string(path[i]);
                        else
                        {
                            t += "->";
                            t += std::to_string(path[i]);
                        }
                    }
                    res.push_back(t);
                }
                path.erase(path.end()-1);
            }
            if(!s.empty())
            {
                x = s.top();
                p = x.ptr;
                s.top().tag = R;
                p = p->right;
            }


        }while(!s.empty());
        return res;
    }
};
/////
class Solution {
private:
    vector<int> store;
    vector<string> result;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if( !root )
            return result;
        // push the value into vector
        store.push_back( root->val );
        // end if the node is a leaf
        if( !root->left && !root->right )
        {
            stringstream ss;
            ss << store[ 0 ];

            for( int i = 1; i < store.size(); i++ )
                ss << "->" << store[ i ];

            string temp;
            ss >> temp;
            result.push_back( temp );
        }

        binaryTreePaths( root->left );
        binaryTreePaths( root->right );

        store.pop_back();

        return result;
    }
};
///
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> ret;
        vector<int> c;
        if(root==nullptr)
            return ret;
        helper(root,ret,c);
        return ret;
    }
private:
    void helper(TreeNode *root,vector<string> &ret,vector<int> &nums)
    {
        nums.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr)
        {
            ret.push_back(arrayToString(nums));
            nums.pop_back();
            return;
        }
        else if(root->left && root->right==nullptr)
        {
            helper(root->left,ret,nums);
            nums.pop_back();
        }
        else if(root->right && root->left==nullptr)
        {
            helper(root->right,ret,nums);
            nums.pop_back();
        }
        else
        {
            helper(root->left,ret,nums);
            helper(root->right,ret,nums);
            nums.pop_back();
        }
    }
    string arrayToString(const vector<int> &res)
    {
        string ret;
        if(res.empty())
            return ret;
        ret+=to_string(res[0]);
        for(int i=1;i<res.size();++i)
            ret+=("->"+to_string(res[i]));
        return ret;
    }
};

///
1. pass string copy, it may waste some memory

class Solution {
public:
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root!=NULL) helper(root, "");
        return ans;
    }
    void helper(TreeNode* node, string s){
        s += s.empty() ? to_string(node->val) : "->" + to_string(node->val);
        if(!node->left && !node->right){
            ans.push_back(s);
            return;
        }
        if(node->left!=NULL) helper(node->left, s);
        if(node->right!=NULL) helper(node->right, s);
    }
};
2. use global string s, change its size during traverse

class Solution {
public:
    vector<string> ans;
    string s;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root!=NULL) helper(root);
        return ans;
    }
    void helper(TreeNode* node){
        int oldSize = s.size();
        s += s.empty() ? to_string(node->val) : "->" + to_string(node->val);
        if(!node->left && !node->right){
            ans.push_back(s);
            s.resize(oldSize);
            return;
        }
        if(node->left!=NULL) helper(node->left);
        if(node->right!=NULL) helper(node->right);
        s.resize(oldSize);
    }
};
update: Find out the maximum sum of value from root to each leaf in a binary tree.

int findMax(TreeNode *root){ //from root to each leaf
    if (root==NULL)
        return 0;
    else
        return max((findMax(root->left), findMax(root->right)) + root->val;
}
/////
class Solution {
    public:

            vector<string> binaryTreePaths(TreeNode* root) {
                vector<string> v;
                if(root)
                    preorder(v,root,"");
                return v;
            }
            void preorder(vector<string>& v,TreeNode* r,string t){
                if(!r)
                    return;
                if(!t.empty())
                    t+=("->"+to_string(r->val));
                else t+=to_string(r->val);
                if(r->left||r->right){
                    preorder(v,r->left,t);
                    preorder(v,r->right,t);
                }else{
                    v.push_back(t);
                }
            }
        };
/////
class Solution {
public:
    void preorder(TreeNode* root, string cur, vector<string> &res){
        cur += to_string(root->val);
        if (root->left == NULL && root->right == NULL){
            res.push_back(cur);
            return;
        }  else {
            cur += "->";
        }
        if (root->left) preorder(root->left, cur, res);
        if (root->right) preorder(root->right, cur, res);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root)  preorder(root, "", res);
        return res;
    }
};
///
class Solution {
public:

    using Elem = pair<TreeNode*, string>;
    using Stack = stack<Elem>;

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> paths;

        if(root)
        {
            Stack pool;
            pool.push(Elem(root, to_string(root->val)));

            while(!pool.empty())
            {
                auto p = pool.top();
                pool.pop();

                if(!p.first->left && !p.first->right)
                    paths.push_back(p.second);

                if(p.first->left)
                {
                    string nstring = p.second + "->" + to_string(p.first->left->val);
                    pool.push(Elem(p.first->left, nstring));
                }

                if(p.first->right)
                {
                    string nstring = p.second + "->" + to_string(p.first->right->val);
                    pool.push(Elem(p.first->right, nstring));
                }
            }
        }

        return paths;
    }
};
////
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> paths;

        if (root != nullptr)
            preDfs(root, path, paths);

        return paths;
    }

private:
    void preDfs(const TreeNode *node, vector<int> &path, vector<string> &pathVector) {
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            string pathStr(to_string(*path.begin()));
            for_each(path.begin()+1, path.end(), [&](int val) {pathStr.append("->" + to_string(val));});             
            pathVector.push_back(pathStr);
            return;
        }

        if (node->left != nullptr) {
            preDfs(node->left, path, pathVector);
            path.pop_back();
        }          
        if (node->right != nullptr) {
            preDfs(node->right, path, pathVector);
            path.pop_back();
        } 
    }        
};
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> paths;
        stack<pair<TreeNode *, int>> nodesUnexplored; //the second item indicates which level the node is at

        if (root != nullptr)
            nodesUnexplored.push(make_pair(root,0));

        while (!nodesUnexplored.empty()) {
            auto currNode = nodesUnexplored.top();
            nodesUnexplored.pop();

            while (currNode.second < path.size())
                path.pop_back();
            path.push_back(currNode.first->val);

            if (currNode.first->left == nullptr && currNode.first->right == nullptr) {
                string pathStr(to_string(path[0]));
                for_each(path.begin()+1, path.end(), [&](int val) {pathStr.append("->" + to_string(val));});
                paths.push_back(pathStr);
            }
            else {
                if (currNode.first->right != nullptr)
                    nodesUnexplored.push(make_pair(currNode.first->right, currNode.second+1));
                if (currNode.first->left != nullptr)
                    nodesUnexplored.push(make_pair(currNode.first->left, currNode.second+1));
            }
        }

        return paths;
    }
};
/////
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
    vector<string> result;
    void printTree(TreeNode* root, string path="")
    {
        if (root == NULL) return;
        stringstream ss;
        ss << root->val;
        string n;
        ss >> n;
        path += n;
        if (root->left == NULL && root->right ==NULL) {
            result.push_back(path);
        }
        path += "->";
        printTree(root->left, path);
        printTree(root->right, path);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        printTree(root);
        return result;   
    }
};
///
There are essentially the same.

But the first use a global vector recording current path during recursion. It may need extra caution to make sure it is correctly maintained.

The second solution pass current path in a temporal variable so it is easier to get it right.

class Solution {
public:
    vector<string> r;
    vector<string> binaryTreePaths(TreeNode* root) {
        // method 1 - dfs with a queue recording current path
        // vector<int> v;
        // dfs1(root,v);

        // method 2 - dfs but with no queue
        if(!root) return r;
        dfs2(root,"");
        return r;
    }

    //method 1 - dfs with a queue recording current path
    // root - the node we will visit
    // v    - a vector recording current path
    void dfs1(TreeNode *root, vector<int> &v) {
        if (!root) return;
        if (!root->left && !root->right) {
            string path = stringlize(v) + to_string(root->val);
            r.push_back(path);
            return;
        }

        v.push_back(root->val);
        dfs1(root->left,v);
        dfs1(root->right,v);
        v.pop_back();
    }

    string stringlize(vector<int> &values) {
        string s;
        for (int i = 0 ; i < values.size(); i++) {
            s += to_string(values[i]) + "->";
        }
        return s;
     }

    //method 2 - dfs with no queue recording current path
    //root: the node we will visit
    //p   : the path before root is visited
    void dfs2(TreeNode *root, string p) {
        if (!root) return;

        if (!root->left && !root->right) {
            string path = append(p,root->val);
            r.push_back(path);
            return;
        }

        dfs2(root->left, append(p,root->val));
        dfs2(root->right,append(p,root->val));
    }

    string append(string &p, int val) {
        return p.empty() ? to_string(val) : p + "->" + to_string(val);
    }

};
///
vector<string> binaryTreePaths(TreeNode* root) {
  if (root == nullptr)
    return {};
  if (root->left == nullptr && root->right == nullptr)
    return {to_string(root->val)};

  vector<string> left  = binaryTreePaths(root->left);
  vector<string> right = binaryTreePaths(root->right);
  left.insert(left.end(), begin(right), end(right));
  for (auto &e : left)
    e = to_string(root->val) + "->" + e;
  return left;
}
///
class Solution {

    void binary_tree_path_worker(TreeNode *node, string &path, vector<string> &out)
    {
        assert (node != NULL);
        path.append(to_string(node->val));

        if (node->left == NULL && node->right == NULL)
        {
            // this is a leaf, so we're done; push the currently built path string to our result container
            out.push_back(path);
            return;
        }

        // there is at least one child, so pre-emptively add the "->" characters
        path.append("->");

        string copy;            // for the right child to potentially use
        string *use = &path;

        if (node->left != NULL && node->right != NULL)
        {
            // there is a branching path; we need to create a copy of the buffer
            copy = path;
            use = &copy;        // definitely for the right child to use
        }

        if (node->left != NULL)
        {
            binary_tree_path_worker(node->left, path, out);
        }
        if (node->right != NULL)
        {
            binary_tree_path_worker(node->right, *use, out);
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;

        if (root == NULL)
        {
            return result;
        }

        string path;    // the initial buffer; will be copied over as paths branch
        binary_tree_path_worker(root, path, result);

        return result;
    }
};
////
class A is just used to display the data, like 1->2->3.So you can deal with the negative number as well

class A {
 public ArrayList<Integer> data = new ArrayList<Integer>();
 public String toString() {
     if (data.size() > 1) {
         StringBuilder s = new StringBuilder();
         s.append(data.get(0));
         for (int i = 1; i < data.size(); i++) {
            s.append("->" + data.get(i));
         }
         return s.toString();
     } else if (data.size() == 1){
         return data.get(0) + "";
     } 
     return "";
 }}
The second step is do some recursion.

public class Solution {
ArrayList hold = new ArrayList<String>();
A a = new A();

public List<String> binaryTreePaths(TreeNode root) {
    if (root == null) return hold;
    a.data.add(root.val);
    binaryTree(root);
    return hold ;

}

private void binaryTree(TreeNode root) {
    if (root.left == null && root.right == null) {
        hold.add(a.toString());
        return;
    }

    if (root.left != null) {
        a.data.add(root.left.val);
        binaryTree(root.left);
        a.data.remove(a.data.size() - 1);
    }

    if (root.right != null) {
        a.data.add(root.right.val);
        binaryTree(root.right);
        a.data.remove(a.data.size() - 1);
    }
}
}
////
This is the Frame:

def dfs(v):
    visit(v)
    stack.push(v)
    next = v
    while !stack.empty():
        while hasUnvisitedAdjacent(stack.top()):
            next = getUnvisitedAdjacent(stack.top())
            visit(next)
            stack.push(next)            
        stack.pop()  
This is the implemention:

class Solution {
    public:
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> res;
            if(!root) return res;

            dfs(root, res);

            return res;
        }
    private:
        void dfs(TreeNode* v, vector<string>& res)
        {
            string path  = to_string(v->val);
            searchStack.push(v);
            TreeNode* next = v;
            if(!next->left && !next->right) 
            {
                res.push_back(path);
                return;
            }
            while(!searchStack.empty())
            {
                while(hasUnvisitedAdjacent(searchStack.top()))
                {
                    next = getUnvisitedAdjacent(searchStack.top());

                    visit(next, path);
                    visitedNode.push_back(next);
                    searchStack.push(next);
                    if(!next->left && !next->right) res.push_back(path);
                }
                searchStack.pop();
                int found = 0;
                if ((found = path.rfind("->")) != string::npos ) path = path.substr(0, found);
            }
        }
        bool isVisited(TreeNode* v)
        {
            if(!v)
            {
                return true;
            }
            return find(visitedNode.begin(), visitedNode.end(), v) != visitedNode.end();
        }
        bool hasUnvisitedAdjacent(TreeNode* v)
        {
            return !isVisited(v->left) || !isVisited(v->right);
        }
        TreeNode* getUnvisitedAdjacent(TreeNode* v)
        {
            TreeNode* next = NULL;
            if(!isVisited(v->left))
            {
                next = v -> left;
            }
            else if(!isVisited(v->right))
            {
                next = v -> right;
            }
            return next;
        }
        void visit(TreeNode* v, string& out)
        {
            out += "->" + to_string(v->val);
        }
        stack<TreeNode*> searchStack;
        vector<TreeNode*> visitedNode;
    };

