class Solution {
public:
void deleteNode(ListNode* node) {
    if(node == NULL) return;
    ListNode *tmp = node->next;
    node->val = tmp->val;
    node->next = tmp->next;
    delete tmp;
}
};
///
class Solution {
public:
void deleteNode(ListNode* node) {  //node是要删除的节点
    if(node==NULL)
        delete node;
    if(node->next!=NULL){
        node->val=node->next->val;
        ListNode* tmp=node->next;
        node->next=node->next->next;
        delete tmp;
    }
}
};
//
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *(node->next);
    }
};
if the node should be freed, we need 3 lines:

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        *node = *temp;
        delete temp;
    }
};
///
class Solution {
public:
    void deleteNode(ListNode* node) {
        std::swap(node->val, node->next->val);
        auto next = node->next;
        node->next = node->next->next;
        delete next;
    }
};
