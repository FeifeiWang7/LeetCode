Use two stack to store the TreeNode of p and q. While the loop is not over, we keep compare the nodes popped from two stack. Then keep push their children into stack. Hope it helps.

   //iterative
    public class Solution {
        public boolean isSameTree(TreeNode p, TreeNode q) {
            Stack<TreeNode> stack1 = new Stack<>();
            Stack<TreeNode> stack2 = new Stack<>();
            stack1.push(p);
            stack2.push(q);
            while(!stack1.isEmpty() && !stack2.isEmpty()) {
                TreeNode n1 = stack1.pop();
                TreeNode n2 = stack2.pop();
                if(n1 == null && n2 == null) continue;
                if(n1 == null || n2 == null || n1.val != n2.val) return false;
                stack1.push(n1.right);
                stack2.push(n2.right);
                stack1.push(n1.left);
                stack2.push(n2.left);
            }
            return true;
        }
    }

