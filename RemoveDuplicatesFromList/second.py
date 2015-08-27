class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head):
        node = head
        while node:
            while node.next and node.next.val == node.val:
                node.next = node.next.next

            node = node.next

        return head
