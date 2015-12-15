typedef int hashKeyT; /* specify hash key data type */
typedef int    hashValueT;
typedef struct
{
	hashKeyT key; /* key */
	hashValueT value; /* value */
	UT_hash_handle hh;
}hashEntryT;	

void HashInit(hashEntryT **hashMap)
{
	*hashMap = NULL;
}
hashEntryT *HashFind(hashEntryT **hashMap, hashKeyT key)
{
	hashEntryT *s;
	HASH_FIND(hh, *hashMap, &key, sizeof(hashKeyT), s);
	return s;
}
void HashAdd(hashEntryT **hashMap, hashKeyT key, hashValueT value)
{
	hashEntryT *s;
	HASH_FIND(hh, *hashMap, &key, sizeof(hashKeyT), s);
	if(s == NULL) /* not found */
	{
		s = (hashEntryT *)malloc(sizeof(hashEntryT));
		s -> key = key;
		HASH_ADD(hh, *hashMap, key, sizeof(hashKeyT), s);
	}
	memcpy(&(s -> value), &value, sizeof(hashValueT));
}
void HashDelete(hashEntryT **hashMap, hashEntryT *s)
{
	HASH_DEL(*hashMap, s);
	free(s);
}
void HashDeleteAll(hashEntryT **hashMap)
{
	hashEntryT *current, *tmp;
	HASH_ITER(hh, *hashMap, current, tmp)
	{
		HASH_DEL(*hashMap, current);
		free(current);
	}
}
int HashMax(hashEntryT **hashMap)
{
	hashEntryT *current, *tmp;
	int max = 0;
	HASH_ITER(hh, *hashMap, current, tmp)
	{
		max = max > current->value? max: current->value;
	}
	return max;
}
int HashCount(hashEntryT **hashMap)
{
	return HASH_COUNT(*hashMap);
}
void HashClear(hashEntryT **hashMap)
{
	HASH_CLEAR(hh, *hashMap);
}

int maxPoints(struct Point* points, int pointsSize) 
{	
	hashEntryT *hashMap, *s;
	int i, j, max = 0;
	if(pointsSize <= 2) return pointsSize;
	HashInit(&hashMap);
	for(i = 2; i < pointsSize; i++)
	{
		int compare = 0; int samepoint= 1; int vertical= 0;
		for(j = 0; j < i; j++)
		{
			if(points[i].x == points[j].x) 
			{
				if(points[i].y == points[j].y)
				{
					samepoint++;
				}
				else
				{
					vertical++;
				}
			}
			else 
			{
				int slope = (points[i].y - points[j].y)*1000000/ (points[i].x - points[j].x);
				s = HashFind(&hashMap, slope);
				if(s == NULL) HashAdd(&hashMap, slope, 1);
				else HashAdd(&hashMap, slope, s->value+1);
			}
		}
		compare = vertical > HashMax(&hashMap) ? vertical : HashMax(&hashMap);
		compare = compare + samepoint;
		max = max > compare ? max : compare;
		HashDeleteAll(&hashMap);
	}    
	return max;
}

