public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(root == null) return res;
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);
        while(!queue.isEmpty()){
            int size =queue.size();
            List<Integer> temp = new ArrayList<Integer>();
            while(size-- > 0){
                root = queue.poll();
                temp.add(root.val);
                if(root.left != null) queue.offer(root.left);
                if(root.right!= null) queue.offer(root.right);
            }
            res.add(temp);
        }
        return res; 
    }
