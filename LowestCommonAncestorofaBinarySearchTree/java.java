public class Solution {
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode A, TreeNode B) {
        if (root == null) {
            return root;
        }
        while ((root.val - A.val) * (root.val - B.val) > 0) {
            if (root.val > A.val) {
                root = root.left;
            } else {
                root = root.right;
            }
        }
        return root;
    }
}
//////
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return root;
        TreeNode current = root;
        while (current != null && current != p && current != q){
            if (current.val <= p.val && current.val <= q.val) {
                current = current.right;
            } else if (current.val >= p.val && current.val >= q.val){
                current = current.left;
            } else {
                break;
            }
        }
        return current;
    }
///recursive
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null || root == p || root == q){
            return root;
        }

        if(root.val < Math.min(p.val, q.val)){
            return lowestCommonAncestor(root.right, p, q);
        }else if(root.val > Math.max(p.val, q.val)){
            return lowestCommonAncestor(root.left, p, q);
        }else{
            return root;
        }
    }
}
/////
public class Solution { public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

    if (nodeInTree(root.left,p,q)){
        return lowestCommonAncestor(root.left,p,q);
    }

    if (nodeInTree(root.right,p,q)){
        return lowestCommonAncestor(root.right,p,q);
    }

    return root;

}

public boolean nodeInTree(TreeNode root, TreeNode p, TreeNode q){
    if (root==null){return false;}
    boolean foundp = hasNode(root,p);
    boolean foundq = hasNode(root,q);
    return foundp && foundq;

}
public boolean hasNode(TreeNode root,TreeNode n){
    if (root==null){return false;}
    if (root==n) { return true;}
    return hasNode (root.left,n)||hasNode(root.right,n);
}
}
///
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {return root;}
        int i = Integer.compare(p.val, root.val);
        int j = Integer.compare(q.val, root.val);
        if (i < 0 & j < 0 & root.left != null) {
            return lowestCommonAncestor(root.left, p, q);
        } else if (i > 0 & j > 0 & root.right != null) {
            return lowestCommonAncestor(root.right, p, q);
        } else {
            return root;
        }
    }
/////
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || p == null && q == null) return null;
        if (p == null) return q;
        if (q == null) return p;

        LinkedList<TreeNode> leftStack = new LinkedList<>();
        LinkedList<TreeNode> rightStack = new LinkedList<TreeNode>();

        Queue<TreeNode> queue = new LinkedList<>();

        boolean foundLeft = false, foundRight = false;



        queue.add(root);

        while(!queue.isEmpty()){
            TreeNode cur = queue.poll();

            if (cur.val == p.val && cur.val == q.val) 
                return cur;

            if (cur.val == p.val){
                foundLeft = true;
                p = cur;
            }
            if (cur.val == q.val){
                foundRight = true;
                q = cur;
            }
            if (!foundLeft) leftStack.push(cur);
            if (!foundRight) rightStack.push(cur);

            if (foundLeft && foundRight) break;

            if (cur.left != null) queue.add(cur.left);
            if (cur.right != null) queue.add(cur.right);
        }

        if (!foundLeft || !foundRight) return null;

        if (leftStack.size() < rightStack.size())
            q = popStack(leftStack, rightStack, p, q);
        else if (leftStack.size() > rightStack.size()) 
            p = popStack(rightStack, leftStack, q, p);

        if (p == q) return p;

        while(!leftStack.isEmpty()){

            TreeNode cur = leftStack.pop();
            if (cur.left == p || cur.right == p) p = cur;
            if (cur.left == q || cur.right == q) q = cur;
             if (p == q) return p;
        }

        return null;
    }

    public TreeNode popStack(LinkedList<TreeNode> left, LinkedList<TreeNode> right, TreeNode p, TreeNode q){
        while (left.size() < right.size()){
            TreeNode cur = right.pop();
            if (cur.left == q || cur.right == q) q = cur;
            if (cur == p) break;
        }
        return q;
    }
}
///
Simple one : use the properties of binary search tree 1. val never duplicates 2. left node val< father node val<right node val

public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if(root.val> p.val && root.val>q.val) return lowestCommonAncestor(root.left, p, q);
    if(root.val<p.val && root.val<q.val) return lowestCommonAncestor(root.right, p, q);
    return root;
}
One with any value(could say binary tree) 1. write two more functions (find all the ancestors, check if the ancestor has this descendant or not) not good codes but solve two more issues(find all ancestor and check if ancestor has this descendant or not )

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if(p == root || q == root) return root;
    if(p == q || contains(p,q)) return p;// p is equal or upper level
    if(contains(q,p)) return q; //q is upper level
    TreeNode temp = p;
    while(temp!= root){
        temp = findFather(root,p);
        if(contains(temp,q)) 
            return temp;
        else
            p=temp;
    }
    return null;
}

public boolean contains(TreeNode ancestor, TreeNode descendant){
    //ancestor contains descendant or not
    if(ancestor == null) return false;
    if(ancestor.left == null && ancestor.right == null) return false;
    if(ancestor.left == descendant || ancestor.right == descendant) 
        return true;
    else
        return contains(ancestor.left, descendant) || contains(ancestor.right, descendant);
}
public TreeNode findFather(TreeNode root, TreeNode son){
    //return father node
    if(root == null) return null;
    if(root.left == null && root.right == null) return null;
    if(root.left == son || root.right == son) return root;
    if(findFather(root.left, son)!= null) return findFather(root.left, son);
    if (findFather(root.right,son)!=null) return findFather(root.right,son);
    return null;
}
///
public class Solution {
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if (root == null || p == null || q == null) return null;
    if (root.val > p.val && root.val > q.val) return lowestCommonAncestor(root.left, p, q);
    if (root.val < p.val && root.val < q.val) return lowestCommonAncestor(root.right, p, q);
    return root;
}
}
In BST, if p value and q value both less than the root value, then they are both in the left child, same to the right. If one is less or equal and other is larger or equal, then this node is the lowest common ancestor, then q and p separate(including themselves as LCA).
/////
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if (root == null || p == null || q == null) {
        if (root == null) {
            return null;
        } else if (p == null && q == null) {
            return root;
        }
        return p == null ? q : p;
    }

    int bigger = p.val > q.val ? p.val : q.val;
    int smaller = p.val < q.val ? p.val : q.val;

    if (root.val > bigger) {
        return this.lowestCommonAncestor(root.left, p, q);
    } else if (root.val < smaller) {
        return this.lowestCommonAncestor(root.right, p, q);
    } else if (root.val > smaller && root.val < bigger) {
        return root;
    } else {
        return root;
    }
}
///
if(root.val > p.val && root.val > q.val) return lowestCommonAncestor(root.left, p, q);
    else if(root.val < p.val && root.val < q.val) return lowestCommonAncestor(root.right, p, q);
    else return root;
/////
I don't know why no one was trying to explain the input here. Maybe I've been too rusty about my data structure, and this is the default representation of BST nodes as an array.

You can also checkout StefanPochmann's deserializer and visualizer, which is very useful.

The input reads like this for [5, 3, 6, 2, 4, null, null, 1]:

           5
         /   \
        3     6
       / \    / \
      2   4  N   N
     /
    1
where N is null.

Basically you go from top level to bottom, then left to right within the level, but it took me a few minutes before I figured out how it is represented. (I couldn't even find a question related about this, so I assume most people remember it from how they used to do it.)

Anyways, Here's my answer:

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode smallerNode;
        TreeNode largerNode;

        if(p.val < q.val) {
            smallerNode = p;
            largerNode = q;
        } else {
            smallerNode = q;
            largerNode = p;
        }

        // if one is on your left, another on your right
        // or if one is yourself, and the other on either side
        // then the current root is the LCA
        if( smallerNode.val <= root.val && largerNode.val >= root.val ) {
            return root;
        } else if (largerNode.val < root.val) { //decide which way to go..
            return lowestCommonAncestor(root.left, smallerNode, largerNode);
        } else {
            return lowestCommonAncestor(root.right, smallerNode, largerNode);
        }
    }
}
/////
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null || p == null || q ==null)
            return null;
        TreeNode max = (p.val > q.val)?p:q;
        TreeNode min = (p.val > q.val)?q:p;
        if(root.val <= max.val && root.val >= min.val)
            return root;
        else if(root.val > max.val){
            root = root.left;
        }else{
            root = root.right;          
        }
        return lowestCommonAncestor(root, p, q);      
    }
}
//
public class Solution {
List<TreeNode> listP=new ArrayList<TreeNode>();
List<TreeNode> listQ=new ArrayList<TreeNode>();
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if(!findPath(root, p, listP) || !findPath(root, q, listQ)) return null;
    int i=0;
    for(i=0; i<listP.size() && i<listQ.size(); i++){
        if(listP.get(i)!=listQ.get(i)) break;
    }
    return listP.get(i-1);

}
public boolean findPath(TreeNode root, TreeNode p, List<TreeNode> list){
    if(root==null) return false;
    list.add(root);
    if(root.val==p.val) return true;
    if(findPath(root.left, p, list)||findPath(root.right, p, list)) return true;
    list.remove(root);
    return false;
  }
}
///
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        while(true){
          if((root.val-p.val)*(root.val-q.val)<=0) return root;
          if(p.val<root.val){
             root=root.left;
          }
         else{
              root=root.right;
          }
        }
    }
}
///
public class Solution {
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if((p.val<=root.val&&q.val>=root.val)||(p.val>=root.val&&q.val<=root.val)){
        return root;
    }
    else if(p.val<root.val&&q.val<root.val){
        return lowestCommonAncestor(root.left,p,q);
    }
    else{
        return lowestCommonAncestor(root.right,p,q);
    }
}
}
///
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if ((root.val - p.val)*(root.val - q.val) <= 0) {return root;}
    else if (root.val - p.val > 0) {return lowestCommonAncestor(root.left, p, q);}
    else {return lowestCommonAncestor(root.right, p, q);}
}
///
return ((p.val-root.val)*(q.val-root.val)<=0) ? root : lowestCommonAncestor(p.val>root.val?root.right:root.left, p, q);

///
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
         if(root==null)
             return null;
         if(p.val<root.val&&q.val<root.val)
         {
             return lowestCommonAncestor(root.left,p,q);
         }
         if(p.val>root.val&&q.val>root.val)
         {
             return lowestCommonAncestor(root.right,p,q);
         }else{

             return root;
         }
    }
}
///
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    List<TreeNode> pList = new ArrayList<TreeNode>();
    List<TreeNode> qList = new ArrayList<TreeNode>();

    getPath(root, p, pList);
    getPath(root, q, qList);

    int len = pList.size() >= qList.size() ? qList.size() - 1 : pList.size() - 1;
    for (int i = len; i >= 0; i --) {
        if (pList.get(i) == qList.get(i)) {
            return pList.get(i);
        }
    }
    return null;
}

private void getPath(TreeNode root, TreeNode node, List<TreeNode> list) {
    TreeNode p = root;
    list.add(p);

    while (p != null && p != node) {
        if (p.val < node.val) {
            p = p.left;
            list.add(p);
        } else {
            p = p.right;
            list.add(p);
        }
    }
    list.add(p);
}
///
public class Solution {
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if(p==null||q==null) return null;
    TreeNode result = root;
    TreeNode node = root;
    boolean flag = false;
    while(node!=null){
        if(p.val<node.val&&q.val<node.val) node = node.left;//to the left subtree
        else if(p.val>node.val&&q.val>node.val) node = node.right;//to the right subtree
        else{
            result = node;//save the probable result
            for(int i=0;i<2;i++,node=result,p=q){//make sure p and q belong to this tree.
                while(node!=null){
                    if(p.val<node.val) node = node.left;
                    else if(p.val>node.val) node = node.right;
                    else {
                        flag = true;
                        break;
                    }
                }
                if(!flag) return null;//the current p or q is not in this tree
                flag = false;//continue to make sure q in this tree
            }
            break;
        }
    }
    return result;
}
}
///
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    TreeNode r=root;
    if(p.val==q.val)return p;
    while(r!=null){
        if((p.val-r.val)*(q.val-r.val)<=0)return r;
        if(p.val>r.val)r=r.right;
        else
            r=r.left;
    }
    return r;
}
///
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null||p.val==root.val||q.val==root.val||(p.val-root.val)*(q.val-root.val)<0) return root;
        if(p.val>root.val&&q.val>root.val)return lowestCommonAncestor(root.right,p,q);
        else return lowestCommonAncestor(root.left,p,q);
    }
}
//
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        if(root==null || root==p || root==q) return root;

        TreeNode left = lowestCommonAncestor(root.left,p,q);
        TreeNode right = lowestCommonAncestor(root.right,p,q);

        if(left==null) return right;
        if(right==null) return left;

        return root;
    }
}
//
public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root.val > p.val && root.val > q.val){
            return lowestCommonAncestor(root.left, p, q);
        }else if(root.val < p.val && root.val < q.val){
            return lowestCommonAncestor(root.right, p, q);
        }else{
            return root;
        }
    }
}
//A non-recursive version.

public class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        while (true) {
            if (root.val > p.val && root.val > q.val)
                root = root.left;
            else if (root.val < p.val && root.val < q.val)
                root = root.right;
            else
                return root;
        }
    }
}
