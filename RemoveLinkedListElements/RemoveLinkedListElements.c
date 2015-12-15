/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) 
{
	if(head == NULL) return head;
	while((head->val == val)&&(head->next!=NULL)) head = head->next;
	struct ListNode *p = head;
	while(p->next != NULL)
	{
		if(p->next->val == val)
		{
			p->next = p->next->next;
		}
		else p = p->next;	
	}    
	return head;
}
