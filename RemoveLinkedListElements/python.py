dummy = ListNode(0)
    dummy.next = head
    current = head
    prev = dummy

    while current:
        if current.val == val:
            prev.next = current.next
            current = current.next
        else:
            tmp = current.next
            prev = current
            current = tmp
    return dummy.next
