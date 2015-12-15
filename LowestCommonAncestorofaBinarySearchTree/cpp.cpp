TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val>root->val && q->val>root->val) 
        return lowestCommonAncestor(root->right,p,q);
    if (p->val<root->val && q->val<root->val) 
        return lowestCommonAncestor(root->left,p,q);
    return root;
}
////
If p is ancestor of q or vice versa. case 3 never happens. Only need to use found p/q to represent the ancestor (case 2).
Otherwise, there is only one node having the case 3, and it is the lowestCommonAncestor.
Other cases(1/4/5/6) are just to propagate the found ancestor.

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    // return value 
    //   null: not found
    //   non-null: having a represented node

    // case 1: root is null, not found.
    if(!root){ return nullptr; }

    // case 2: p/q found, propagate the p or q
    if(root == p || root == q){ return root; }

    TreeNode* left_side = lowestCommonAncestor(root->left, p, q);
    TreeNode* right_side = lowestCommonAncestor(root->right, p, q);

    // case 3: if left_side and right_side are both found, the none p/q lowestCommonAncestor found.
    if(left_side && right_side){ return root; }

    // case 4: if only left_side found, propagate the result(case 2 and 3)
    if(left_side) { return left_side; }

    // case 5: if only right_side found, propagate the result(case 2 and 3)
    if(right_side) { return right_side; }

    // case 6: nothing found
    return nullptr;
}
/////
I didn't pay attention to the "BST" in the problem. As a result, I did a 44ms Cpp solution working with general binary tree structure. The program doesn't check for values.

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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool foundP = false;
        bool foundQ = false;
        return findComm(root, p, q, &foundP, &foundQ);
    }
private:
    TreeNode* findComm(TreeNode* root, TreeNode* p, TreeNode* q, bool* foundP, bool* foundQ)
    {
        if(root == NULL)    
            return NULL;

        bool tempP = *foundP;
        bool tempQ = *foundQ;
        bool dummyF = false;
        TreeNode* r = findComm(root->left, p, q, foundP, foundQ);
        //returned LCA, then pass along back to top level
        if(r != NULL)   
            return r;

        if(tempP != *foundP)
        {
            //P found in left branch, then dont let right branch know P is found
            r = findComm(root->right, p, q, &dummyF, foundQ);
        }
        else if(tempQ != *foundQ)
        {
            //Q found in left branch, then dont let right branch know Q is found
            r = findComm(root->right, p, q, foundP, &dummyF);
        }
        else
        {
            //neither Q nor P was found yet, pass along
            r = findComm(root->right, p, q, foundP, foundQ);
        }
        //returned LCA, then pass along back to top level
        if(r != NULL)   
            return r;

        if(root == p)       
            *foundP = true;
        if(root == q)       
            *foundQ = true;

        //under current root, if both P and Q already found, this is LCA
        if(*foundQ && *foundP)  
            return root;
        return NULL;
    }
};

///
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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *lca = root;
        while (lca) {
            if (lca == p || lca == q || (lca->val > min(p->val, q->val) && lca->val < max(p->val, q->val)) )
                break;
            else if (lca->val < min(p->val, q->val))
                lca = lca->right;
            else if (lca->val > max(p->val, q->val))
                lca = lca->left;
        }
        return lca;
    }
};
///
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> stack;
        TreeNode* node = root;
        TreeNode* lca = NULL;
        TreeNode* n1 = NULL;
        TreeNode* n2 = NULL;
        if(p->val < q->val)
        {
            n1 = p;
            n2 = q;
        }
        else
        {
            n1 = q;
            n2 = p;
        }
        while(node)
        {
            stack.push_back(node);
            if(node->val == n1->val)  // searching for the smaller one;
            {
                lca = node;
                break;
            }
            else if(node->val > n1->val)
                node = node->left;
            else
                node = node->right;
        }

        if(!lca) return NULL; // not found p in the tree

        while(stack.size() > 0)
        {
            lca = stack.back();
            stack.pop_back();
            node = lca;
            while(node)
            {
                if(node->val == n2->val)
                    return lca;
                else if (node->val > n2->val)
                    node = node->left;
                else
                    node = node->right;
            }
        }
        return NULL;

    }
};
///
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        // check if the current value is larger than both nodes , go left
        if(p->val < root->val && q->val < root->val){
            lowestCommonAncestor(root->left , p , q);
         // go right
        }else if(p->val > root->val && q->val > root->val){
            lowestCommonAncestor(root->right , p , q);
        }// my LCA 
        else{
            return root;
        }
    }
};
///
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( ( root->val >= p->val && root->val <= q->val )
         || ( root->val >= q->val && root->val <= p->val ) )
            return root;

        else if( root->val < p->val && root->val < q->val )
            return lowestCommonAncestor( root->right, p, q );

        else
            return lowestCommonAncestor( root->left, p, q );
    }
};
///
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        TreeNode* small = NULL;
        TreeNode* big = NULL;
        (p->val > q->val) ? (big = p, small = q) : (big = q, small = p); 
        if (root == p || root == q || root == NULL) return root;
        if (root->val > big->val) left = lowestCommonAncestor(root->left, small, big);
        else if (root->val < small->val) right = lowestCommonAncestor(root->right, small, big);
        else {
            left = lowestCommonAncestor(root->left, small, big);
            right = lowestCommonAncestor(root->right, small, big);
        }
        return left && right ? root : left ? left : right;
    }
};
///
There is some (very) redundant searching in this bit of code. Would only be needed for a generic binary tree, but for a BST we do not need the isUnder() function at all. I will shortly post a better version.

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
public:
    bool isUnder(TreeNode* root, TreeNode* x) {
        if (root == NULL)
            return false;

        if (
                (root == x) ||
                isUnder(root->left, x) ||
                isUnder(root->right, x)
                )
            return true;
        else
            return false;

    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // swap p and q if p has a larger val.
        if (p->val > q->val)
        {
            TreeNode* swap = p;
            p = q;
            q = swap;
        }

        bool p_isLeft = isUnder(root->left, p);
        bool q_isRight = isUnder(root->right, q);

        bool p_isRight = isUnder(root->right, p);
        bool q_isLeft = isUnder(root->left, q);

        // Is p left or myself?
        // Is q right or myself?
        // If both yes, then I am the LCA;
        if ( (p_isLeft || (p == root)) && (q_isRight || (q == root)) )
            return root;

        // Are both p and q to the left? Then the LCA is somewhere under my left node.
        if ( p_isLeft && q_isLeft )
            return lowestCommonAncestor(root->left, p, q);

        // Are both p and q to the right? Then the LCA is somewhere under my right node.    
        if ( p_isRight && q_isRight )
            return lowestCommonAncestor(root->right, p, q);
    }
};
///
The first solution works for a general binary tree where we can't rely on any ordering of the nodes:

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) { return nullptr; }
        if (root == p || root == q) { return root; }
        auto l = lowestCommonAncestor(root->left, p, q), r = lowestCommonAncestor(root->right, p, q);
        return l && r ? root : l ? l : r;

    }
};
The second solution assumes a BST ordering to avoid searching much of the tree:

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) { std::swap(p, q); }
        while (root->val < p->val || root->val > q->val) {
            while (root->val < p->val) { root = root->right; }
            while (root->val > q->val) { root = root->left; }
        }
        return root;
    }
};
///
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root)
        {
            if((p->val - root->val)*(q->val - root->val) <=  0) /*if p is not in the same subtree as q*/
                return root;
            root = (p->val < root->val)?root->left:root->right;
        }
    }
};
///
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> pPath, qPath;
        TreeNode *pointer = root;
        // Get the path to p
        while(pointer->val != p->val) {
            if(pointer->val > p->val) {
                pPath.push_back(0);
                pointer = pointer->left;
            }
            else {
                pPath.push_back(1);
                pointer = pointer->right;
            }
        }
        pointer = root;
       // Get the path to q
        while(pointer->val != q->val) {
            if(pointer->val > q->val) {
                qPath.push_back(0);
                pointer = pointer->left;
            }
            else {
                qPath.push_back(1);
                pointer = pointer->right;
            }
        }
        pointer = root;
        for(int i = 0; i < pPath.size() && i < qPath.size(); i++) {
            // q and q belongs to the different child of pointer, so pointer is the LCA
            if(pPath[i] != qPath[i])
                return pointer;
            else {// Go to the left child of pointer
                if(pPath[i] == 0)
                    pointer = pointer->left;
                else // Go to the right child of pointer
                    pointer = pointer->right;
            }
        }
        // One is the ancestor of the other
        return pointer;
    }
};
///
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == p || root == q) return root;
        bool b1 = root->val > p->val, b2 = root->val > q->val;
        return b1 & b2 ? lowestCommonAncestor(root->left, p, q) : b1 || b2 ? root : lowestCommonAncestor(root->right, p, q);
    }
};
/////
class Solution { public:

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int max = p->val > q->val ? p->val: q->val;
    int min = p->val < q->val ? p->val: q->val;

    if(root->val > max)
    {
        return lowestCommonAncestor(root -> left, p, q);
    }

    if(root->val < min)
    {
        return lowestCommonAncestor(root -> right, p, q);
    }

    return root;
}
};
///
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > root->val && q->val < root->val)
        {
            return root;
        }
        if(p->val < root->val && q->val > root->val)
        {
            return root;
        }
        if( p->val == root->val || q->val == root->val)
            return root;

        if( p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        if( p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
    }
/////
Well, remember to take advantage of the property of binary search trees, which is, node -> left -> val < node -> val < node -> right -> val. Moreover, both p and q will be the descendants of the root of the subtree that contains both of them. And the root with the largest depth is just the lowest common ancestor. This idea can be turned into the following simple recursive code.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p -> val < root -> val && q -> val < root -> val)
            return lowestCommonAncestor(root -> left, p, q);
        if (p -> val > root -> val && q -> val > root -> val)
            return lowestCommonAncestor(root -> right, p, q);
        return root;
    }
};
Of course, we can also solve it iteratively.

class Solution { 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (true) {
            if (p -> val < cur -> val && q -> val < cur -> val)
                cur = cur -> left;
            else if (p -> val > cur -> val && q -> val > cur -> val)
                cur = cur -> right;
            else return cur; 
        }
    }
};
///
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val == root->val || q->val == root->val || (p->val < root->val && q->val > root->val) || (q->val < root->val && p->val > root->val))
        {
            return root;
        }
        else if(p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        else
            return lowestCommonAncestor(root->right,p,q);
    }
};
///
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p || root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if(left && right) return root;
    return left? left : right;
}
///
Just do it recursively, if one of p or q is root, then return root,

if p (or q) is in the left subtree with the other is in the right
subtree (case 1), return root too
if p and q are both in the left subtree (case 0), check in the left subtree

if p and q are both in the right (case 2) subtree, check in the right subtree

class Solution {
public: 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        switch( (p->val>root->val) + (q->val>root->val))
        {
            case 0: return lowestCommonAncestor(root->left, p, q);
            case 1: return root;
            case 2: return lowestCommonAncestor(root->right, p, q);
        }
    }
};
///
My C++ solution is as follow, very simple and easy to understand.

In general, it is based on the basic searching on BST and comparing pointers. That's all.

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if ( !root || !p || !q ) { return NULL; }
    TreeNode* ans = root;
    TreeNode* r = root; // for search node p
    TreeNode* k = root; // for search node q
    while ( r != p || k != q ) {
        if ( p->val < r->val ) {
            r = r->left;
        } else if ( p->val > r->val ) {
            r = r->right;
        }
        if ( q->val < k->val ) {
            k = k->left;
        } else if ( q->val > k->val ) {
            k = k->right;
        }

        if ( r == k ) {
            ans = r;
        } else {
            break;
        }
    }

    return ans;
}
///
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {


        while(root)// this also covers corner condition when root is nullptr

            if(root->val>max(p->val,q->val))// ancestor is in the left
            root=root->left;
            else if(root->val<min(p->val,q->val))// ancestor is in the right
            root=root->right;
            else// ancestor is found
            break;

        return root;

    }
};
//
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if ((root->val - p->val) * (root->val - q->val) <=0)
    // p & q on different sides, or p or is root itself
        return root;
    else if (root->val > p->val)
        return lowestCommonAncestor(root->left, p, q);
    else
        return lowestCommonAncestor(root->right, p, q);
}
