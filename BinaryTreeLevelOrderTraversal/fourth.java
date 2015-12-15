Recursive DFS, i think the time complexity for this solution is o(n), is that right? how about the space complexity? is that o(logn)?

public static List<List<Integer>> iterative(TreeNode root) {
    List<List<Integer>> list = new ArrayList<List<Integer>>();
    return addlevel(root,0,list);
}
public static List<List<Integer>> addlevel(TreeNode root, int level, List<List<Integer>> list){
    if(root==null) return list;
    // check if it is a new level
    if(list.size()==level){
        list.add(new ArrayList<Integer>());
    }
    list.get(level).add(root.val);
    addlevel(root.left,level+1,list);
    addlevel(root.right,level+1,list);
    return list;
}
Iterative BFS - using queue

public static List<List<Integer>> levelOrder(TreeNode root) {
     List<List<Integer>> levelorder = new ArrayList<List<Integer>>();
        LinkedList<TreeNode> queue = new LinkedList<TreeNode>();

        if(root==null) return levelorder;
        queue.add(root);

        while(!queue.isEmpty()){
            int count = queue.size();
            List<Integer> onelevel = new ArrayList<Integer>();
            while(count>0){
                TreeNode tmp = queue.poll();
                onelevel.add(tmp.val);
                if(tmp.left!=null) queue.add(tmp.left);
                if(tmp.right!=null) queue.add(tmp.right);
                count--;
            }
            levelorder.add(onelevel);
        }
        return levelorder;
}
