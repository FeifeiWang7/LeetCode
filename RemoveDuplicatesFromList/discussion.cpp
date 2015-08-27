class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* cur = head;
        while (cur) {
            while (cur->next && cur->val == cur->next->val)
                cur->next = cur->next->next;
            cur = cur->next;
        }
        return head;
    }
};
Note about freeing memory. We need to free memory when we delete a node. But don't use delete node; construct on an interview without discussing it with the interviewer. A list node can be allocated in many different ways and we can use delete node; only if we are sure that the nodes were allocated with new TreeNode(...);.


The is no need to use two while loop and also no need to use recursion

public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return head;

        ListNode cur = head;
        while(cur.next != null) {
            if (cur.val == cur.next.val) {
                cur.next = cur.next.next;
            }
            else cur = cur.next;
        }
        return head;
    }
}

One 'if' and one 'while', the simplest you can ever get:

ListNode *deleteDuplicates(ListNode *head) {
    ListNode*cur=head,*tail=head;
    while(cur){
        if(cur->val!=tail->val){
            tail->next=cur;
            tail=cur;
        }
        cur=cur->next;
        tail->next=NULL;
    }
    return head;
}

I think that instead of using two while cycles this can be solved using only one and recursion. With something like this:

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if ( head == NULL ) return head;
        ListNode *list = head;
        while( list != NULL && list -> next != NULL )
        {
            if ( list -> val == list -> next -> val )
            {
                list -> next = list -> next -> next;
                deleteDuplicates( list );
            }
            list = list -> next;
        }
        return head;
    }
};

The only way to delete the not needed node in java that I know of is to null out the node to avoid loitering. What are the proper ways to do that in C++?


