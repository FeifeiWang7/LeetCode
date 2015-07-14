/*
struct ListNode 
{
	int val;
	struct ListNode *next;
};*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
	struct ListNode *curr = head , *p = head;
	while(n>0)
	{
		p = p -> next;
		if(p == NULL) return head->next; //which means we have to delete the first node
		n--;
	}
	while(p -> next != NULL)
	{
		p = p -> next;
		curr = curr -> next;
	}
	curr -> next = curr->next->next;	
	return head;
}


