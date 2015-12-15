I have a simple question. My version of solution worked pretty well. But I think that there should be test for long list.

For example, my version based on recursion and it wouldn't work on long list. But it was accepted.

ListNode* removeElements(ListNode* head, int val) {
    if (head == NULL)
        return head;
    if (head->next == NULL && head->val == val)
    {
        delete head;
        return NULL;
    }
    if (head->val == val)
    {
        ListNode *next = head->next;
        head->val = next->val;
        head->next = next->next;
        delete next;
        return removeElements(head, val);
    }

    if (removeElements(head->next, val) == NULL)
        head->next = NULL;
    return head;
}
////
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode * tmp = head;
        ListNode * prevTmp = NULL;

        while(tmp)
        {
            if(tmp->val == val)
            {
                if(prevTmp)
                {
                    prevTmp->next = tmp->next;
                    tmp = tmp->next;
                }
                else
                {
                    head = tmp->next;
                    tmp = tmp->next;
                }
            }
            else
            {
                prevTmp = tmp;
                tmp = tmp->next;
            }
        }

        return head;
    }
};
////
ListNode *removeElements(ListNode *head, int val)
{
    ListNode **list = &head;

    while (*list != nullptr)
    {
        if ((*list)->val == val)
        {
            *list = (*list)->next;
        }
        else
        {
            list = &(*list)->next;
        }
    }

    return head;
}
Original recursive version:

void removeHelper(ListNode *&head, int val)
{
    if (head == nullptr)
    {
        return;
    }
    else if (head->val == val)
    {
        head = head->next;
    }
    else
    {
        removeHelper(head->next, val);
    }
}
/////
The comment part at last is another code that can pass all the test with one more variable.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newHead = head, *curr = head;
        while(curr) {
            if(newHead->val == val) {
                curr = newHead->next;
                newHead = newHead->next;
                continue;
            }
            if(curr->next != NULL) 
                if(curr->next->val == val) {
                    curr->next = curr->next->next;
                    continue;
                }
            curr = curr->next;
        }
        return newHead;

        /*ListNode* listPtr = head, *pre = head, *newHead = head;
        while(listPtr != NULL) {
            if(newHead->val == val) {
                pre = newHead->next;
                listPtr = newHead->next;
                newHead = newHead->next;
                continue;
            }
            if(listPtr->val == val) pre->next = listPtr->next;
            else pre = listPtr;
            listPtr = listPtr->next;
        }
        return newHead;*/
    }
};
///
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pseudo_head = new ListNode(0);
        pseudo_head->next = head;
        ListNode *cur = pseudo_head;
        while(cur){
            if(cur->next && cur->next->val == val)   cur->next = cur->next->next;
            else    cur = cur->next;
        }
        return pseudo_head->next;
    }
};
///////
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
    ListNode* removeElements(ListNode* head, int val) {
        if (head==NULL){
            return head;
        }
        ListNode* p=head;
        while(p->next!=NULL){
            if (p->next->val == val){
                p->next = p->next->next;
            }
            else{
                p=p->next;
            }
        }
        if (head->val==val)
            head=head->next;
        return head;
    }
};
///
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head != NULL)
        {
            (head->val == val ? head : head->next) = removeElements(head->next, val);
        }
        return head;
    }
};
/////
ListNode* removeElements(ListNode* head, int val) {
if (head == NULL)
{
    return NULL;
}
ListNode* dummy = new ListNode(0);
dummy->next = head;
ListNode* dummyTmp = dummy;
while (dummy != NULL && dummy->next != NULL)
{
    while (dummy->next != NULL && dummy->next->val ==  val)
    {
        dummy->next = dummy->next->next;
    }
    dummy = dummy->next;
}
return dummyTmp->next;
}


