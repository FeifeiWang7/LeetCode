typedef char hashKeyT;
typedef int hashValueT;
typedef struct
{
        hashKeyT key;
        hashValueT value;
        UT_hash_handle hh;
}hashEntryT;
int lengthOfLongestSubstring(char* s)
{
        hashEntryT *hashMap = NULL, *item, *del, *tmp;
        int len = strlen(s), i, max = 0, start = 0;
        for(i = 0; i < len; i++)
        {
                HASH_FIND(hh, hashMap, &s[i], sizeof(s[i]), item);
                if(item == NULL)
                {
                        item = (hashEntryT *)malloc(sizeof(hashEntryT));
                        item -> key = s[i];
                        item -> value = i;
                        HASH_ADD(hh, hashMap, key, sizeof(hashKeyT), item);
                }
                else
                {
                        max = max > HASH_COUNT(hashMap)? max:HASH_COUNT(hashMap);
                        int j = item -> value;

                        for(int k = start; k <= j; k++)
                        {
                                HASH_FIND(hh, hashMap, &s[k], sizeof(s[k]), del);
                                if(del != NULL) HASH_DEL(hashMap, del);
                        }
                        start = j+1;
                        tmp = (hashEntryT *)malloc(sizeof(hashEntryT));
                        tmp -> key = s[i];
                        tmp -> value = i;
                        HASH_ADD(hh, hashMap, key, sizeof(hashKeyT), tmp);
                }
        }
        return max>HASH_COUNT(hashMap) ? max:HASH_COUNT(hashMap);
}
 //remove some hash func
int lengthOfLongestSubstring(char* s)
{
        hashEntryT *hashMap = NULL, *item, *del, *tmp;
        int len = strlen(s), i, max = 0, start = 0;
        for(i = 0; i < len; i++)
        {
                HASH_FIND(hh, hashMap, &s[i], sizeof(s[i]), item);
                if(item == NULL)
                {
                        item = (hashEntryT *)malloc(sizeof(hashEntryT));
                        item -> key = s[i];
                        item -> value = i;
                        HASH_ADD(hh, hashMap, key, sizeof(hashKeyT), item);
                }
                else
                {
                        max = max > i-start? max:i-start;
                        int j = item -> value;
                        memcpy(&(item -> value), &i, sizeof(hashValueT));
                        for(int k = start; k < j; k++)
                        {
                                HASH_FIND(hh, hashMap, &s[k], sizeof(s[k]), del);
                                if(del != NULL) HASH_DEL(hashMap, del);
                        }
                        start = j+1;
                }
        }
        return max>i-start? max:i-start;
}

///
int lengthOfLongestSubstring(char* s)
{
        int len = strlen(s), max = 0, count,i,j;
        int index[1000000]; index[0] = 1;
        if(len < 1) return 0;
        for(i = 1; i < len; i ++)
        {
                count = index[i-1] + 1;
                for(j = i - count + 1; j< i; j++)
                {
                        if(s[j] == s[i])
                        {
                                index[i] = i - j;
                                break;
                        }
                }
                if(j == i) index[i] = count;
        }
        for(i = 0; i < len; i++) max = max > index[i] ? max : index[i];
        return max;
}       
//MORE EFFICIENT
int lengthOfLongestSubstring(char* s)
{
        int len = strlen(s), max = 0, count,i,j;
        int index[1000000]; index[0] = 1;
        if(len < 1) return 0; if(len == 1) return 1;
        for(i = 1; i < len; i ++)
        {
                count = index[i-1] + 1;
                for(j = i - count + 1; j< i; j++)
                {
                        if(s[j] == s[i])
                        {
                                index[i] = i - j;
                                break;
                        }
                }
                if(j == i)
                {
                        index[i] = count;
                }
                max = max > index[i] ? max : index[i];
        }
        return max;
}       
