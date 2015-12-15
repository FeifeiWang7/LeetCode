I haven't found any C solution sharing. I Implemented the hash table by my self. Not sure if it is the best way to implement the hash table using a k-array, every element of which is a list, in order to deal with hash duplication. Is it the best way to implement the hash table?

struct Node{
    int value;
    int id;
    struct Node* next;
};
struct Node* insert(int new_value, int new_id, struct Node* old_list)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->value = new_value;
    new_node->id = new_id;
    new_node->next = old_list;
    return new_node;
}
void deleteNextNode(struct Node* node)
{
    if (node == NULL || node->next == NULL)
        return;
    struct Node* tmp = node->next;
    node->next = node->next->next;
    free(tmp);  
}
bool check(struct Node* list, int value, int id, int k)
{
    /* return true: find collision*/
    if (list == NULL)
        return false;
    if (id - list->id <= k && list->value == value)
        return true;
    for (struct Node* p = list; p->next != NULL;)
    {
        if (id - p->next->id > k)
        {
            deleteNextNode(p);
            continue;
        }
        if (p->next->value == value)
            return true;
        p = p->next;
    }
    return false;
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (k == 0)
        return false;
    struct Node** hash = (struct Node**)malloc(sizeof(struct Node*)*k);
    memset(hash, NULL, sizeof(struct Node*)*k);
    for (int id = 0; id < numsSize; id++)
    {
        int hash_id = nums[id]%k;
        if (check(hash[hash_id], nums[id], id, k))
            return true;
        hash[hash_id] = insert(nums[id], id, hash[hash_id]);
    }
    return false;
}
int main()
{
    int nums[3] = { 1, 2, 1 };
    int numsSize = 3;
    int k = 0;
    char* rtn = containsNearbyDuplicate(nums, numsSize, k) ? "true" : "false";;
    printf("%s", rtn);
    return 0;
}
////
Accepted C code Hashtable :

struct Node{

int val;
struct Node *next;//LL prevent collison //separate Chaining
};

struct Set{

int bucketSize;
struct Node **table;
};

void initSet(struct Set *set, int bucketSize){

set->bucketSize = bucketSize;
set->table =(struct Node**)malloc(sizeof(struct Node*) * bucketSize);
memset(set->table, 0, sizeof(struct Node*) * bucketSize);
}

bool addValue(struct Set *s, int val){

 int idx = val > 0 ? val : -val;
idx %= s->bucketSize;
struct Node *ptr = s->table[idx];
while(ptr != NULL)
{
    if(ptr->val == val)
    {
        return false;
    }

    ptr = ptr->next;
}
ptr = (struct Node*)malloc(sizeof(struct Node));
ptr->val = val;
ptr->next = s->table[idx];
s->table[idx] = ptr;
return true;
}

void releaseSet(struct Set *s){

struct Node *ptr, *tmp;
for(int i = 0; i < s->bucketSize; ++i)
{
    ptr = s->table[i];
    while(ptr != NULL)
    {
        tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
}
free(s->table);
s->table = NULL;
s->bucketSize = 0;
}

void removeVal(struct Set *s, int val){

struct Node *prevnode=NULL;
struct Node *tmp=NULL;
int idx = val > 0 ? val : -val;

idx %= s->bucketSize;
struct Node *ptr = s->table[idx];
struct Node *Prevptr=NULL;

while(ptr != NULL && ptr->val!=val)
{
            Prevptr=ptr;
    ptr = ptr->next;        
}

    if(ptr!=NULL && ptr->val==val)
   {

       if(Prevptr==NULL)
             s->table[idx]=ptr->next;
       else
            Prevptr->next=ptr->next;

         free(ptr);
    }
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {

if(numsSize < 2)
{
    return false;
}
struct Set set;

initSet(&set, numsSize);
for(int i = 0; i < numsSize; ++i)
{

    if(i>k)
    {
        removeVal(&set,nums[i-k-1]);
    }
    if(!addValue(&set, nums[i]))
    {
        releaseSet(&set);
        return true;
    }

}
releaseSet(&set);

return false;
}
