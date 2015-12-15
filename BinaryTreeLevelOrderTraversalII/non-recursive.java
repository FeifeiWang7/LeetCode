So there are two arraylists storing values and nodes in current level respectively. Then iterate through the nodes in current level to get their children and their values.

public class Solution 
    {
        public List<List<Integer>> levelOrderBottom(TreeNode root)
        {
            List<List<Integer>> ans = new ArrayList<List<Integer>>();
            List<Integer> curVal = new ArrayList<Integer>();
            List<TreeNode> curLev = new ArrayList<TreeNode>();
            List<TreeNode> nextLev = new ArrayList<TreeNode>();
            if(root == null)
                return ans;
            curVal.add(root.val);
            curLev.add(root);
            ans.add(0, curVal);
            while(curLev.size() != 0)
            {
                curVal = new ArrayList<Integer>();
                for(int i = 0; i < curLev.size(); i++)
                {
                    if(curLev.get(i).left != null)
                    {
                        curVal.add(curLev.get(i).left.val);
                        nextLev.add(curLev.get(i).left);
                    }
                    if(curLev.get(i).right != null)
                    {
                        curVal.add(curLev.get(i).right.val);
                        nextLev.add(curLev.get(i).right);
                    }
                }
                if(curVal.size() != 0)
                    ans.add(0, curVal);
                curLev = nextLev;
                nextLev = new ArrayList<TreeNode>();
            }
            return ans;
        }
    }

