bool isPalindrome(ListNode* head) {
    long long  hash=0,reversehash=0;
    long long prime = 101LL, mod = 1e9+7,power=1;
    ListNode * cur = head;
    while(cur!=NULL)
    {
        hash = (hash + (cur->val*power)%mod)%mod;
        power = (power*prime)%mod;
        reversehash = (reversehash*prime)%mod+cur->val;
        cur = cur->next;
    }
    return hash==reversehash;
}
If Hash of string and its reverse string is equal then string is 'most probably' a palindrome
////////
public boolean isPalindrome(ListNode head) {
    if (head == null || head.next == null)
        return true;
    ListNode fast = head, slow = head, prev = null;
    while (fast != null && fast.next != null) {
        prev = slow;
        slow = slow.next;
        fast = fast.next.next;
    }
    prev.next = null;
    slow = reverse(slow);
    while (head != null && slow != null) {
        if (head.val != slow.val)
            return false;
        head = head.next;
        slow = slow.next;
    }
    return true;
}

private ListNode reverse(ListNode head) {
    ListNode prev = null, cur = head;
    while (cur != null) {
        ListNode next = cur.next;
        cur.next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
///
public class Solution {

public boolean isPalindrome(ListNode head) {

    if (head == null) return true;
       if(head.next == null) return true;

       ListNode dummy,pre,cur,next,fast;
       dummy = new ListNode(Integer.MAX_VALUE);
       dummy.next = head;
       int i = 1;
       pre = dummy; 
       fast = dummy;
       //find the middle 
       while(fast!= null){
           fast = fast.next;
           if(i%2 == 0){
            pre = pre.next;
           }
           i++;
       }

       cur = pre.next;
       fast = pre;
       //reverse the second half
       while(cur != null){
           next = cur.next;
           cur.next = pre;
           pre = cur;
           cur = next;
       }
       fast.next = null;
       fast = head;
       //compare the first half and the reversed second half
       while(fast != null && pre!= null)
       {

           if(fast.val != pre.val)
           return false;;

           fast = fast.next;
           pre = pre.next;
       }

       //i do not restore the input :(

       return true;
}
/////
The basic idea is to use two reverse the second half list and compare one by one from head.

I cant think of any other O(1) space O(n) time idea. This solution beats 85%.

public boolean isPalindrome(ListNode head) {

    if (head == null)
        return true;


    // Use two pointers to locate the half point
    ListNode slow = head;
    ListNode fast = head;

    while (fast.next != null && fast.next.next != null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    if (slow.next == null)
        return true;

   //Reverse list from after slow pointer
    ListNode head2 = slow.next;
    ListNode current = head2.next;
    slow.next = null;
    head2.next = null;

    while (current != null) {
        ListNode next = current.next;
        current.next = head2;
        head2 = current;
        current = next;
    }

    //Check from head using reversed half and original half
    while (head != null && head2 != null) {
        if (head.val != head2.val)
            return false;
        head = head.next;
        head2 = head2.next;
    }

    return true;

}
/////
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if(!head || !head->next) return true;

        // Determine the size of the list
        int listSize = 0;
        for(ListNode * tmp = head; tmp != NULL; tmp = tmp->next)
            listSize++;

        int nbShift = listSize / 2;
        if(listSize % 2)
            nbShift++;

        ListNode * secondHead = head;
        for(int i = 0; i < nbShift; i++)
            secondHead = secondHead->next;

        secondHead = reverseLinkedList(secondHead);

        for(int i = 0; i < listSize - nbShift; i++)
        {
            if(head->val != secondHead->val)
                return false;
            else
            {
                head = head->next;
                secondHead = secondHead->next;
            }
        }

        return true;
    }

    ListNode *  reverseLinkedList(ListNode* head)
    {
        if(!head || !head->next) head;

        ListNode * tmp = NULL;
        ListNode * prevNode = head;
        ListNode * currNode = head->next;
        head->next = NULL;

        while(currNode)
        {
            tmp = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode  = tmp;
        }

        return prevNode;
    }
};
/////
I came up with this very basic approach, pretty similar with checking palindrome number. It is just my first try and it works.

Please tell me where I could improve the code and is this the solution that costs O(n) time and O(1) space?

Explanations:

Find the middle of the list and break the list into two pieces
Reverse the second half of the list
Check if very node is the same in same position of each list.
Since the number of nodes might be odd or even, so the last "if" checks are meant to deal with two different situations.
public boolean isPalindrome(ListNode head) {
    if(head==null) {
        return true;
    }
    ListNode l1 = head;
    ListNode nodeBeforeMid = findMid(head);
    ListNode l2 = nodeBeforeMid.next;
    nodeBeforeMid.next = null;
    l2 = reverseList(l2);
    while(l1!=null && l2!=null && l1.val==l2.val) {
        l1 = l1.next;
        l2 = l2.next;
    }
    if(l1==null && l2==null) {
        return true;
    }
    else if(l1==null && l2!=null) {
        return true;
    }
    return false;
}

public ListNode findMid(ListNode head) {
    ListNode slow = new ListNode(0);
    slow.next = head;
    ListNode fast = new ListNode(0);
    fast.next = head;
    while(fast.next!=null && fast.next.next!=null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    return slow;
}

public ListNode reverseList(ListNode head) {
    ListNode nHead = null;
    while(head!=null) {
        ListNode temp = head.next;
        head.next = nHead;
        nHead = head;
        head = temp;
    }
    return nHead;
}
///
Even though this solution could use O(n) runtime and O(1) space, but it would permanently change the original LinkedList after running this function (which is not a good idea), since Java is object passing by reference. Not sure if there is any other idea could fix this problem and also use O(1) memory space.

public class Solution {

    public boolean isPalindrome(ListNode head) {

    if(head == null || head.next == null)
        return true;

    ListNode slow = head;
    ListNode fast = head.next;

    /* slow run into the middle
     * fast run into the end of list */
     while(fast!=null && fast.next!=null){
         slow = slow.next;
         fast = fast.next.next;
     }

     ListNode preOne = slow;
     ListNode temp = slow.next;
     ListNode aheadOne = temp;
     slow.next = null;

     /* reverse the second half pointer direction of list */
     while(temp != null){
         aheadOne = temp.next;
         temp.next = preOne;
         preOne = temp;
         temp = aheadOne;
     }

     ListNode left = head;
     ListNode right = preOne;
     while(left != null){
         if(left.val != right.val)
            return false;
         left = left.next;
         right = right.next;
     }

     return true;
}
}

///
I have explained my approach fully in the comments and have named variables in quite a reader-friendly way as well. Hope this benefits someone.

public boolean isPalindrome(ListNode head) {
    // Trivial case
    if(head == null || head.next == null) { return true;}

    ListNode start = new ListNode(0);
    start.next = head;
    ListNode firstHalfStart = head;
    ListNode secondHalfStart = head;
    ListNode fast = head;

    // Traverse to mid node and Reverse the First half of the LinkedList in the same run
    while(fast.next != null && fast.next.next != null) {
        fast = fast.next.next;

        start.next = secondHalfStart.next;
        secondHalfStart.next = secondHalfStart.next.next;
        start.next.next = firstHalfStart;

        firstHalfStart = start.next;
    }

    // Offset for odd number of elements
    // As the mid node is common to both halves, this should be skipped
    if(fast.next == null) {
        firstHalfStart = firstHalfStart.next;
    }

    // At the end of the previous loop, SecondHalfStart pointer is still stuck on the end of the first half
    // Shift it by one to take it to the start of the SecondHalf
    secondHalfStart = secondHalfStart.next;

    while(secondHalfStart != null) {
        if(firstHalfStart.val != secondHalfStart.val) { return false;}
        secondHalfStart = secondHalfStart.next;
        firstHalfStart = firstHalfStart.next;
    }
    return true;
}
///
public class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null) {
            return true;
        }
        ListNode cur = head;
        int n = 1;
        while (cur.next != null) {
            n++;
            cur = cur.next;
        }
        ListNode pre = null;
        ListNode nex = null;
        cur = head;
        for (int i = 0; i < n / 2; ++i) {
            nex = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nex;
        }
        if (n % 2 == 1) {
            cur = cur.next;
        }
        while (cur != null) {
            if (cur.val != pre.val) {
                return false;
            }
            cur = cur.next;
            pre = pre.next;
        }
        return true;        
    }
}
/////
public class Solution {
    boolean palindrome=true;
    public boolean isPalindrome(ListNode head) {
        readback(head,head);
        return palindrome;
    }
    ListNode readback(ListNode back, ListNode forward){
        if(back==null)
            return forward;
        ListNode next=readback(back.next, forward);
        if(back.val!=next.val)
            palindrome=false;
        return next.next;
    }
}
/////
public class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode curp = head,curq = head;
        int length =0,i;
        while(curp!=null){
            length++;
            curp = curp.next;
        }
        if(length%2==1){
            length = (length-1)/2;
        }else {
            length = length/2;
        }
        i = length;
        while(i-->0){
            curq = curq.next;
        }
        curq = reverseList(curq);
        curp = head;
        while(length-->0){
            if(curq.val!=curp.val){
                return false;
            }
            curp = curp.next;
            curq = curq.next;
        }
        return true;
    }
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
}
///
public class Solution {
    public boolean isPalindrome(ListNode head) {
        Stack<ListNode> st = new Stack<ListNode>();

        ListNode temp = head;

        while(temp != null){
            st.push(temp);
            temp = temp.next;
        }

        while(!st.empty()){
            if(st.pop().val != head.val){
                return false;
            }
            head = head.next;
        }
        return true;
    }
}
/////
Sorry, Since it's a recursive algorithm, it uses O(N) space. Thanks for pointing out this.

public class Solution {
public ListNode root;
public boolean isPalindrome(ListNode head) {
    root = head;
    return (head == null) ? true : _isPalindrome(head);
}

public boolean _isPalindrome(ListNode head) {
    boolean flag = true;
    if (head.next != null) {
        flag = _isPalindrome(head.next);
    }
    if (flag && root.val == head.val) {
        root = root.next;
        return true;
    }
    return false;
}
}
/////
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isPalindrome(ListNode head) {

        if(head==null || head.next==null){
            return true;
        }

        ListNode mid = findMiddle(head);
        ListNode midhead = mid.next;

        ListNode reverseHead = reverse(midhead);

        while(reverseHead!=null){
            if(head.val==reverseHead.val){
                head = head.next;
                reverseHead = reverseHead.next;
            }else{
                return false;
            }
        }

        return true;
    }

    public ListNode findMiddle(ListNode head1){
        ListNode fast = head1.next;
        ListNode slow = head1;
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public ListNode reverse(ListNode head2){
        ListNode pre = null;
        while(head2!=null){
            ListNode tmp = head2.next;
            head2.next = pre;
            pre = head2;
            head2 = tmp;
        }
        return pre;
    }
}
///
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode node = head;
        int count = 0;
        while(node != null){
            count++;
            node = node.next;
        }
        node = head;
        if(count == 0 || count == 1)
            return true;

        //reverse half
        ListNode nextNode = node.next;
        for(int i=0;i<count/2-1;i++){
            ListNode temp = nextNode.next;
            nextNode.next = node;
            node = nextNode;
            nextNode = temp;
        }
        head.next = null;
        ListNode secNode = (count % 2 == 0)? nextNode:nextNode.next;
        while(node != null){
            if(node.val != secNode.val)
                return false;
            node = node.next;
            secNode = secNode.next;
        }
        return true;
    }
}
///public class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null) {
            return true;
        }
        ListNode p1 = head;
        ListNode p2 = head;
        ListNode p3 = p1.next;
        ListNode pre = p1;
        //find mid pointer, and reverse head half part
        while(p2.next != null && p2.next.next != null) {
            p2 = p2.next.next;
            pre = p1;
            p1 = p3;
            p3 = p3.next;
            p1.next = pre;
        }

        //odd number of elements, need left move p1 one step
        if(p2.next == null) {
            p1 = p1.next;
        }
        else {   //even number of elements, do nothing

        }
        //compare from mid to head/tail
        while(p3 != null) {
            if(p1.val != p3.val) {
                return false;
            }
            p1 = p1.next;
            p3 = p3.next;
        }
        return true;

    }
}
///
public class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head==null||head.next==null)return true;
        ListNode walker = head;
        ListNode pre = walker;
        ListNode runner = head;
        while(runner.next!=null && runner.next.next !=null){
            pre = walker;
            walker = walker.next;
            runner = runner.next.next;
        }
        ListNode head2 = walker.next;
        if(runner.next==null) pre.next=null;
        else walker.next = null;
        ListNode head1 = reverse(head);
        while(head1!=null){
            if(head1.val!=head2.val)return false;
            head1=head1.next;
            head2=head2.next;
        }
        return true;
    }
    public ListNode reverse(ListNode head){
        if(head==null||head.next==null)return head;
        ListNode prev = head;
        ListNode curr = head.next;
        ListNode next = curr.next;
        curr.next = prev;
        prev.next = null;
        prev = curr;
        curr = next;
        if(curr==null)return prev;
        while(curr!=null){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}
///
public class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head==null || head.next==null) return true;
        ListNode slow = head;
        ListNode fast = head;
        while(fast.next!=null && fast.next.next!=null){
            fast = fast.next.next;
            slow = slow.next;
        }
        ListNode next = slow.next.next;
        ListNode tail = slow.next;

        //Invert half list   
        while(next!=null){
            ListNode temp = slow.next;
            slow.next = next;
            tail.next = next.next;
            next.next = temp;
            next = tail.next;
        }

        while(slow.next!=null){
            if(head.val != slow.next.val){
                return false;
            }
            slow = slow.next;
            head = head.next;
        }
        return true;
    }
}
//
public class Solution {
public boolean isPalindrome(ListNode head) {
    if(head == null)
        return true;
    if(head.next == null)
        return true;
    ListNode fast = head;
    ListNode slow = head;
    while(fast.next != null && fast.next.next != null){
        fast = fast.next.next;
        slow = slow.next;
    }
    ListNode partNode = slow.next;
    slow.next = null;
    ListNode newList = reverse(partNode);
    ListNode pointer = head;
    while(newList != null){
        if(pointer.val != newList.val)
            return false;
        pointer = pointer.next;
        newList = newList.next;
    }
    return true;
}
public ListNode reverse(ListNode head){
    if(head == null)
        return head;
    if(head.next == null)
        return head;
    ListNode node = head.next;
    ListNode point = head;
    head.next = null;
    while(node != null){
        ListNode temp = node.next;
        node.next = point;
        point = node1;
        node = temp;
    }
    return point;
}
}
///
public class Solution {

  public boolean isPalindrome(ListNode head) {
    if (head == null || head.next == null)
      return true;

    // step 1. cut the original list to two halves
    ListNode prev = null, slow = head, fast = head, l1 = head;

    while (fast != null && fast.next != null) {
      prev = slow;
      slow = slow.next;
      fast = fast.next.next;
    }

    prev.next = null;

    // step 2. reverse the 2nd half
    ListNode l2 = (fast == null) ? reverse(slow) : reverse(slow.next);

    // step 3. compare the new two halves
    while (l1 != null && l2 != null) {
      if (l1.val != l2.val)
        return false;

      l1 = l1.next;
      l2 = l2.next;
    }

    return true;
  }

  // helper function: reverse a list
  ListNode reverse(ListNode head) {
    ListNode prev = null, curr = head, next = null;

    while (curr != null) {
      next = curr.next;
      curr.next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
  }

}
///
public class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null) return true;

        // find mid
        ListNode slow = head;
        ListNode fast = head.next;
        while(fast.next != null){
            slow = slow.next;
            fast = fast.next;
            if(fast.next != null) fast = fast.next;
        }

        // reverse second-half
        fast = reverseListNode(slow.next);

        // compare
        slow = head;
        while(fast != null){
            if(fast.val != slow.val) return false;
            fast = fast.next;
            slow = slow.next;
        }
        return true;
    }
    private ListNode reverseListNode(ListNode head){
        if(head == null || head.next == null) return head;
        ListNode next = head.next;
        head.next = null;
        while(next != null){
            ListNode temp = next.next;
            next.next = head;
            head = next;
            if(temp != null) next = temp;
            else return next;
        }
        return next; 
    }    
}
///
public class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null) {
            return true;
        }
        ListNode p1 = head;
        ListNode p2 = head;
        ListNode p3 = p1.next;
        ListNode pre = p1;
        //find mid pointer, and reverse head half part
        while(p2.next != null && p2.next.next != null) {
            p2 = p2.next.next;
            pre = p1;
            p1 = p3;
            p3 = p3.next;
            p1.next = pre;
        }

        //odd number of elements, need left move p1 one step
        if(p2.next == null) {
            p1 = p1.next;
        }
        else {   //even number of elements, do nothing

        }
        //compare from mid to head/tail
        while(p3 != null) {
            if(p1.val != p3.val) {
                return false;
            }
            p1 = p1.next;
            p3 = p3.next;
        }
        return true;

    }
}
//
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null) {
            return true;
        }
        ListNode p1 = head;
        ListNode p2 = head;
        ListNode p3 = p1.next;
        ListNode pre = p1;
        //find mid pointer, and reverse head half part
        while(p2.next != null && p2.next.next != null) {
            p2 = p2.next.next;
            pre = p1;
            p1 = p3;
            p3 = p3.next;
            p1.next = pre;
        }

        //odd number of elements, need left move p1 one step
        if(p2.next == null) {
            p1 = p1.next;
        }
        else {   //even number of elements, do nothing

        }
        //compare from mid to head/tail
        while(p3 != null) {
            if(p1.val != p3.val) {
                return false;
            }
            p1 = p1.next;
            p3 = p3.next;
        }
        return true;

    }
}
///
public boolean isPalindrome(ListNode head) {
    if (head == null) {
        return true;
    }
    ListNode left = null;
    ListNode right = null;
    ListNode slow = head;
    ListNode fast = head;
    ListNode tmp;
    while (fast != null && slow != null) {
        tmp = slow;
        if (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            tmp.next = left;
            left = tmp;
        } else if (fast.next == null) {
            right = slow.next;
            fast = null;
        } else if (fast.next.next == null) {
            right = slow.next;
            tmp.next = left;
            left = tmp;
            fast = null;
        }
    }
    while (left != null && right != null) {
        if (left.val != right.val) {
            return false;
        }
        left = left.next;
        right = right.next;
    }
    return true;
}
//
public class Solution {
public boolean isPalindrome(ListNode head) {
    ListNode fast = head;
    ListNode slow = head;
    ListNode prev = null;
    while(fast!=null&&fast.next!=null){//Using fast-slow pointer to get the middle node
        fast = fast.next.next;
        ListNode temp = slow.next;
        slow.next = prev;//reverse the nodes between head and the middle node
        prev = slow;
        slow = temp;
    }
    if(fast!=null) slow = slow.next;
    fast = prev;
    while(true){
        if(slow==null&&fast==null) return true;
        if(slow==null||fast==null) return false;
        if(slow.val==fast.val){
            slow = slow.next;
            fast = fast.next;
        }else return false;
    }
}
}


