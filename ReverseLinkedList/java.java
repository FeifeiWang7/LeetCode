public class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode preHead = new ListNode(0);
        preHead.next = head;
        ListNode tail = head;
        ListNode runner = head.next;
        while (runner != null) {
            ListNode tmp1 = preHead.next;
            ListNode tmp2 = runner.next;
            preHead.next = runner;
            runner.next = tmp1;
            runner = tmp2;
        }
        tail.next = null;
        return preHead.next;
    }
}
/////
// Recursion:

public ListNode reverseList(ListNode head) {
    return helper(null, head);
}

ListNode helper(ListNode reversed, ListNode remaining) {
    if(remaining==null) return reversed;
    ListNode tmp = remaining.next;
    remaining.next = reversed;

    return helper(remaining, tmp);
}
// Iteration:

public ListNode reverseList(ListNode head) {
    if(head==null) return head;

    ListNode newhead = new ListNode(0);
    newhead.next = head;

    while(head.next!=null) {
        ListNode tmp = head.next;
        head.next = head.next.next;

        tmp.next = newhead.next;
        newhead.next = tmp;
    }
    return newhead.next;
}
/////
public class Solution {
    public ListNode reverse(ListNode head, ListNode prev) {
        if(head == null) return prev;

        ListNode newHead = reverse(head.next, head);
        head.next = prev;
        return newHead;
    }
    public ListNode reverseList(ListNode head) {
        return reverse(head, null);
    }
}
////
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseList(ListNode curr){
        if(curr==null) return curr;
        ListNode rest = curr.next;
        if(rest==null) return curr;
        rest = reverseList(rest);
        curr.next.next = curr;    //  Here is the trick
        curr.next =null;          //
        return rest;
    }
}
/////
public ListNode reverseList(ListNode head) {
   ListNode newHead = null;
   //iterative
   while(head!=null){
       ListNode tmp = head;
       head =head.next;// move the current pointer must be here，otherwise the pointer will be changed
       tmp.next=newHead;
       newHead=tmp;
   }
   return newHead; 
}
//////
Iteratively:

public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null)
            return head;
        ListNode pre = null;
        ListNode curr = head;
        while(curr != null){
            ListNode next = curr.next;
            curr.next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
Recursively:

public class Solution {     
     public ListNode reverseList(ListNode head) {         
             if(head == null || head.next == null)             
                     return head;         
             ListNode second = head.next;        
             head.next = null;         
            ListNode newHead = reverseList(second);         
            second.next = head;         
            return newHead;     
        } 
     }
//////
/** * Definition for singly-linked list. * public class ListNode { * int val; * ListNode next; * ListNode(int x) { val = x; } * } */

public class Solution {

public ListNode reverseList(ListNode head) {
    return reverseList(head, null);
}

private ListNode reverseList(ListNode head, ListNode prev) {
    if(head == null){
        return prev;
    }else{
        ListNode next= head.next;
        head.next = prev;
        return reverseList(next, head);
    }
}
}
///
public class Solution {
    public ListNode reverseList(ListNode head) {
        if(head==null || head.next==null)
            return head;
        ListNode nextNode=head.next;
        ListNode newHead=reverseList(nextNode);
        nextNode.next=head;
        head.next=null;
        return newHead;
    }
}
/////
public ListNode reverseList(ListNode head) {
    ListNode first = null;
    ListNode tail = head;
    while (tail != null) {
        ListNode tmp = tail;
        tail = tail.next;
        tmp.next = first;
        first = tmp;
    }
    return first;
}
