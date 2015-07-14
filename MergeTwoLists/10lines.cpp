ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    dummy.next = l1;
    ListNode *cur = &dummy;

    while(l2)
    {
        while(cur->next && cur->next->val<=l2->val) cur = cur->next; // if the current list, l1, has a smaller value, then move cur forward
        l1 = cur->next; // otherwise, switch l1 and l2
        cur->next = l2;
        l2 = l1;
    }
    return dummy.next;
}
