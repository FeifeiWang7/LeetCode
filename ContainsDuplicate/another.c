typedef struct hashlist {
     int val;
     struct hashlist *next;
}list;

int containsDuplicate(int* nums, int numsSize) {
    int i;
    int mask = numsSize - 1;
    list *tmp[numsSize];
    memset(tmp, 0, sizeof(list*)*numsSize);
    if(numsSize == 0 || numsSize == 1) {
        return false;
    }
    for(i=0; i < numsSize; i++) {
        int idx;
        list *p;
        list *node = malloc(sizeof(list));
        node->val = *nums;
        idx = abs(*nums) % mask;    
        p = tmp[idx];
        node->next = p;
        tmp[idx] = node;
        while(p) {
            if (p->val == node->val) {
                return true;
            }
            p = p->next;
        }
        nums++;
    }
    return false;
}
/////
I implemented separate chaining with arrays. It took 16-20 ms. However, I saw that most C solutions takes only 12 ms. How can I improve this. Does it help to use linked lists instead?

struct chain{
    int size;
    int capacity;
    int* head;
};

void chainInsert(struct chain* chn, int num){
    if(chn->size == chn->capacity){
        chn->capacity = chn->capacity*2;
        int* tmp = (int*)malloc(chn->capacity*sizeof(*tmp));
        for(int i=0; i != chn->size; i++){
            tmp[i] = chn->head[i];
        }
        chn->head = tmp;
    }
    chn->head[chn->size] = num;
    chn->size++;
};


bool containsDuplicate(int* nums, int numsSize) {
    int tableSize = 2*numsSize;
    struct chain* table = (struct chain*)malloc(tableSize*sizeof(*table));
    //initialization
    for(int i=0; i!= tableSize; i++){
        table[i].size = 0;
        table[i].capacity = 1;
        table[i].head = (int*)malloc(sizeof(*(table[i].head)));
    }

    for(int i=0; i!= numsSize; i++){
        int index = nums[i]%(tableSize);
        index = index > 0? index: index+tableSize;

        struct chain* chn = &table[index];
        for(int j =0; j < chn->size; j++){
            if(chn->head[j] == nums[i])
                return true;
        }
        chainInsert(chn, nums[i]);

    }

    return false;
}
/////////
typedef struct node_s node;
struct node_s 
{ 
	int val; 
	node *next; 
}; 
typedef struct 
{ 
	node* head; 
	node* last; 
}hash; 

int myabs(int a)
{ return a>=0?a:-a; } 

bool containsDuplicate(int* nums, int numsSize) 
{ 
	hash *table=(hash*)malloc(sizeof(hash)*100); 
	int i,j,index; 
	for(i=0;i<100;i++) 
		table[i].head=table[i].last=NULL; 
	for(i=0;i<numsSize;i++)
	{ 
		index=myabs(nums[i])%100; 
		if(table[index].head==NULL)
		{ 
			table[index].head=(node*)malloc(sizeof(node)); 
			table[index].head->val=nums[i]; 
			table[index].last=table[index].head; table[index].last->next=NULL; }else{ node*p=table[index].head; while(p){ if(p->val==nums[i]) return true; p=p->next; } p=(node*)malloc(sizeof(node)); p->val=nums[i]; p->next=NULL; table[index].last->next=p; table[index].last=p; } } return false; }
