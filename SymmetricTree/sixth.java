public boolean isSymmetric(TreeNode root) {
        if(root==null || root.left==null && root.right==null){
            return true;
        }
        if(root.left==null ^ root.right==null || root.left.val!= root.right.val){
            return false;
        }
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root.left);
        q.add(root.right);
        while(!q.isEmpty()) {
            TreeNode out = q.poll();
            TreeNode in = q.poll();
            if(out==null ^ in==null || out.val!=in.val) {
                return false;
            }
            if(out.left!=null || in.right!=null){
                q.add(out.left);
                q.add(in.right);
            }
            if(out.right!=null || in.left!=null){
                q.add(out.right);
                q.add(in.left);
            }
        }
        return true;
    }
Basically, what we have to do is keep checking if left leaf node value of left child same as right leaf node value of right child.

My idea is first examine the root to see it is null or has any leaf node. Then adding two nodes to a queue and popping out two at a time to examine if they have equal values and so on. Before adding new nodes to the queue, check if either one is null so that we can XOR to check them afterwards.

Not sure if this is a good solution. Any advice? Thanks in advance.
