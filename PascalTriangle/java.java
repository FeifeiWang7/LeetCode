public class Solution {
    public List<List<Integer>> generate(int numRows) {
        if(numRows == 0) return new ArrayList<>();
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> first = new ArrayList<>();
        first.add(1);
        result.add(first);
        List<Integer> lastLevel;
        List<Integer> currentLevel;
        for(int i = 1; i < numRows; i++) {
            lastLevel = result.get(i-1);
            currentLevel = new ArrayList<>();
            currentLevel.add(1);
            for(int j = 1; j < lastLevel.size(); j++) {
                currentLevel.add(lastLevel.get(j-1) + lastLevel.get(j));
            }
            currentLevel.add(1);
            result.add(currentLevel);
        }
        return result;
    }
}
///////
public class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();

        for (int i = 0; i < numRows; i++) {
            List<Integer> list = new ArrayList<Integer>(Arrays.asList(1));

            for (int j = 1; j < i; j++) 
                list.add(res.get(i - 1).get(j - 1) + res.get(i - 1).get(j));

            if (i > 0) list.add(1);

            res.add(list);
        }

        return res;
    }
}
////
public class Solution {
public List<List<Integer>> generate(int numRows) {
    List<List<Integer>> tri = new ArrayList<List<Integer>>();
    if (numRows<1) return tri;
    for(int i=0;i<numRows;i++){
        List<Integer> li = new ArrayList<Integer>();
        tri.add(li);
    }
  //work start here
    tri.get(0).add(1);
    for(int i=1;i<numRows;i++){
        tri.get(i).add(1);
        for(int j=0;j<i-1;j++){
            int temp = tri.get(i-1).get(j)+tri.get(i-1).get(j+1);
            tri.get(i).add(temp);
        }
        tri.get(i).add(1);
    }
    return tri;
}
}
////
The trick is to use linked list because there is a lot of add operations that each costs o(n) time using array list. And to get the previous assigned before retriving value frequently from it.

public List<List<Integer>> generate(int numRows) {


    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    if (numRows == 0)
        return ans;

    LinkedList<Integer> sub = new LinkedList<Integer>();
    sub.add(1);
    ans.add(sub);

    for (int i = 1; i < numRows; i++) {
        LinkedList<Integer> subAns = new LinkedList<Integer>();
        List<Integer> list = ans.get(i - 1);
        subAns.addFirst(1);
        for (int j = 1; j < i; j++)
            subAns.addFirst(list.get(j - 1) + list.get(j));
        subAns.addFirst(1);
        ans.add(subAns);
    }

    return ans;

}
