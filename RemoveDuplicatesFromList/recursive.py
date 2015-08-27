class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head):
        if head and head.next and head.val != head.next.val:
            head.next = self.deleteDuplicates(head.next)
        elif head and head.next:
            head = self.deleteDuplicates(head.next)
        return head
