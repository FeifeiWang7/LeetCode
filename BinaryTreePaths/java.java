public class Solution {

     String res = "";
     List<String> resList= new ArrayList<String>();

     public  List<String> binaryTreePaths(TreeNode root) {
      if(root== null)
      {   
       return resList;
      }
      res+= root.val;
      res+= "->";

      if(root.left== null&&root.right== null) 
      {
      res = res.substring(0, res.length()-2);// remove '"->" in the end
      resList.add(res);
      res = res.substring(0, res.length()-Integer.toString(root.val).length()); // remove the root
      return resList;
      }

      binaryTreePaths(root.left);
      binaryTreePaths(root.right);
      res = res.substring(0, res.length()-2-Integer.toString(root.val).length()); // remove the root and "->" in the end
      return resList;

    }
}
///
class Solution {
    deque<TreeNode*> path;
    vector<string> paths;
    void findPaths(TreeNode* root)
    {
        if (!root) return;
        path.push_back(root);
        if (!root->left && !root->right)
        {
            string path_str = to_string(path[0]->val);
            for (int i = 1; i < path.size(); i++)
                path_str += ("->" + to_string(path[i]->val));
            path.pop_back(); paths.push_back(path_str);
            return;
        }
        findPaths(root->left);
        findPaths(root->right);
        path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        findPaths(root);
        return paths;
    }
};
///
public class Solution {
      public class wrapper {
        TreeNode tn;
        String s;
        public wrapper(TreeNode t, String s) {
            tn = t;
            this.s = s;
        }
    }
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<String>();         // if you hit a null put the sequence to the result
        if (root == null) return res;
        wrapper rw = new wrapper(root, String.valueOf(root.val));
        Stack<wrapper> stk = new Stack<wrapper>();
        stk.push(rw);
        while (!stk.isEmpty()) {
            wrapper temp = stk.pop();
            if (temp.tn.left == null && temp.tn.right == null) res.add(temp.s);
            if (temp.tn.left != null) stk.push(new wrapper(temp.tn.left, temp.s + "->" + temp.tn.left.val));
            if (temp.tn.right != null) stk.push(new wrapper(temp.tn.right, temp.s + "->" + temp.tn.right.val));
        }

        return  res;

    }
}
///
public class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> rst = new ArrayList<String>();
        if(root == null) return rst;
        StringBuilder sb = new StringBuilder();
        helper(rst, sb, root);
        return rst;
    }

    public void helper(List<String> rst, StringBuilder sb, TreeNode root){
        if(root == null) return;
        int tmp = sb.length();
        if(root.left == null && root.right == null){
            sb.append(root.val);
            rst.add(sb.toString());
            sb.delete(tmp , sb.length());
            return;
        }
        sb.append(root.val + "->");
        helper(rst, sb, root.left);
        helper(rst, sb, root.right);
        sb.delete(tmp , sb.length());
        return;

    }
}
/////
I simply do a DFS traversal with a stack, and I store current path in a list. Main point is to detect "way back" by pushing current node to stack if it is not the same as last entry in path.

   public List<String> binaryTreePaths(TreeNode root) {
        if(root == null){
            return Collections.emptyList();
        }
        List<String> res = new ArrayList<>();

        Deque<TreeNode> st = new ArrayDeque<>();
        Deque<TreeNode> path = new ArrayDeque<>();

        st.addFirst(root);
        while(!st.isEmpty()){
            root = st.removeFirst();
            if(root != path.peekLast()){
                path.addLast(root);
                st.addFirst(root);
            }
            else{
                path.removeLast();
                continue;
            }
            if(root.left == null && root.right == null){
                Iterator<TreeNode> iter = path.iterator();
                StringBuilder tmp = new StringBuilder(path.size() *3 - 2);
                tmp.append(Integer.toString(iter.next().val));
                while(iter.hasNext()){
                    tmp.append("->");
                    tmp.append(Integer.toString(iter.next().val));
                }
                res.add(tmp.toString());
            }
            if(root.left != null){
                st.addFirst(root.left);
            }
            if(root.right != null){
                st.addFirst(root.right);
            }
        }
        return res;
    }
///
Lot of recursive solutions on this forum involves creating a helper recursive function with added parameters. The added parameter which usually is of the type List , carries the supplementary path information. However, the approach below doesn't use such a helper function.

public List<String> binaryTreePaths(TreeNode root) {

        List<String> paths = new LinkedList<>();

        if(root == null) return paths;

        if(root.left == null && root.right == null){
            paths.add(root.val+"");
            return paths;
        }

         for (String path : binaryTreePaths(root.left)) {
             paths.add(root.val + "->" + path);
         }

         for (String path : binaryTreePaths(root.right)) {
             paths.add(root.val + "->" + path);
         }

         return paths;

    }
//////////
Codes:

public class Solution { private String printStack(TreeNode leaf, Map<TreeNode, TreeNode> parentMap) {

    String separator = "->";

    ArrayList<TreeNode> path = new ArrayList<TreeNode>();
    TreeNode current = leaf;
    while (current != null) {
        path.add(current);

        current = parentMap.get(current);
    }
    StringBuilder builder = new StringBuilder();
    ListIterator<TreeNode> reverseIterator = path.listIterator(path.size());
    while (reverseIterator.hasPrevious()) {
        TreeNode node = reverseIterator.previous();

        builder.append(node.val);
        builder.append(separator);
    }

    return builder.substring(0, builder.length() - separator.length());
}

public List<String> binaryTreePaths(TreeNode root) {
    ArrayList<String> result = new ArrayList<String>();
    if (root == null) {
        return result;
    }

    ArrayList<TreeNode> nodeStack = new ArrayList<TreeNode>();
    ArrayList<Boolean> booleanStack = new ArrayList<Boolean>();
    HashMap<TreeNode, TreeNode> parentMap = new HashMap<TreeNode, TreeNode>();

    nodeStack.add(root);
    booleanStack.add(false);
    while (nodeStack.size() > 0) {
        TreeNode current = nodeStack.get(nodeStack.size() - 1);
        boolean visited = booleanStack.get(booleanStack.size() - 1);
        if (visited) {
            nodeStack.remove(nodeStack.size() - 1);
            booleanStack.remove(booleanStack.size() - 1);
        } else {
            booleanStack.set(booleanStack.size() - 1, true);
            boolean isLeaf = true;
            if (current.left != null) {
                nodeStack.add(current.left);
                booleanStack.add(false);
                parentMap.put(current.left, current);
                isLeaf = false;
            }

            if (current.right != null) {
                nodeStack.add(current.right);
                booleanStack.add(false);
                parentMap.put(current.right, current);
                isLeaf = false;
            }

            if (isLeaf) {
                result.add(printStack(current, parentMap));
            }
        }
    }

    return result;
}
}

/////
public class Solution {
    List<String> result = new ArrayList<String>();
    public List<String> binaryTreePaths(TreeNode root) {
        dfs(root, "");
        return result;
    }

    void dfs(TreeNode node, String path) {
        if(node == null)
            return;
        path = path + node.val;
        if(isLeafNode(node))
            result.add(path);
        path = path + "->";
        dfs(node.left, path);
        dfs(node.right, path);
    }

    boolean isLeafNode(TreeNode node) {
        return node.left == null && node.right == null;
    }
}
/////
public class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> l=new ArrayList<>();
        if(root!=null)
            pre(l,root,"");
        return l;
    }
     void pre(List<String> l,TreeNode r,String s){
         if(r==null)return;
         if(s.isEmpty())
            s+=r.val;
        else s+=("->"+r.val);
        if(r.left!=null||r.right!=null){
            pre(l,r.left,s);
            pre(l,r.right,s);
        }else
            l.add(s);
     }
}
///
public class Solution {
public List<String> binaryTreePaths(TreeNode root) {
    List<String> paths = new LinkedList<String>();
    if(root != null)
    binaryTreePaths(root,paths, "");
    return paths;
}
public void binaryTreePaths(TreeNode root, List<String> paths, String path) {
    StringBuilder pathb = new StringBuilder(path);
    pathb.append(root.val);
    if(root.left == null && root.right == null) {
        paths.add(pathb.toString());
        return;
    } else {
        pathb.append("->");
        String curPath = pathb.toString();
        if(root.left != null) binaryTreePaths(root.left, paths, curPath);
        if(root.right != null) binaryTreePaths(root.right,paths, curPath);
    }
}
}
/////
public class Solution {
public List<String> binaryTreePaths(TreeNode root) {
    List<String> res = new ArrayList<>();
    if(root==null) return res;
    String tmp = ""+root.val;
    helper(root,res,tmp);
    return res;
}
private void helper(TreeNode root, List<String> res, String tmp) {
    if(root.left==null&&root.right==null) {
        res.add(tmp);
    } else {
        if(root.left!=null) helper(root.left, res, tmp+"->" + root.left.val);
        if(root.right!=null) helper(root.right, res, tmp+"->" + root.right.val);
    }
}
}
/////
The basic idea is DFS using stack to record every path to leaf. Also, I use one stringbuilder to track the path in string.

public class Solution {
public List<String> binaryTreePaths(TreeNode root) {
    List<String> result = new ArrayList<String>();
    //quick sole
    if(root == null){
        return result;
    }

    //initial
    StringBuilder sb = new StringBuilder();
    TreeNode current = root;
    TreeNode pre = root;
    Stack<TreeNode> st = new Stack<TreeNode>();

    st.push(current);
    sb.append(current.val);

    while(current.left!=null){
        st.push(current.left);
        sb.append("->");
        sb.append(current.left.val);
        current = current.left;
    }

    while(!st.empty()){
        if(st.peek().left==null && st.peek().right==null){
            result.add(sb.toString());
        }

        if(st.peek().right==null || st.peek().right==pre){
            pre = st.pop();
            sbPop(sb);
        }else{
            current = st.peek().right;
            while(current!=null){
                st.push(current);
                sb.append("->");
                sb.append(current.val);
                current = current.left;
            }
        }

    }

    return result;
}

private void sbPop(StringBuilder sb){
    int index = 0;
    for(int i=sb.length()-1;i>=0;i--){
        if(sb.charAt(i)=='-' && sb.charAt(i+1)=='>'){
            index = i;
            break;
        }
    }
    sb.setLength(index);
}
}
////
public List<String> binaryTreePaths(TreeNode root) {
    List<String> paths = new ArrayList<>();
    binaryTreePaths(root, paths, new StringBuilder());
    return paths;
}

public void binaryTreePaths(TreeNode root, List<String> paths, StringBuilder builder) {
    if(root == null) return;
    if(root.left == null && root.right == null) paths.add(builder.append("->").append(root.val).substring(2));
    builder.append("->").append(root.val);
    if(root.left != null) binaryTreePaths(root.left, paths, new StringBuilder(builder.toString()));
    if(root.right != null) binaryTreePaths(root.right, paths, new StringBuilder(builder.toString()));
}
///
public List<String> binaryTreePaths(TreeNode root) {
    List<String> answer = new ArrayList<String>();
    if (root != null) searchBT(root, "", answer);
    return answer;
}
private void searchBT(TreeNode root, String path, List<String> answer) {
    if (root.left == null && root.right == null) answer.add(path + root.val);
    if (root.left != null) searchBT(root.left, path + root.val + "->", answer);
    if (root.right != null) searchBT(root.right, path + root.val + "->", answer);
}
///I see people interview FB meet this question in phone screen. It's simple. But interviewer will ask you about time complexity. The worst case is not that straight-forward. You should try to construct a tree with that 'worst case'. Assume the number of treeNode is n, you need to provide the big O notation of n.

///
public class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<List<Integer>> paths = new ArrayList<List<Integer>>();
        getPaths(root, new LinkedList<Integer>(), paths);
        List<String> result = new ArrayList<String>();
        StringBuilder b = new StringBuilder();
        for (List<Integer> path:paths){
            b.setLength(0);
            b.append(path.remove(0));
            for (int i:path){
                b.append("->").append(i);
            }
            result.add(b.toString());
        }
        return result;
    }

    private void getPaths(TreeNode parent, List<Integer> path, List<List<Integer>> paths){
        if (parent!=null){
            path.add(parent.val);
            if (parent.left == null && parent.right == null){
                paths.add(new LinkedList<Integer>(path));
            }
            getPaths(parent.left, path, paths);
            getPaths(parent.right, path, paths);
            path.remove(path.size()-1);
        }
    }
}
///
public class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> result = new ArrayList<>();
        Stack<Integer> path = new Stack<Integer>();
        binaryTreePathsHelper(root, path, result);
        return result;
    }

    private void binaryTreePathsHelper(TreeNode root, Stack<Integer> path, List<String> result) {
        if (root == null)  return;
        path.push(root.val);
        if (root.left == null && root.right == null){
            // process result
            StringBuilder sb = new StringBuilder();
            for (Integer nd : path){
                sb.append(nd);
                sb.append("->");
            }
            result.add(sb.substring(0, sb.length() - 2));
        }
        binaryTreePathsHelper(root.left, path, result);
        binaryTreePathsHelper(root.right, path, result);
        path.pop(); // remove parent
    }
}
////
public class Solution {

public List<String> binaryTreePaths(TreeNode root) {

    List<String> ret = new ArrayList<String>();

    if(root == null){
        return ret;
    }

    dfs(root, new StringBuilder(), ret);

    return ret;
}

public void dfs(TreeNode root, StringBuilder sb, List<String> ret){

   if(root.left == null && root.right == null){
       sb.append(root.val);
       ret.add(sb.toString());
       return;
   }

   sb.append(root.val);
   sb.append("->");

   if(root.left != null){
       dfs(root.left, new StringBuilder(sb), ret);
   }

   if(root.right != null){
       dfs(root.right, new StringBuilder(sb), ret);
   }
}
}

////
public class Solution {

List<String> paths = new ArrayList<String>(); 
String curPath = ""; 

public List<String> binaryTreePaths(TreeNode root) {

    if(root==null){
        return paths ;
    }

    searchTree(root,curPath);

    return paths ;


}

public void searchTree(TreeNode root,String curPath){


    curPath += root.val ;


    // add curPath to paths
    if(root.left==null && root.right==null){

        paths.add(curPath);

        return ;

    }

    curPath += "->" ; 

    if(root.left != null)
        searchTree(root.left,curPath);

    if(root.right != null)    
        searchTree(root.right,curPath);

}
}
///
recursion(308ms):

public List<String> binaryTreePaths(TreeNode root) {
    List<String> result=new ArrayList<String>();
    if(root==null)return result;
    helper(result,root,"");
    return result;
}
private void helper(List<String> result,TreeNode root,String str){
    str+=root.val;
    if(root.left==null&&root.right==null){
        result.add(str);
        return;
    }
    if(root.left!=null){
        helper(result,root.left,str+"->");
    }
    if(root.right!=null){
        helper(result,root.right,str+"->");
    }
}
iteration(304ms):

public List<String> binaryTreePaths(TreeNode root) {
    Queue<TreeNode> nodes=new LinkedList<TreeNode>();
    Queue<String> strs=new LinkedList<String>();
    List<String> result=new ArrayList<String>();
    if(root!=null){
        nodes.offer(root);
        strs.offer(Integer.toString(root.val));
    }
    while(!nodes.isEmpty()){
        TreeNode node=nodes.poll();
        if(node.left==null&&node.right==null){
            result.add(strs.poll());
        }else{
            String newStr=strs.poll();
            if(node.left!=null){
                nodes.offer(node.left);
                strs.offer(newStr+"->"+node.left.val);
            }
            if(node.right!=null){
                nodes.offer(node.right);
                strs.offer(newStr+"->"+node.right.val);
            }
        }
    }
    return result;
}
///
public class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> paths = new ArrayList<>();
        List<TreeNode> buffer = new ArrayList<>();
        getPaths(root, buffer, paths);
        return paths;
    }

    private void getPaths(TreeNode root, List<TreeNode> buffer, List<String> results) {
        if (root == null) {
            return;
        }
        if (root.left == null && root.right == null) {
            StringBuilder sb = new StringBuilder();
            for (TreeNode n : buffer) {
                sb.append(n.val).append("->");
            }
            sb.append(root.val);
            results.add(sb.toString());
        }
        else {
            buffer.add(root);
            getPaths(root.left, buffer, results);
            getPaths(root.right, buffer, results);
            buffer.remove(buffer.size() -1);
        }
    }
}
///
public List<String> binaryTreePaths(TreeNode root) {
    List<String> ans = new ArrayList<String>();
    List<Integer> temp = new ArrayList<Integer>();

    if(root == null){
        return ans;
    }

    temp.add(root.val);
    useme(ans,temp,root);
    return ans;
}

public void useme(List<String> ans,List<Integer> temp, TreeNode root){
    if(root.left == null && root.right == null){
        StringBuffer sb = new StringBuffer();
        for(int i:temp){
            sb.append(i).append("->");
        }
        sb.delete(sb.length()-2,sb.length());
        ans.add(new String(sb));
        return;
    }
    if(root.left !=null){
        temp.add(root.left.val);
        useme(ans,temp,root.left);
        temp.remove(temp.size()-1);
    }

    if(root.right!=null){
        temp.add(root.right.val);
        useme(ans,temp,root.right);
        temp.remove(temp.size()-1);
    }
}
///
public class Solution {
public List<String> binaryTreePaths(TreeNode root) {
    List<String> path = new ArrayList<String>();
    if(root == null) return path;
    String res = ""+root.val;
    if(root.right==null&&root.left==null){
        path.add(res);
        return path;
    }
    findPath(root.right,path,res);
    findPath(root.left,path,res);
    return path;
}

public void findPath(TreeNode root,List path,String res){
     if(root==null){
         return;
     }
     //just add the result at the final stage---the node is a leaf
     if(root.right==null&&root.left==null){
         res+="->"+root.val;
         path.add(res);
     }

     res+="->"+root.val;
     findPath(root.right,path,res);
     findPath(root.left,path,res);
}
}
///
public class Solution {
 public List<String> binaryTreePaths(TreeNode root) {
    if (root == null){
        return new ArrayList<>();
    }
    List<String> returnList = new ArrayList<>();
    getBinaryTreePaths(returnList,root,"");
    return returnList;

}

private void getBinaryTreePaths(List<String> returnList, TreeNode node,String base) {
    String current = base.length()==0?node.val+"":base+"->"+node.val;
    if(node.left == null && node.right == null){
        returnList.add(current);
    }
    if (node.left != null){
        getBinaryTreePaths(returnList,node.left,current);
    }
    if (node.right != null){
        getBinaryTreePaths(returnList,node.right,current);
    }
}
}
///
public List<String> binaryTreePaths(TreeNode root) {
    List<String> res = new ArrayList<>();
    StringBuilder sb = new StringBuilder();
    return path(root, res, sb);
}
private List<String> path(TreeNode node, List<String> res, StringBuilder pro) {
    if (node == null) {
        return res;
    }
    StringBuilder pre = new StringBuilder(pro);
    if (node.left == null && node.right == null) {
        res.add(pre.append(node.val).toString());
    }
    pre = new StringBuilder(pro);
    if (node.left != null) {
        path(node.left, res, pre.append(node.val + "->")); 
    }
    if (node.right != null) {
        path(node.right, res, pro.append(node.val + "->"));
    }
    return res;
}
idea: if node == null, doesn't add anything. if node has no child, add this node to the result list. if node has child, recursive add left node (if have) and right node (if have).

should pay attention to the StringBuilder, pre.append(x) will change the original value of pre. So, I keep track of the original StringBuilder. That is the reason why I add the code "StringBuilder pre = new StringBuilder(pro);"


////
public List<String> binaryTreePaths(TreeNode root) {
    List<String> res = new ArrayList<String>();
    if(root != null){
        res.addAll(binaryTreePaths(root.left));
        res.addAll(binaryTreePaths(root.right));
        for(int i=0; i < res.size();i++){
            String path = root.val+"->"+res.get(i);
            res.set(i,path);
        }

        if(res.size()==0) res.add(String.valueOf(root.val));
    }
    return res;

}
