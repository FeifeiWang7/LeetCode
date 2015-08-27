public ListNode deleteDuplicates(ListNode head) {
    if(head == null) return null;

    ListNode notDuplic = head;
    ListNode index = head.next;

    while(index!=null){
        if(notDuplic.val != index.val){
            notDuplic.next = index;
            notDuplic = index;
        }

        index = index.next;
    }

    notDuplic.next =null;

    return head;
}
