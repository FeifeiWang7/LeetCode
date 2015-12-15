def reverseList(self, head):
    prev = None
    curr = head

    while curr:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next

    return prev
###
def reverseList(self, head):
    pre, cur = None, head
    while cur:
        cur.next, pre, cur = pre, cur, cur.next
    return pre
########
Method 1: uses self as a dummy node for swapping

def reverseList(self, head):
    pre, pre.next, tail = self, head, head
    while tail and tail.next:
        pre.next, pre.next.next, tail.next = \
                  tail.next, pre.next, tail.next.next
    return self.next
Method 2: swapping using two variable, pre and cur

def reverseList(self, head):
    pre, cur = None, head
    while cur:
        cur.next, pre, cur = pre, cur, cur.next
    return pre
Method 3: Recursive method by storing previous node in the function argument.

def reverseList(self, head, pre = None):
    if not head: return pre
    cur, head.next = head.next, pre
    return self.reverseList(cur, head)

#####
Hi everyone, can someone explain to me why the first method doesn't work while the 2nd method works? Thanks much

def reverseList(self, head):
    reverse = None
    while(head):
        temp = head
        temp.next = reverse
        reverse = temp
        head = head.next
    return reverse


def reverseList(self, head):
    reverse = None
    while(head):
        temp = head
        head = head.next
        temp.next = reverse
        reverse = temp
    return reverse
###
class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def reverseList(self, head):
        if head is None:
            return None
        if head.next is None: # last one
            return head
        # not the last one
        nextNode = head.next
        new_head = self.reverseList(nextNode)
        head.next = None
        nextNode.next = head
        return new_head
