the DP array can be numsSize long, but actually we only need 2 steps history; so dp[2] is enough. the dynamic programming formular is:

max_money_upto_house(i) = max{money_upto_house(i-2) + rob_house(i),  
                              money_upto_house(i-1) and spare_house(i)}
To pack everything into 3 lines:

#define MAX(a,b) (a>b)?a:b 
/* int rob(int* nums, int numsSize) */
int rob(int* n, int nS)  
{
  /* if(!n || nS == 0) return 0; */
  int dp[2] = {n[0],0}, idx = 1;
  for(int i = 1; i< nS; i++, idx^=1) dp[idx] = MAX(dp[idx^1], dp[idx] + n[i]);
  return dp[idx^1];
}
The human version is O(n) time but O(n) space:

int rob(int* n, int nS)  
{
  int dp[nS+1];
  dp[0] = 0;
  dp[1] = n[0];
  for(int i = 1; i<= nS; i++)
  {
    dp[i+1] = MAX(dp[i], dp[i-1] + n[i]);
  }

  return dp[nS];
}
