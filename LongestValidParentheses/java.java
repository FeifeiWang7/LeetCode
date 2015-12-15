public class Solution {
    public int longestValidParentheses(String s) {
        if (s == null || "".equals(s)) return 0;
        int[] dp = new int[s.length() + 1];
        int max = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == ')' && i - dp[i] >= 1 && s.charAt(i - dp[i] - 1) == '(') {
                dp[i + 1] = dp[i - dp[i] - 1] + dp[i] + 2;
            }
        }
        for (int i = 0; i < dp.length; i++) {
            if (dp[i] > max) max = dp[i];
        }
        return max;
    }
}
///
public int longestValidParentheses(String s) {

        int[] dp = new int[s.length()];

        char[] c = s.toCharArray();
        int max = 0, cand;
        for (int i = 0; i < c.length; i++) {
            if (c[i] == ')' && i > 0 && (cand = i - dp[i - 1] - 1) >= 0)
                if (c[cand] == '(')
                    dp[i] = 2 + dp[i - 1] + (cand > 0 ? dp[cand - 1] : 0);
            max = max < dp[i] ? dp[i] : max;
        }

        return max;
    }
///
public int longestValidParentheses(String s) {
        Stack<Integer> st = new Stack<>();
        st.push(-1);
        int len = 0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)==')'&&st.peek()!=-1&&s.charAt(st.peek())=='('){
                st.pop();
                len = Math.max(len,i-st.peek());
            }
            else   st.push(i);
        }
        return len;
    }
////
public class Solution {
public int longestValidParentheses(String s) {
    if(s == null || s.length() <= 1){
        return 0;
    }
    int start = -1;
    int res = 0;
    LinkedList<Integer> stack = new LinkedList<Integer>();
    for(int i=0;i<s.length();i++){
        if(s.charAt(i) == '('){
            stack.push(i);
        }else{
            if(!stack.isEmpty()){
                stack.pop();
                if(!stack.isEmpty()){
                    res = Math.max(res,i-stack.peek());
                }else{
                    res = Math.max(res,i-start);
                }
            }else{
                start = i;
            }
        }
    }
    return res;
}
}
////
public int longestValidParentheses(String s) {
    Stack<Integer> st = new Stack<Integer>();
    int maxLen = 0;
    int curLen = 0;
    for(int i = 0; i < s.length();i++) {
        if(s.charAt(i) == '(') {
            st.push(curLen);
            curLen = 0;
        } else if (s.charAt(i) == ')') {
            if(st.isEmpty()) {
                curLen = 0;
            } else {
                curLen = curLen + st.pop() + 2;
                if(curLen > maxLen) maxLen = curLen;
            }
        }
    }
    return maxLen;
}
///////
Stack:

    public int longestValidParentheses(String s) {
        Stack<Integer> st = new Stack<>();
        int max = 0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)==')'&&!st.isEmpty()&&s.charAt(st.peek())=='('){
                st.pop();
                max = Math.max(max, i-((st.isEmpty())?-1:st.peek()));
            }
            else    st.push(i);
        }
        return max;
    }
DP:

public int longestValidParentheses(String s) {
    /*max[i] = j means subsequence index i-j is longest valid Parentheses*/
    int[] max = new int[s.length()+1];
    max[s.length()] = s.length();
    int sum = 0;
    for(int i=s.length()-1;i>=0;i--){
        if(max[i+1]!=i+1){
            if(max[i+1]+1<s.length()&&s.charAt(i)=='('&&s.charAt(max[i+1]+1)==')'){
                max[i] = (max[i+1]+2<s.length()+1&&max[max[i+1]+2]!=max[i+1]+2)?max[max[i+1]+2]:max[i+1]+1;
            }
            else    max[i] = i;
        }
        else if(i+1<s.length()&&s.charAt(i+1)==')'&&s.charAt(i)=='('){
            max[i] = (i+2<s.length()+1&&max[i+2]!=i+2)?max[i+2]:i+1;
        }
        else    max[i] = i;
        sum = Math.max(sum, max[i]-i+1);
    }
    return (sum==1)?0:sum;
}
/////
I have seen a lot of good answers but it is not immediately clear how they are achieving the result. I am going to make an attempt to explain my solution using a stack. Every time we encounter '(' we push the index onto the stack and when we encounter ')' we pop the stack and use the current index minus the index at the top of the stack to be the current_length. we check against the max found so far and update if needed. Here is the code

public static int longestValidParentheses(String s) {


        Stack<Integer> bracketStack = new Stack<Integer>();
        int max_len=0;
        int current_len=0;
        int last = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {

                    bracketStack.push(i);
            }
            else{

                if(!bracketStack.isEmpty())
                {
                    bracketStack.pop();

                if(!bracketStack.isEmpty())
                    current_len = i-bracketStack.peek();
                else
                    current_len=i-last;
                max_len = Math.max(max_len,current_len);
                }
                else{

                    last = i;
                }
            }

        }


        return max_len;
    }

/////
public int longestValidParentheses(String s) {
    char[] S = s.toCharArray();
    int[] V = new int[S.length];
    int open = 0;
    int max = 0;
    for (int i=0; i<S.length; i++) {
        if (S[i] == '(') open++;
        if (S[i] == ')' && open > 0) {
            V[i] = 2 + V[i-1] + (i-2-V[i-1] > 0 ? V[i-2-V[i-1]] : 0);
            open--;
        }
        if (V[i] > max) max = V[i];
    }
    return max;
}
///
Could there be better improvements on this?

public class Solution {
    public int longestValidParentheses(String s) {
        int length = 0;
        int score = 0;
        int start = 0;
        int cur = 0;
        int bound;

        while (cur < s.length()) {
            score += (s.charAt(cur) == '(') ? 1 : -1;

            if (score == 0) {
                length = Math.max(length, cur - start + 1);             
            } else if (score < 0) {
                start = cur + 1;
                score = 0;
            }

            ++cur;
        }

        if (score > 0) {
            bound = start - 1;
            cur = s.length() - 1;
            start = cur;
            score = 0;

            while (cur > bound) {
                score += (s.charAt(cur) == ')') ? 1 : -1;

                if (score == 0) {
                    length = Math.max(length, start - cur + 1);             
                } else if (score < 0) {
                    start = cur - 1;
                    score = 0;
                }

                --cur;
            }
        }

        return length;
    }
}
///
public class Solution {
public int longestValidParentheses(String s) {
    Stack<Integer> stack = new Stack<Integer>();
    int max=0;
    int left = -1;
    for(int j=0;j<s.length();j++){
        if(s.charAt(j)=='(') stack.push(j);            
        else {
            if (stack.isEmpty()) left=j;
            else{
                stack.pop();
                if(stack.isEmpty()) max=Math.max(max,j-left);
                else max=Math.max(max,j-stack.peek());
               }
            }
        }
    return max;
}
}
