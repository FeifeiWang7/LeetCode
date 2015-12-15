/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// assume head has value
struct ListNode* reverseList(struct ListNode* head) 
{
	struct ListNode *result, *tmp;

	result = (struct ListNode *)malloc(sizeof(struct ListNode));
	result->next = NULL;
	while((head->next!=NULL) && (head->next->next != NULL))
	{
		tmp = head->next;
		head = tmp->next;
		tmp->next = result->next;
		result->next = tmp;	
	}
	if((head->next!=NULL) && (head->next->next == NULL))
	{	
		head->next->next = result -> next;
		result->next = head->next;
	}
	else if(head->next == NULL) result->next == NULL;
	head = result;
	free(result);
	return head;
}
