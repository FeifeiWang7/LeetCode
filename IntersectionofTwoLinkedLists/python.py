This fast solution aligns the two linked list at their ends, and compares node references starting from the nth node from the last, n being the length of the shorter list. Any comments are greatly appreciated.

class Solution(object):
        def getIntersectionNode(self, headA, headB):
            if not headA or not headB:
                return None
            a = self.countLen(headA)
            b = self.countLen(headB)
            if a < b:
                a,b = b,a
                headA,headB = headB,headA
            while a > b:
                headA = headA.next
                a -= 1
            while headA:
                if headA == headB:
                    return headA
                headA = headA.next
                headB = headB.next
            return None

        def countLen(self, head):
            n = 0
            while head:
                head = head.next
                n += 1
            return n

###
O(m+n) time, O(1) space but need to temporarily modify the structure.

a1 ->->-> c1 ->->-> c3
          ↑
          |
   b1 ->->
Method description:

Find the length of (a1->c3), countA, and get the tail
Find the length of (b1->c3), countB, get the tail c3, and reverse the whole (b1->c3) link to (c3->b1)
Find the length of (a1->b1), countX
Reverse (c3->b1) back to (b1->c3)
If the first two tails are not equal, return None
Proceed from a1 by (countA - (countA+countB-countX+1)/2) nodes, and return that
It tries to count the length of the branches.

436ms in Python which is among the top 3%

class Solution:
    # Count the nodes and return the tail and the length
    # return (tail, len)
    def countNodes(self, head):
        count = 1
        while head.next is not None:
            count += 1
            head = head.next
        return (head, count)

    # Count the nodes, reverse the whole link, and return the original tail and the length
    # return (tail, len)
    def reverseNodes(self, head):
        count = 1
        prev = head
        now = prev.next
        prev.next = None
        while now is not None:
            count += 1
            temp = now.next
            now.next = prev
            prev = now
            now = temp
        return (prev, count)


    # @param two ListNodes
    # @return the intersected ListNode
    def getIntersectionNode(self, headA, headB):
        if headA is None or headB is None:
            return None
        tailA, countA = self.countNodes(headA)
        tailB, countB = self.reverseNodes(headB)
        _, countX = self.countNodes(headA)
        self.reverseNodes(tailB)
	if tailA is not tailB:
            return None
        for _ in range(countA - (countA+countB-countX+1)/2):
            headA = headA.next
        return headA

####
I assume from intersection node to the end is same, which mean after they intersecting, they won't divide. So I only need to check after they have the same length and return the first node is same.

class Solution:
# @param two ListNodes
# @return the intersected ListNode
def getIntersectionNode(self, headA, headB):
    sizeA = 0
    sizeB = 0
    p1 = headA
    p2 = headB
    while p1:
        p1 = p1.next
        sizeA += 1
    while p2:
        p2 = p2.next
        sizeB += 1

    while sizeA != sizeB:
        if sizeA > sizeB:
            headA = headA.next
            sizeA -= 1
        elif sizeB > sizeA:
            headB = headB.next
            sizeB -= 1

    while headA and headB:
        if headA==headB:
            return headA
        headA = headA.next
        headB = headB.next

    return None
