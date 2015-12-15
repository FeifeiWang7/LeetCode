struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *ptr1=head, *ptr2=head->next, *ptr3=head->next->next;
    ptr1->next = NULL;
    while(ptr3 != NULL) {
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
    }
    ptr2->next = ptr1;
    return ptr2;
}
bool isPalindrome(struct ListNode* head) {
    int length = 0;
    struct ListNode *ptr = head;
    while(ptr != NULL) {
        length += 1;
        ptr = ptr->next;
    }
    if(length <= 1) {
        return true;
    }
    struct ListNode *first_half = head;
    ptr = head;
    for(int i=0; i<length/2-1; i++) {
        ptr = ptr->next;
    }
    struct ListNode *second_half = ptr->next;
    if(length % 2 != 0) {
        second_half = second_half->next;
    }
    ptr->next = NULL;
    second_half = reverseList(second_half);
    while(first_half != NULL && second_half != NULL) {
        if(first_half->val != second_half->val) {
            return false;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }
    return true;
}
/////
bool isPalindrome(struct ListNode* head) {

struct ListNode* slow = head;
struct ListNode* fast = head;
struct ListNode* median = NULL;
struct ListNode* tail = NULL;

if (head == NULL || head->next == NULL)
    return true;

while (fast->next != NULL)//The index number of slow is the floor of (N+1)/2
{
    fast = fast->next;
    if(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
}
median = slow->next;//This median is the head of the right part of the list. it's not a true median.
tail = fast;

ReverseList(median);

while(fast != NULL)
{
    if(head->val != fast->val)
    {
        ReverseList(tail);//Recover the parameter list
        return false;
    }
    head = head->next;
    fast = fast->next;
}
ReverseList(tail);//Recover the parameter list
return true;
}

void ReverseList(struct ListNode* head) { struct ListNode* preNode = NULL; struct ListNode* thisNode = head; struct ListNode* nxtNode = head->next;

while(thisNode != NULL)
{
    if(nxtNode != NULL)
    {
        thisNode->next = preNode;
        preNode = thisNode;
        thisNode = nxtNode;
        nxtNode = nxtNode->next;
    }
    else
    {
        thisNode->next = preNode;
        preNode = thisNode;
        thisNode = nxtNode;
    }
}
}
/////
def isPalindrome(self, head):
    fast = slow = head
    # find the mid node
    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next
    # reverse the second half
    node = None
    while slow:
        nxt = slow.next
        slow.next = node
        node = slow
        slow = nxt
    # compare the first and second half nodes
    while node: # while node and head:
        if node.val != head.val:
            return False
        node = node.next
        head = head.next
    return True
/////
Firstly, finding the middle node of the list.Secondly, reversing the botton half list.Finally,comparing the val.

struct ListNode* reverseList(struct ListNode* head) {
    if(!head || !head->next)
        return head;
    struct ListNode *p,*q,*r;
    p = head;
    q = p->next;
    p->next = NULL;
    while(q->next){
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    q->next = p;
    return q;
    }

bool isPalindrome(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    //get the middle node
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
    }
    ///reverse the bottom half list
    struct ListNode* rHead = reverseList(slow);
    while(head != NULL && rHead != NULL){
        if(head->val != rHead->val)
            return false;
        head = head->next;
        rHead = rHead->next;
    }
    return true;
}

///
when come to single linked list,there are few primary operations you should always keep in mind,like reverse,merge,find certain node etc.then u can solve all the problems with a combination of these operations.

bool isPalindrome(struct ListNode* head) {
    if(!head || !head->next) return true;

    struct ListNode *pslow=head;
    struct ListNode *pfast=head->next;
    struct ListNode *pp=NULL;
    struct ListNode *pt=NULL;
    struct ListNode *ph=NULL;

    //reverse the first half
    while(pfast && pfast->next){
        pt=pslow->next;
        pslow->next=pp;
        pp=pslow;
        pslow=pt;
        pfast=pfast->next->next;
    }
    //odd or even
    pt=pslow->next;
    if(pfast){
        pslow->next=pp;
        head=pslow;
        ph=pt;
    }else{
        head=pp;
        ph=pslow;
    }
    //restore and judge
    bool res=true;
    while(head){
        if(res && head->val!=pt->val){
            res=false;
        }
        pp=head->next;
        head->next=ph;
        ph=head;
        head=pp;
        pt=pt->next;
    }

    return res;
}
///
struct ListNode* reverse(struct ListNode* head){
if(head==NULL)
    return NULL;
struct ListNode* curr=head;
struct ListNode* prev=NULL;
struct ListNode* NextNode=NULL;
while(curr){

    NextNode=curr->next;
    curr->next=prev;
    prev=curr;
    curr=NextNode;
}
return prev;
}
bool isPalindrome(struct ListNode* head) {
if(head==NULL)
    return true;
struct ListNode* fast=head;
struct ListNode* slow=head; 

while(fast->next!=NULL && fast->next->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
}
slow->next=reverse(slow->next);
slow=slow->next;

while(slow!=NULL){
    if(head->val!=slow->val)
        return false;
    slow=slow->next;
    head=head->next;
}
return true;
}
