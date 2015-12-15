class Solution { public: ListNode* reverseList(ListNode* head) {

    if(!head) return nullptr;
    ListNode *p= head, *pPre = nullptr;

    while(p) {
        ListNode* tmp = p->next;
        p->next = pPre;  
        pPre = p;
        p = tmp;
    }

    return pPre;
}
};
///////
ListNode * reverseList( ListNode * head )
    {
        if( !head || !head->next ) return head;

        ListNode * t1 = head;
        head = t1->next;
        ListNode * t2 = head->next;

        t1->next = 0;
        head->next = t1;

        while( t2 )
        {
            t1 = t2->next;
            t2->next = head;
            head = t2;
            t2 = t1;
        }
        return head;
    }
////
xWell, since the head pointer may also be modified, we create a new_head that points to it to facilitate the reverse process.

For the example list 1 -> 2 -> 3 -> 4 -> 5 in the problem statement, it will become 0 -> 1 -> 2 -> 3 -> 4 -> 5 (we init new_head -> val to be 0). Then we set a pointer pre to new_head and another cur to head. Then we keep inserting cur -> next after pre until cur becomes the last node. The code is follows.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        ListNode* cur = head; 
        while (cur && cur -> next) {
            ListNode* temp = pre -> next;
            pre -> next = cur -> next;
            cur -> next = cur -> next -> next; 
            pre -> next -> next = temp;
        }
        return new_head -> next;
    }
};
This link provides a more concise solution without using the new_head. The idea is to reverse one node at a time for the beginning of the list. The rewritten code is as follows.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while (head) {
            ListNode* next = head -> next;
            head -> next = pre;
            pre = head;
            head = next;
        } 
        return pre;
    }
};
Well, both of the above solutions are iterative. The hint has also suggested us to use recursion. In fact, the above link has a nice recursive solution, whose rewritten code is as follows.

class Solution {
public:   
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head -> next)) return head;
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node; 
    }
}; 
The basic idea of this recursive solution is to reverse all the following nodes after head. Then we need to set head to be the final node in the reversed list. We simply set its next node in the original list (head -> next) to point to it and sets its next to be NULL.

///////
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = nullptr;
        while (curr) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        return prev;
    }
};
////
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)
        return head;

        ListNode* Dummy=new ListNode(-1);
        Dummy->next=head;
        ListNode* cur=head->next;
        head->next=nullptr;
        while(cur){
            ListNode* tmp=cur->next;
            Dummy->next=cur;
            cur->next=head;
            head=cur;
            cur=tmp;
        }
        return Dummy->next;
    }
};
///
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *temp = NULL , *nextNode = NULL;
        while(head){
            nextNode = head->next;
            head->next = temp;
            temp = head;
            head = nextNode;
        }
        return temp;
    }
};
