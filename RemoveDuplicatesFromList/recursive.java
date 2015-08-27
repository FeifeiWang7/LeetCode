public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null) {
            return head;
        }
        ListNode distinct = head;
        while(distinct.next != null && distinct.next.val == head.val) {
            distinct = distinct.next;
        }

        head.next = deleteDuplicates(distinct.next);

        return head;
    }
}
