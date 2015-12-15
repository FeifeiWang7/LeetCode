#include <stdio.h>
#include <stdbool.h>
struct ListNode {
      int val;
      struct ListNode *next;
};
bool isPalindrome(struct ListNode* head) 
{
        int len = 0;
        struct ListNode *tmp = head;
        while(tmp != NULL) 
        {
                len++;
                tmp = tmp->next;
        }
        int half = len/2;

        struct ListNode *result = head;
        if(head == NULL) return true;
        head = head->next;
	result->next = NULL; //added avoid cycle??? Otherwise time limit exceeded.
        while(--half)
        {
                tmp = head;
                head = tmp->next;
                tmp -> next = result;
                result = tmp;
        }  
        if(len%2 == 1) head = head -> next;

        while((result != NULL) && (head != NULL))
        {
                if(result->val != head -> val) return false;
                result = result->next;
                head = head->next;
        }
        return true;
}
int main()
{
	struct ListNode ListNode1;
	struct ListNode ListNode2;
	struct ListNode ListNode3;
	struct ListNode ListNode4;
	ListNode1.val = 1;	
	ListNode1.next = &ListNode2;
	ListNode2.val = 2;	
	ListNode2.next = &ListNode3;
	ListNode3.val = 3;	
	ListNode3.next = &ListNode4;
	ListNode4.val = 1;	
	ListNode4.next = NULL;
	printf("%d\n", isPalindrome(&ListNode1));
	return 0;
}
