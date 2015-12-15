public class Solution {
  public int minDepth(TreeNode root) {
      if(root==null) return 0;
      else if(root.left==null && root.right==null) return 1;
      else if(root.left==null) return 1+minDepth(root.right);
      else if(root.right==null) return 1+minDepth(root.left);
      return 1+Math.min(minDepth(root.left),minDepth(root.right));
      }
}
///recursive
public class Solution {
public int minDepth(TreeNode root) {
   if(root ==null){
       return 0;
   }
   if(root.left ==null&&root.right == null){
       return 1;
   }
   if(root.left ==null){
       return 1+minDepth(root.right);
   }
   if(root.right ==null){
       return 1+minDepth(root.left);
   }
   int left = 1+minDepth(root.left);
   int right =1+ minDepth(root.right);
   return left<right?left:right;
}
}
//iterative BFS
public class Solution {
public int minDepth(TreeNode root) {
//iterative
   LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
    if(root==null) return 0;
    queue.add(root);
    int level = 0;
    while(!queue.isEmpty()){
        int count = queue.size();
        while(count>0){
            TreeNode tmp = queue.poll();
            // return when we find the first leaf node
            if(tmp.left==null && tmp.right==null) return ++level;
            if(tmp.left!=null) queue.add(tmp.left);
            if(tmp.right!=null) queue.add(tmp.right);
            count--;
        }
        level++;
    }
    return level;
}
}

//recursion
public int minDepth(TreeNode root) {
    // recursion method
    if (root == null) return 0;
    int count = 1;
    if (root.left == null && root.right != null) {
        return minDepth(root.right) + 1;
    }
    if (root.left != null && root.right == null) {
        return minDepth(root.left) + 1;
    }
    return helper(root);
}
private int helper(TreeNode root) {
    return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
}
public int minDepth(TreeNode root) {
    // iteration method
    if (root == null) return 0;
    Stack<TreeNode> stack = new Stack<>();
    Stack<Integer> levels = new Stack<>();
    stack.push(root);
    levels.push(1);
    int min = Integer.MAX_VALUE;
    while (!stack.isEmpty()) {
        TreeNode temp = stack.pop();
        int level = levels.pop();
        if (temp.left == null && temp.right == null) {
            min = Math.min(min, level);
        }
        if (temp.left != null) {
            stack.push(temp.left);
            levels.push(level + 1);
        }
        if (temp.right != null) {
            stack.push(temp.right);
            levels.push(level + 1);
        }
    }
    return min;
}
