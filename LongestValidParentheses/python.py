def longestValidParentheses(self, s):
        dp, ans = [0]*(len(s)+1), 0
        for i in range(2, len(s)+1):
            if s[i-1]==')':
                if i-dp[i-1]-2>=0 and s[i-dp[i-1]-2]=='(': dp[i] = dp[i-1] + 2
                dp[i] += dp[i-dp[i]]
                ans = max(ans, dp[i])
        return ans
###
let dp[i] is the number of longest valid Parentheses ended with the i - 1 position of s, then we have the following relationship: dp[i + 1] = dp[p] + i - p + 1 where p is the position of '(' which can matches current ')' in the stack.

  def longestValidParentheses(self, s):
    dp, stack = [0]*(len(s) + 1), []
    for i in range(len(s)):
        if s[i] == '(':
            stack.append(i)
        else:
            if stack:
                p = stack.pop()
                dp[i + 1] = dp[p] + i - p + 1
    return max(dp)
#####
class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        # use 1D DP
        # dp[i] records the longestValidParenthese EXACTLY ENDING at s[i]
        dp = [0 for x in xrange(len(s))]
        max_to_now = 0
        for i in xrange(1,len(s)):
            if s[i] == ')':
                # case 1: ()()
                if s[i-1] == '(':
                    # add nearest parentheses pairs + 2
                    dp[i] = dp[i-2] + 2
                # case 2: (()) 
                # i-dp[i-1]-1 is the index of last "(" not paired until this ")"
                elif i-dp[i-1]-1 >= 0 and s[i-dp[i-1]-1] == '(':
                    if dp[i-1] > 0: # content within current matching pair is valid 
                    # add nearest parentheses pairs + 2 + parentheses before last "("
                        dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2]
                    else:
                    # otherwise is 0
                        dp[i] = 0
                max_to_now = max(max_to_now, dp[i])
        return max_to_now
#####
class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        dic = {}
        dic[-1] = 0
        stack = []
        stack.append(-1)
        result = 0
        for i in xrange(0, len(s)):
            if s[i] == '(':
                dic[i] = 0
                stack.append(i)
            else:
                if len(stack) < 2:
                    result = max(result, dic[stack[-1]])
                    dic[stack[-1]] = 0
                    continue
                dic[stack[-2]] += i - stack[-1] + 1
                result = max(result, dic[stack[-2]])
                stack.pop()
        return result
###
def longestValidParentheses(self, s):
    stack, longest, index = [0], 0, 0

    for index in xrange(0, len(s)):
        if s[index] == ")" and len(stack) != 1:
            length, last = stack.pop(), stack.pop()
            total_length = last + length + 2
            stack.append(total_length)
            longest = max(longest, total_length)
        elif s[index] == "(":
            stack.append(0)
        else:
            stack = [0]

    return longest
#####
class Solution:
    # @param {string} s
    # @return {integer}
    def longestValidParentheses(self, s):
        if not s:
            return 0
        record = [0]*len(s)
        left = []
        for index, char in enumerate(s):
            if char == "(":
                left.append(index)
            elif left:
                leftIndex = left.pop()
                if index>0 and index - leftIndex == record[index-1]+1:
                    record[index] = record[index-1] + 2
                    if leftIndex > 0:
                        record[index] += record[leftIndex-1]
        return max(record)
###
def longestValidParentheses(self, s):
    """ as the ")" will not effect the final result, which acts as a dummy  element to
        make the all the  original elements of s equivalently, 
        otherwise the first element needs to be dealt with separately. 
    """ 
    s = ")" + s  
    stack, ans = [], 0
    for index in xrange(len(s)):
      element = s[index]
      if element == ")" and stack and stack[-1][1] == "(":
        stack.pop()
        ans = max(ans, index - stack[-1][0])
      else:
        stack.append((index, element))
    return ans
