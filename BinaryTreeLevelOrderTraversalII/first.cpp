public class Solution {

public int level=0;
public List<List<Integer>> ans = new ArrayList<>();

 public void Build(TreeNode root) {
   if(root == null) return;
    level++;
    List<Integer> temp;
   if(level>ans.size()){
        temp=new ArrayList<>();
        temp.add( root.val);
        ans.add(0,temp);
    }
    else{
        temp=ans.get(ans.size()-level);
        temp.add(root.val);
    }

    Build(root.left);
    Build(root.right);

    level--;
  }

public List<List<Integer>> levelOrderBottom(TreeNode root) {
        Build(root);
        return ans;
  }
}
