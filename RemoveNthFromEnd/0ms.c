int recurseList(struct ListNode* node, int n) {
    if (node->next == NULL)
        return 1;

    int rc = recurseList(node->next, n);

    if (rc == n) {
        node->next = node->next->next;
    }
    return rc + 1;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int rc = recurseList(head, n);
    if (rc == n) {
        if (n == 1)
            head = NULL;
        else
            head = head->next;
    }

    return head;
}
