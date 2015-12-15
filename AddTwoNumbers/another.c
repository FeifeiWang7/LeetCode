int cal(int a, int b, int *carry)
 {
     int sum = a+b+*carry;
     *carry = sum/10;
     return sum%10;
 }

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode* head = l1;
    struct ListNode* pre = l1;
    if (l1 == NULL){
        return l2;
    }
    else if (l2 == NULL){
        return l1;
    }
    l1->val = cal(l1->val,l2->val,&carry);
    l1 = l1->next;
    l2 = l2->next;
    while (l1 && l2){ 
            pre->next->val = cal(l1->val,l2->val,&carry);
            pre = pre->next;
            l1 = l1->next;
            l2 = l2->next;
    }
    if (l2){ //if l2 is longer.
        pre->next = l2;
    }
    while (carry){
        if (pre->next){
            pre->next->val = cal(pre->next->val,0,&carry);
            pre = pre->next;
        }
        else{
            pre->next = malloc(sizeof(struct ListNode));
            pre->next->val = cal(0,0,&carry);
            pre->next->next = NULL;
        }
     }
    return head;
}
////

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *newList() { // construct and initialize a list
        struct ListNode *list = malloc(sizeof(struct ListNode));
        list->val = list->next = 0;
        return list;}
    int add1 = 0;
    struct ListNode *ret = newList();
    struct ListNode *current = ret;
    while(l1 || l2 || add1) {
        struct ListNode *l = newList();
        if(l1) {l->val += l1->val; l1 = l1->next;}
        if(l2) {l->val += l2->val; l2 = l2->next;}
        l->val += add1 ? (add1--) : 0; // set add1 to 0
        l->val -= (l->val >= 10) ? (10+add1++) : 0; // set add1 to 1 if l->val >= 10
        current = current->next = l;}
    return ret->next;}
