ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fast = head, **cur = &head;
    while(n--) fast = fast->next;
    while (fast) {
        fast = fast->next;
        cur = &(*cur)->next;  }
    *cur = (*cur)->next;
    return head;
}

