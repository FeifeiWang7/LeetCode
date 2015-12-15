public List<String> summaryRanges(int[] a) {
  List<String> res = new ArrayList<String>();

  if (a == null) return res;

  int i = 0, n = a.length;

  for (int j = 1; j < n; j++) {
    if ((long)a[j] - (long)a[j - 1] > 1) {
      // found a range
      res.add(getRange(a[i], a[j - 1]));
      i = j;
    }
  }

  // final check
  if (i < n) res.add(getRange(a[i], a[n - 1]));

  return res;
}

String getRange(int n1, int n2) {
  return (n1 == n2) ? String.valueOf(n1) : String.format("%d->%d", n1, n2);
}
/////////
public List<String> summaryRanges(int[] nums) {
    List<String> ans = new ArrayList<String>();
    if(nums==null){
        return ans;
    }
    int len =0;
    StringBuilder temp = null;
    for(int i=0; i<(len=nums.length);++i){
        int k = nums[i];
        temp = new StringBuilder();
        temp.append(nums[i]);
        while(i+1<len && nums[i+1] == nums[i]+1){
            ++i;
        }
        if(nums[i]!=k){
            temp.append("->");
            temp.append(nums[i]);
        }
        ans.add(temp.toString());
    }
    return ans;
}
///
public class Solution {
public List<String> summaryRanges(int[] nums) {
    List<String> res = new ArrayList<String>();
    if (nums.length == 0) return res;
    int start = nums[0], end = nums[0];
    for (int i = 0; i < nums.length - 1; i++) {
        if (nums[i + 1] == nums[i] + 1) end = nums[i + 1];
        else {
            addToArr(res, start, end);
            start = end = nums[i + 1];
        }
    }
    addToArr(res, start, end);
    return res;
}
private void addToArr(List<String> arr, int start, int end) {
    if (start == end) arr.add(String.valueOf(start));
    else arr.add(start + "->" + end);
}
}
////////
public class SummaryRanges {

public List<String> summaryRanges(int nums[]){


    List<String> ranges = new ArrayList<String>(); //Initialize the return array

    if(nums.length == 0){ //If the array is empty, return directly
        return ranges;
    }

    if(nums.length == 1){ //If the array has a length of 1, just add to the return array
        ranges.add(String.valueOf(nums[0]));
    }

    int start = nums[0]; //Initialize an integer marker to mark the start of each range

    String pointer = "->";

    //Main logic goes here
    for(int i=0;i<=nums.length-2;i++){
        if(nums[i+1]-nums[i]!=1){       //Judge whether two adjacent integers are in same range
            if(nums[i] != start){       //If the start marker not equals to the number at current index,
                                        //it means that this range has more than two elements
              ranges.add(String.valueOf(start)+pointer+String.valueOf(nums[i]));
            }else{                      //Else, this range only contains one element.
              ranges.add(String.valueOf(nums[i]));
            }
            if(i==nums.length-2){       //And we have to judge whether the next element is the last one element in array
                ranges.add(String.valueOf(nums[i+1]));//If true, simply treat the last element as a new range and break from the loop
                break;
            }
            start = nums[i+1];   //Otherwise, reset the start marker to the next element
        }else{
            if(i==nums.length-2){//If the last element is still within a range, end this loop by adding the last range to the return array
                ranges.add(String.valueOf(start)+pointer+String.valueOf(nums[i+1]));
                break;
            }
        }
    }

    return ranges;
}
}


