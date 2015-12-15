ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode* head;
    ListNode** pp = &head;
    int carry = 0;
    while (l1 || l2 || carry) {
        int digit = carry;
        if (l1) {
            digit += l1->val; l1 = l1->next;
        }
        if (l2) {
            digit += l2->val; l2 = l2->next;
        }
        carry = digit / 10;
        digit %= 10;
        ListNode* newNode = new ListNode(digit);
        *pp = newNode;
        pp = & (*pp)->next;
    }
    return head;
}
//recursion
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
    if(!l1 && !l2) {
        if(carry) return new ListNode(carry);
        else return NULL;
    }
    int val = carry + (l1?l1->val:0) + (l2?l2->val:0);
    ListNode* newNode = new ListNode(val%10);
    newNode->next = addTwoNumbers(l1?l1->next:NULL, l2?l2->next:NULL, val/10);
    return newNode;
}
