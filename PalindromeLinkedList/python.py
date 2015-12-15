class Solution(object):
    def isPalindrome(self, head):
        dummy = first = second = ListNode(None)
        dummy.next = head
        while second and second.next:
            first, second = first.next, second.next.next

        first.next, second = None, first.next
        while second:
            second.next, first.next, second = first.next, second, second.next

        second, first = first.next, dummy.next
        while first and second:
            if first.val != second.val: return False
            first, second = first.next, second.next
        return True
###
O(n) time, O(1) space. The second solution restores the list after changing it.

Solution 1: Reversed first half == Second half?

Phase 1: Reverse the first half while finding the middle.
Phase 2: Compare the reversed first half with the second half.

def isPalindrome(self, head):
    rev = None
    slow = fast = head
    while fast and fast.next:
        fast = fast.next.next
        rev, rev.next, slow = slow, rev, slow.next
    if fast:
        slow = slow.next
    while rev and rev.val == slow.val:
        slow = slow.next
        rev = rev.next
    return not rev
Solution 2: Play Nice

Same as the above, but while comparing the two halves, restore the list to its original state by reversing the first half back. Not that the OJ or anyone else cares.

def isPalindrome(self, head):
    rev = None
    fast = head
    while fast and fast.next:
        fast = fast.next.next
        rev, rev.next, head = head, rev, head.next
    tail = head.next if fast else head
    isPali = True
    while rev:
        isPali = isPali and rev.val == tail.val
        head, head.next, rev = rev, head, rev.next
        tail = tail.next
    return isPali
###
I just realized that the O(1) space is only a follow-up, so here's the obvious one without that.

def isPalindrome(self, head):
    vals = []
    while head:
        vals += head.val,
        head = head.next
    return vals == vals[::-1]
###
def isPalindrome(self, head):
    count = 0
    node = head
    while node:
        node = node.next
        count += 1
    node = head
    pre = None
    for i in range(count // 2):
        temp = node.next
        node.next = pre
        pre = node
        node = temp
    if count % 2 == 0:
        h2 = node
    else:
        h2 = node.next
    h1 = pre
    while h1:
        if h1.val == h2.val:
            h1 = h1.next
            h2 = h2.next
        else:
            return False
    return True

###
I have the same idea as yours but I reverse the second half. I think it is ok but you did change the structure of the linked list after checking whether it is palindrome. You can just check the linked list and not change it! here is my code.
def reverseLinkedList(self, head, tail):
    if head is None or tail is None: return head 
    if head is tail: return head
    p1, p2 = head, head.next
    while p2 is not tail:
        tmp = p2.next
        p2.next = p1
        p1 = p2
        p2 = tmp
    tail.next = p1
    head.next = None
    return tail 

# @param {ListNode} head
# @return {boolean}
def isPalindrome(self, head):

    if head is None or head.next is None: return True

    p1, p2, even = head, head, False
    while p2.next:              
        p1 = p1.next
        p2 = p2.next
        if p2.next: p2 = p2.next 
        else: even = True

    if head.val != p2.val: return False

    halfMark = p1
    if even: halfTail = p1
    else: halfTail = p1.next
    lastHalf = self.reverseLinkedList(halfTail, p2)

    checkPos1, checkPos2, result = head, lastHalf, True
    while result and checkPos1 is not halfMark: 
        if checkPos1.val != checkPos2.val:
            result = False
        checkPos1 = checkPos1.next 
        checkPos2 = checkPos2.next

    self.reverseLinkedList(lastHalf, halfTail)

    return result
###
class Solution:
# @param {ListNode} head
# @return {boolean}
def isPalindrome(self, head):
    node = head
    length = 0
    comp = []
    while node:
        comp.append(node.val)
        node = node.next
        length += 1

    for i in range(length // 2):
        if not comp[i] == comp[len(comp)-i-1]:
            return False

    return True
