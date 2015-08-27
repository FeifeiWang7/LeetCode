if (head) {
    struct ListNode *p = head;
    while (p->next) {
        if (p->val != p->next->val) {
            p = p->next;
        }
        else {
            struct ListNode *tmp = p->next;
            p->next = p->next->next;
            free(tmp);
        }
    }
}

return head;
