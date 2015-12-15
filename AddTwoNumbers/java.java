public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    int carry = 0;
    ListNode head = l1;
    ListNode prev = l1;
    while (l2 != null || carry != 0) {
        if (l1 == null) {
            l1 = new ListNode(0);
            prev.next = l1;
        }
        if (l2 != null) {
            l1.val += (l2.val + carry);
            l2 = l2.next;
        } else {
            l1.val += carry;
        }
        carry = l1.val / 10;
        l1.val %= 10;
        prev = l1;
        l1 = l1.next;
    }
    return head;
}
///
private ListNode addTwoNumbersRec(int carry, ListNode l1, ListNode l2) {
    if (l1 == null && l2 == null && carry == 0)
        return null;

    int l1Val = l1 != null ? l1.val : 0;
    int l2Val = l2 != null ? l2.val : 0;
    ListNode l1Next = l1 != null ? l1.next : null;
    ListNode l2Next = l2 != null ? l2.next : null;

    int sum = l1Val + l2Val + carry;
    int val = sum % 10;
    int newCarry = sum / 10;

    ListNode newNode = new ListNode(val);
    newNode.next = addTwoNumbersRec(newCarry, l1Next, l2Next);

    return newNode;
}

public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    return addTwoNumbersRec(0,l1,l2);
}
