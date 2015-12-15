struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL||head->next==NULL) return head;
    struct ListNode* p1 = head, *p2=p1->next, *p3=p2;
    while(p2 != NULL){
        p3 = p2->next; p2->next = p1; p1=p2;p2=p3;
    }
    head->next=NULL;
    head = p1; 
}
////
code 1 :

struct ListNode* reverselink(struct ListNode* head){

if(head == NULL) 
          return NULL;

struct ListNode* pev,*tmp;
pev = tmp = NULL;

while(head->next != NULL)
{
    tmp = head->next;
    head->next = pev;
    pev = head;
    head = tmp;
}

head->next = pev;
return head;
}

code 2:

struct ListNode* ReverseList_Digui(struct ListNode* pHead) {

if(pHead->next == NULL)
    return pHead;

struct ListNode* rHead = ReverseList_Digui(pHead->next);

pHead -> next -> next = pHead;
pHead -> next = NULL;

return rHead;
}

struct ListNode* reverseList(struct ListNode* head) {

if(head == NULL || head->next == NULL)
    return head;

return ReverseList_Digui(head);
}
