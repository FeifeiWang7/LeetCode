My original code: Runtime - 22 ms

#include <stddef.h>

struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {
        head = head->next;
    }
    if (head == NULL)
        return NULL;

    struct ListNode *p = head, *q = head->next;
    while (q != NULL) {
        if (q->val == val) {
            q = q->next;
            p->next = q;
        }
        else {
            p = q;
            q = q->next;
        }
    }
    return head;
}
Compared with this one by a clever guy: My step by step 12 ms C solution

As you see, our code are identical, except for the position of two variable definitions. (you say "and variables' name"? oh, come on, don't be so picky) Then, I moved the definition instructions to function top:

#include <stddef.h>

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *p = NULL, *q = NULL;

    while (head != NULL && head->val == val) {
        head = head->next;
    }
    if (head == NULL)
        return NULL;

    p = head, q = head->next;
    while (q != NULL) {
        if (q->val == val) {
            q = q->next;
            p->next = q;
        }
        else {
            p = q;
            q = q->next;
        }
    }
    return head;
}
Runtime reduced to 12 ms. Why?

P.S. I compiled both code on my PC(64bit, ubuntu, gcc) and disassembled them, only to find the faster (12ms) version, on the contrary, has two more instructions to set the variables zero. All other parts of the disassembled code are the same.
////
ListNode* removeElements(ListNode* head, int val) {
    ListNode **pp = &head;
    while (*pp)
        if ((*pp)->val == val)
            *pp = (*pp)->next;
        else
            pp = &(*pp)->next;
    return head;
}
/////
struct ListNode* removeElements(struct ListNode* head, int val) {

struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
dummy->val=INT_MAX;
dummy->next=head;
struct ListNode* prev=dummy; 
struct ListNode* Next=NULL;    
struct ListNode* curr=dummy->next;    

while(curr){
    Next=curr->next;

    if(curr->val==val){
        prev->next=curr->next;
        free(curr);
    }
    else
        prev=curr;

    curr=Next;  
}

return dummy->next;
}
///////
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode **prev, *curr;

    prev = &head;
    curr = head;

    while (curr) {
        if (curr->val == val)
            *prev = curr->next;
        else 
            prev = &(curr->next);
        curr = curr->next;
    }
    return head;
}
/////
typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val) {
    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = head;
    ListNode* p = dummy;
    while( NULL != p->next){
        if( val == p->next->val ) p->next = p->next->next;
        else p = p->next;
    }
    return dummy->next;
}
