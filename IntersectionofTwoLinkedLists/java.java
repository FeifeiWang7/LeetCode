public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    if (headA == null || headB == null) {
        return null;
    }
    int length1 = 0, length2 = 0, diff = 0;
    ListNode list1 = headA, list2 = headB;
    while (list1 != null) {
        length1++;
        list1 = list1.next;
    }
    while (list2 != null) {
        length2++;
        list2 = list2.next;
    }
    list1 = headA;
    list2 = headB;
    diff = length1 - length2;
    if (length2 > length1) {
        list1 = headB;
        list2 = headA;
        diff = length2 - length1;
    }
    for (int i = 0; i < diff; i++) {
        list1 = list1.next;
    }
    while (list1 != null && list2 != null) {
        if (list1.val == list2.val) {
            return list1;
        }
        list1 = list1.next;
        list2 = list2.next;
    }
    return null;
}

////

public class Solution {

  public ListNode getIntersectionNode(ListNode l1, ListNode l2) {
    if (l1 == null || l2 == null) return null;

    // step 1. count the two lists
    int n1 = count(l1), n2 = count(l2);

    // step 2. move the longer one |n1 - n2| steps
    int n = Math.abs(n1 - n2);

    while (n-- > 0) {
      if (n1 > n2)
        l1 = l1.next;
      else
        l2 = l2.next;
    }

    // step 3. move together and find the meeting point
    while (l1 != l2) {
      l1 = l1.next;
      l2 = l2.next;
    }

    return l1;
  }

  int count(ListNode l) {
    int n = 0;
    while (l != null) {
      n++;
      l = l.next;
    }
    return n;
  }

}
////
public class Solution {

public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

    if(headA == null || headB == null){
        return null;
    }

    int lenA = 0;
    int lenB = 0;
    ListNode lenforA = headA;
    ListNode lenforB = headB;

    while(lenforA != null){
        lenforA = lenforA.next;
        lenA++;
    }
    while(lenforB != null){
        lenforB = lenforB.next;
        lenB++;
    }

    if(lenA > lenB){
        int move1 = lenA - lenB;
        while(move1 != 0){
            headA = headA.next;
            move1--;
        }
    }

    if(lenA < lenB){
        int move2 = lenB - lenA;
        while(move2 != 0){
            headB = headB.next;
            move2--;
        }
    }

    while(headA != null && headB != null){
        if(headA == headB){
            return headA;
        }
        headA = headA.next;
        headB = headB.next;
    }

    return null;
}
}

###
If two linked lists have intersection, we can find two observations:

They must have same tail from the intersection point.
L1+L2 must have same tail from the intersection point as L2 + L1. For example,
 L1 = 1,2,3 
 L2 = 6,5,2,3
L1+L2 = 1,2,3,6,5,2,3
L2+L1 = 6,5,2,3,1,2,3
To implement L1+L2 as well as L2+L1, we can simply jump to another list's head after traveling through certain list!

But, you need to notice that if the two lists have no intersection at all, you should stop after checking L1+L2, so we need a flag to ensure it!

Followings are my code!

def getIntersectionNode(self, headA, headB):
    if not headA or not headB:
        return None
    ptA, ptB, jumpA = headA, headB, False
    while True:
        if id(ptA) == id(ptB):
            return ptA
        ptA, ptB = ptA.next, ptB.next
        if not ptA:
            if not jumpA:
                jumpA = True
                ptA = headB
            else:
                return None
        if not ptB:
            ptB = headA
#####
class Solution:
    # @param two ListNodes
    # @return the intersected ListNode
    def getIntersectionNode(self, headA, headB):
        if headA is None or headB is None:
            return None

        pa = headA # 2 pointers
        pb = headB

        while pa is not pb:
            # if either pointer hits the end, switch head and continue the second traversal, 
            # if not hit the end, just move on to next
            pa = headB if pa is None else pa.next
            pb = headA if pb is None else pb.next

        return pa # only 2 ways to get out of the loop, they meet or the both hit the end=None

# the idea is if you switch head, the possible difference between length would be countered. 
# On the second traversal, they either hit or miss. 
# if they meet, pa or pb would be the node we are looking for, 
# if they didn't meet, they will hit the end at the same iteration, pa == pb == None, return either one of them is the same,None
