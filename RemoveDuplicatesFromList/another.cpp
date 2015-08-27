ListNode *deleteDuplicates(ListNode *head) {
    if (NULL == head) return head;
    ListNode *cur = head, *nxt = head->next;

    while (nxt) {
        // find the next different one
        while (nxt && (cur->val == nxt->val))
            nxt = nxt->next;
        cur = cur->next = nxt;
        if (nxt) nxt = nxt->next;
    }

    return head;
}

 /* modified to a more concise one */
ListNode *deleteDuplicates(ListNode *head) {
    if(NULL == head) return head;

    ListNode *cur = head, *nxt = head->next;
    while (nxt) {
        if (cur->val != nxt->val) 
            cur = cur->next = nxt;
        else if (!nxt->next)
            cur->next = nxt->next;
        nxt = nxt->next;
    }

    return head;
}
