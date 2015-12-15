public List<Integer> getRow(int rowIndex)
{
    List<Integer> list=new ArrayList<Integer>();
    list.add(1);
    if(rowIndex==0)
    {
        return list;
    }
    if(rowIndex%2==0)
    {
        long num=1;
        for(int i=1;i<=rowIndex/2;i++)
        {
            num=num*(rowIndex-i+1)/i;
            list.add((int)num);
        }
        for(int i=list.size()-2;i>=0;i--)
        {
            list.add(list.get(i));
        }
    }
    else
    {
        long num=1;
        for(int i=1;i<=rowIndex/2;i++)
        {
            num=num*(rowIndex-i+1)/i;
            list.add((int)num);
        }
        for(int i=list.size()-1;i>=0;i--)
        {
            list.add(list.get(i));
        }
    }
    return list;
}

////
public class Solution {
    public List<Integer> getRow(int k) {
        Integer[] arr = new Integer[k + 1];
        Arrays.fill(arr, 0);
        arr[0] = 1;

        for (int i = 1; i <= k; i++) 
            for (int j = i; j > 0; j--) 
                arr[j] = arr[j] + arr[j - 1];

        return Arrays.asList(arr);
    }
}
///
public List<Integer> getRow(int rowIndex) {
    List<Integer> res = new ArrayList<Integer>();
    for(int i = 0;i<rowIndex+1;i++) {
            res.add(1);
            for(int j=i-1;j>0;j--) {
                res.set(j, res.get(j-1)+res.get(j));
            }
    }
    return res;
}
