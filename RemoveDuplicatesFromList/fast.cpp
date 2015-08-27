class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)
            return head;
        ListNode *headrecord=head;
        while(head->next)
        {
            if(head->val==head->next->val)
            {
                ListNode *record=head->next->next;
                delete(head->next);
                head->next=record;
            }
            else
                head=head->next;
        }
        return headrecord;
    }
};
