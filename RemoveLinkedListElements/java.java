public class Solution {
        public ListNode removeElements(ListNode head, int val) {
            if (head == null) return head;

            ListNode dummy = new ListNode(0);
            dummy.next = head;
            ListNode prev = dummy;

            while (prev.next != null) {
                if (prev.next.val == val) {
                    prev.next = prev.next.next;
                } else {
                    prev = prev.next;
                }
            }

            return dummy.next;
        }
    }
//////////////
public class Solution {
public ListNode removeElements(ListNode head, int val) {
     if(head==null)
        return head;
    if(head.next==null)
        return head.val==val?null:head;
    while(head!=null&&head.val==val)
        head=head.next;
    if(head==null)
        return head;
    head.next=removeElements(head.next,val);
    return head;
}
}
/////////////
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode result = head;
        if (result == null) {
            return null;
        } else if (result.val == val) {
            return removeElements(result.next, val);
        } else {
            result.next = removeElements(result.next, val);
        }
        return result;
    }
}
///
public class Solution {
public ListNode removeElements(ListNode head, int val) {

    /*Trick:
     *using a headnode , headnode's next always point to the real head
     *headnode don't save data, but it can simplify the delete operation
     */
    ListNode headNode = new ListNode(0); 
    headNode.next = head;

    ListNode pre = headNode;

    while(head != null){

        if(head.val == val)
            pre.next = head.next ; //remove element
        else
            pre=pre.next;

        head = head.next; //move to next
    }

    return headNode.next;

}
}
////
class Solution {
    public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)     return NULL;
        if (head->val == val) return removeElements(head->next,val);
        head->next = removeElements(head->next,val);
        return head;

    }
};
///
public ListNode removeElements(ListNode head, int val) {
    if (head == null) return null;
    ListNode pointer = head;
    while (pointer.next != null) {
        if (pointer.next.val == val) pointer.next = pointer.next.next;
        else pointer = pointer.next;
    }
    return head.val == val ? head.next : head;
}
//////
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        while(head != null && head.val == val) {
            head = head.next;
        }
        if(head == null) {
            return head;
        }
        ListNode p = head;
        while(p.next != null) {
            if(p.next.val == val) {
                p.next = p.next.next;
            } else {
                p = p.next;
            }
        }
        return head;
    }
}

/////
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        while(head != null && head.val == val) {
            head = head.next;
        }
        if(head == null) {
            return head;
        }
        ListNode p = head;
        while(p.next != null) {
            if(p.next.val == val) {
                p.next = p.next.next;
            } else {
                p = p.next;
            }
        }
        return head;
    }
}
//////
public class Solution {

public ListNode removeElements(ListNode head, int val) {

    ListNode dummy = new ListNode(1);
    ListNode i = dummy;
    ListNode j = head;
    dummy.next = head;

    while(j != null){
        if(j.val == val){
            i.next = i.next.next;
            j = j.next;
        }else{
            i = i.next;
            j = j.next;
        }
    }

    return dummy.next;
}
}

/////
public class Solution {
public ListNode removeElements(ListNode head, int val) {
    if (head == null) {
        return head;
    }

    ListNode dummy = new ListNode(0);
    dummy.next = head;
    ListNode p = dummy;
    while (p.next != null) {
        if (p.next.val == val) {
            p.next = p.next.next;
        } else {
            p = p.next;
        }
    }

    return dummy.next;
}
}
