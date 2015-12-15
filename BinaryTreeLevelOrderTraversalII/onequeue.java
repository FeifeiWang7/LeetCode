public static List<List> levelOrderBottom(TreeNode root) { 
List<List<Integer>> result=new ArrayList<List<Integer>>();//返回的最终结果
       Queue<TreeNode> treeNodes2=new LinkedList<>();//用来存放每一层的节点

       //处理第一个节点（root）
       if(root==null)
           return result;
       else {
           List<Integer> temp=new ArrayList<>();//存放暂时的结果
           temp.add(root.val);
           treeNodes2.offer(root);
           result.add(temp);

       }

       while(!treeNodes2.isEmpty())
       {
          int i=treeNodes2.size();
          List<Integer> tempReslut=new ArrayList<>();//存放暂时的结果
          while(i>0)//遍历这一层的所有节点
          {

              TreeNode tNode=treeNodes2.poll();
              if(tNode.left!=null)
              {
                  tempReslut.add(tNode.left.val);
                  treeNodes2.offer(tNode.left);
              }
              if(tNode.right!=null)
              {
                  tempReslut.add(tNode.right.val);
                  treeNodes2.offer(tNode.right);
              }
              i--;
          }
          if(!tempReslut.isEmpty()) result.add(0,tempReslut);  

       }

       return result;

    }

