int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void subSets(int* n, int nS, int pos,
             int k, int subS, int* cur,
             int* colS, int* retS,
             int** ret)
{
  //the # of items in this subset is reached; push current list to the return list
  if(k == subS)
  {
    colS[*retS] = subS;
    if(subS > 0) memcpy(ret[*retS], cur, sizeof(int) * subS);
    (*retS)++;
  }

  //loop through the remaining in nums set
  for(int i = pos; i<nS; i++)
  {
    // skip the duplicate items
    if(i!=pos && n[i] == n[i-1])  continue;

    cur[k] = n[i];
    subSets(n, nS, i+1, k+1, subS, cur, colS, retS, ret);
  }
}

int** subsetsWithDup(int* n, int nS, int** colS, int* retS)
{
  if(nS == 0 || n==NULL)  return NULL;

  int worstCaseLen = pow(2,nS); // worst case no dup so 2^n
  int* cur = (int*)malloc(sizeof(int)*nS);
  int** ret = (int**)malloc(sizeof(int*)* worstCaseLen);  

  for(int i = 0; i<worstCaseLen; i++)
    ret[i] = (int*)malloc(sizeof(int)*nS);
  *retS = 0;
  *colS = (int*)malloc(sizeof(int) * worstCaseLen); 

  //sort first
  qsort(n, nS, sizeof(int), compare);

  // the length of subsets varies from 0, 1, ... , n-1, n
  // always start from index 0
  for(int i = 0; i <= nS; i++)
    subSets(n, nS, 0, 0, i, cur, *colS, retS, ret);

  return ret;
}
