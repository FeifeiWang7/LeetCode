class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)
            return NULL;
       if( head->next == NULL)
            return head;

        ListNode *p = head,*tmp = NULL;
        while(p){
            tmp = p;
            p = p->next;
            while(p&&p -> val == tmp->val)
                p = p->next;
            tmp->next = p;
        }
        return head;
    }
};

……
    ListNode *p = head, *tmp = NULL, *del = NULL;
    while (p) {
        tmp = p;
        p = p->next;
        while (p && p->val == tmp->val) {
            del = p;
            p = p->next;
            delete del;
        }
        tmp->next = p;
    }
    ……
