if(node.next==null) { return; } ; node.val = node.next.val; node.next = node.next.next;;

///
public void deleteNode(ListNode node) {

    node.val = node.next.val;
    node.next = node.next.next;

}
///
public class Solution {


     public void deleteNode(ListNode node) {
            if(node.next==null){
                return;
            }
            node.val = node.next.val;
            if(node.next.next==null){
                node.next=null;
                  return;
            }
            deleteNode(node.next);
            return;
        }

}
