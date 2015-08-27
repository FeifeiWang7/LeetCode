public class Solution {
public ListNode deleteDuplicates(ListNode head) {
    ListNode curP = head;
    while(curP!=null){
        while(curP.next!=null&&curP.val ==curP.next.val){
            curP.next = curP.next.next;
        }
        curP=curP.next;
    }
    return head;
}
}
