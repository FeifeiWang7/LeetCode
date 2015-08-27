/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
	struct ListNode *p, *q;
	p = head;
	while(p != NULL)
	{
		q = p;
		while((q->next != NULL) && (p->val == q->val)) 
			q = q ->next;
		if(p->val < q->val) p -> next = q;
		else if(q -> next == NULL) 
		{
			p -> next = NULL;
		}
		p = p -> next;
	}
	return head;
}
