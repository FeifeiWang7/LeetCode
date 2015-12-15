class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),top=0;
        if(!n)
         return 0;
        char *mystack=new char[n];
        int *index=new int[n];
        for(int i=0;i<n;i++)
        {
          if(s[i]=='(')
            {
                mystack[top]='(';
                index[top]=i;
                ++top;
            }
          if(s[i]==')')
          {
              if(top>0&&mystack[top-1]=='(')
                    top--;
              else
               { 
                   mystack[top]=')';
                   index[top]=i;
                   ++top;
               }
          }
        }
        if(top==0)
            return n;
        int my_max=index[0]-0;;
        for(int i=1;i<top;i++)
            my_max=max(my_max,index[i]-index[i-1]-1);
        my_max=max(my_max,n-index[top-1]-1);
        delete[]index;
        delete []mystack;
        return my_max;
    }
};
/////
struct Solution
    {
        int longestValidParentheses(string s)
        {
            vector<int> stk (1, -1);
            int max_diff = 0;
            for (int i = 0; i < s.size(); ++i)
                if (s[i] == ')')
                {
                    stk.pop_back();
                    if (stk.empty())
                        stk.push_back(i);
                    else
                        max_diff = max(i - stk.back(), max_diff);
                }else
                    stk.push_back(i);
            return max_diff;
        }
    };
///////
public class Solution {
    public int longestValidParentheses(String s) {
        if(s == null || s.length() == 0){
            return 0;
        }

        int m = s.length();
        boolean[] used = new boolean[m];

        Stack<Integer> stack = new Stack<Integer>();
        for(int i = 0; i < m; i ++){
            if(s.charAt(i) == '('){
                stack.push(i);
            }
            if(s.charAt(i) == ')' && !stack.empty()){

                used[i] = true;
                used[stack.peek()] = true;
                stack.pop();
            } 
        }
        int length = 0;
        int max = Integer.MIN_VALUE;
        for(int i = 0; i < m; i ++){
            if(used[i]){
                length ++;
                max = Math.max(length, max);
            }else{

                length = 0;
            }
        }
        return Math.max(max, 0);

    }
}
///
This problem is similar to "largest rectangle histogram" and "water trap" in terms of the usage of stack.

  class Solution {
    public:
        int longestValidParentheses(string s) {
            int maxLen=0;
            stack<int> mystack;
            int n =s.size();
            for(int i=0;i<n;i++){
                if(s[i]==')' && !mystack.empty() && s[mystack.top()]=='('){
                    mystack.pop();
                    int len = mystack.empty()? i+1:i-mystack.top();
                    maxLen=max(maxLen, len);
                }
                else
                    mystack.push(i);
            }
            return maxLen;
        }
    };
///////
1. dp[i] = {max(k) | s[i-k+1, i] is well formed. k=0 means empty}
 2. For char s[i], we should check the char s[i-1-dp[i-1]]. 
  If s[i] and s[i-1-dp[i-1]] are matched, substring from  i-1-dp[i-1] to i is well formed. 
  Then, we should joint it with previous well formed substring which ends at s[i-1-dp[i-1]-1].

 int longestValidParentheses(string s) {
            vector<int> dp(s.length(),0);
            int res = 0;
            for(int i=1; i<s.length(); ++i)
                if(s[i]==')' && i-1-dp[i-1]>=0 &&s[i-1-dp[i-1]]=='('){
                    if(i-1-dp[i-1]-1 >= 0) dp[i]= dp[i-1]+2+dp[i-1-dp[i-1]-1];
                    else  dp[i]= dp[i-1]+2;
                    res = max(res, dp[i]);
                }
            return res;
        }
/////
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int maxL=0;
        for(int i=0;i<s.size();i++)
        {
            int t=stk.top();
            if(t!=-1&&s[i]==')'&&s[t]=='(')
            {
                stk.pop();
                maxL=max(maxL,i-stk.top());
            }
            else
                stk.push(i);
        }
        return maxL;
    }
};
///
int longestValidParentheses(string s) {
        int cnt = 0; // count of "("
        vector<int> dp(s.size()+1, 0);

        for (size_t i = 1; i <= s.size(); i++) {
            if (s[i-1] == '(') {
                cnt++;
            } else {
                if (cnt > 0) {  // there exists an unclosed "(" to match ")"
                    cnt--;
                    dp[i] = 2;
                    if (s[i-2] == ')')  // add the length of previous closed ")" neighbor
                        dp[i] += dp[i-1];                        
                    dp[i] += dp[i-dp[i]]; // add the length of previous valid parentheses
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
////
First, scan from left to right while checking the balance. Second, scan from right to left in the same way. So no stack is needed.

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        {
            int left = 0;
            int right = 0;
            for (int i = 0; i < s.length(); i++) {
                switch (s[i]) {
                case '(': left++; break;
                case ')': right++; break;
                default: left = right = 0; continue;
                }
                if (left == right && left + right > result) result = left + right;
                if (right > left) left = right = 0;
            }
        }
        {
            int left = 0;
            int right = 0;
            for (int i = s.length(); i > 0; i--) {
                switch (s[i-1]) {
                case '(': left++; break;
                case ')': right++; break;
                default: left = right = 0; continue;
                }
                if (left == right && left + right > result) result = left + right;
                if (left > right) left = right = 0;
            }
        }
        return result;
    }
};
Combination:

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        int ll = 0, lr = 0, li = 0;  // left paren sum, right paren sum, left index
        int rl = 0, rr = 0, ri = s.length();  // left paren sum, right paren sum, right index
        while (li < s.length() && ri > 0) {
            switch (s[li]) {
            case '(': ll++; break;
            case ')': lr++; break;
            default: ll = lr = 0;
            }
            switch (s[ri-1]) {
            case '(': rl++; break;
            case ')': rr++; break;
            default: rl = rr = 0;
            }
            if (ll == lr && ll + lr > result) result = ll + lr;
            if (rl == rr && rl + rr > result) result = rl + rr;
            if (ll < lr) ll = lr = 0;
            if (rl > rr) rl = rr = 0;
            li++; ri--;
        }
        return result;
    }
};
//////
int longestValidParentheses(string s) {
    // dp[i] = longest length of valid substring ending at i
    int*dp=new int[s.size()]();
    int i,j,ans=0;
    for(i=1;i<s.size();i++){
        char c=s[i];
        if(c!=')')continue;
        int k=dp[i-1];
        j=i-1-k;
        // account for any nested structure
        if(j>=0&&s[j]=='('){
            ans=max(ans,dp[i]=k+2);
            // append length of adjacent valid substring
            if(--j>=0)
                ans=max(ans,dp[i]+=dp[j]);
        }
    }
    delete[]dp;
    return ans;
}
////
// Using a stack. One pass
    int longestValidParentheses(string s) {
        vector<int> stack;
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                stack.push_back(i);
            else {
                if (!stack.empty() && s[stack.back()] == '(') {
                    stack.pop_back();
                    int lastPos = -1;
                    if (!stack.empty())
                        lastPos = stack.back();
                    int curLen = i - lastPos;
                    maxLen = (maxLen < curLen) ? curLen : maxLen;
                } else
                    stack.push_back(i);
            }
        }
        return maxLen;
    }
/////
My solution uses DP. The main idea is as follows: I construct a array longest[], for any longest[i], it stores the longest length of valid parentheses which is end at i. 
And the DP idea is : 
If s[i] is '(', set longest[i] to 0,because any string end with '(' cannot be a valid one. 
Else if s[i] is ')' 
     If s[i-1] is '(', longest[i] = longest[i-2] + 2 
     Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2] 
For example, input "()(())", at i = 5, longest array is [0,2,0,0,2,0], longest[5] = longest[4] + 2 + longest[1] = 6. 

   int longestValidParentheses(string s) {
            if(s.length() <= 1) return 0;
            int curMax = 0;
            vector<int> longest(s.size(),0);
            for(int i=1; i < s.length(); i++){
                if(s[i] == ')'){
                    if(s[i-1] == '('){
                        longest[i] = (i-2) >= 0 ? (longest[i-2] + 2) : 2;
                        curMax = max(longest[i],curMax);
                    }
                    else{ // if s[i-1] == ')', combine the previous length.
                        if(i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '('){
                            longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                            curMax = max(longest[i],curMax);
                        }
                    }
                }
                //else if s[i] == '(', skip it, because longest[i] must be 0
            }
            return curMax;
        }
Updated: thanks to Philip0116, I have a more concise solution(though this is not as readable as the above one, but concise):

int longestValidParentheses(string s) {
        if(s.length() <= 1) return 0;
        int curMax = 0;
        vector<int> longest(s.size(),0);
        for(int i=1; i < s.length(); i++){
            if(s[i] == ')' && i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '('){
                    longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                    curMax = max(longest[i],curMax);
            }
        }
        return curMax;
    }
////
My java solution with both stack and an array....It is very easy to understand. Maybe it is the only good part compared to the other space-saving solution.

public class Solution {
    public int longestValidParentheses(String s){
        if (s==null||s.length()==0) return 0;

        Stack<Integer> stack= new Stack<Integer>(); //Store indices of '('
        int[] result=new int[s.length()];//Store the length of the current longest valid sequence.
        Arrays.fill(result, 0);

        int max=0;

        for (int i=0;i<s.length();i++)
            if (s.charAt(i)=='(')
                stack.push(i);  

            else if (s.charAt(i)==')'){
                if (stack.isEmpty()) 
                    continue;
                else if (stack.peek()>0) 
                    result[i]=2+result[stack.pop()-1]+result[i-1];//May connect two valid sequences, or increase the length of current valid sequence. 
                else {
                    result[i]=2+result[i-1];//Handle the special case that the leftmost char is a '('
                    stack.pop();
                }

                max=Math.max(result[i],max);
            }
        return max;
    }
}
/////
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), longest = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(i);
            else {
                if (!st.empty()) {
                    if (s[st.top()] == '(') st.pop();
                    else st.push(i);
                }
                else st.push(i);
            }
        }
        if (st.empty()) longest = n;
        else {
            int a = n, b = 0;
            while (!st.empty()) {
                b = st.top(); st.pop();
                longest = max(longest, a-b-1);
                a = b;
            }
            longest = max(longest, a);
        }
        return longest;
    }
};
