class Solution {
public:
ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* retHead = head;
    ListNode* first = head->next;
    while (first != NULL) {
        if (first->val != head->val) {
            head = head->next;
            head->val = first->val;
        }
        first = first->next;
    }

    // release nodes to avoid memory leak
    first = head->next;
    ListNode* delNode;
    while (first != NULL) {
        delNode = first;
        first = first->next;
        delete delNode;
    }

    head->next = NULL;

    return retHead;
}
};
