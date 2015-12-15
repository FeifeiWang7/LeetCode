public class Solution {
public List<List<Integer>> levelOrder(TreeNode root) {
   List<List<Integer>> table = new ArrayList<List<Integer>>();
    Queue<TreeNode> q = new LinkedList<TreeNode>();
    q.add(root);
    while (q.peek()!=null)
    {
        List<Integer> table2 = new ArrayList<Integer>();
        int size =q.size();
        for (int i = 0 ; i < size; i ++)
        {
            TreeNode temp = q.remove();
            table2.add(temp.val);
            if (temp.left!=null) q.add(temp.left);
            if (temp.right!=null) q.add(temp.right);
        }
        table.add(table2);
    }
    return table;

}
}


