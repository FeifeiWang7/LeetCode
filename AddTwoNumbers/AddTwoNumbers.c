struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
	struct ListNode *p = l1, *q = l2; 
	int remain = 0, value;
	while((p!=NULL)&&(q!=NULL))
	{
		value = q->val + p -> val + remain;
		p->val = value%10;
		remain = value/10;
		if(p->next!=NULL && q->next!=NULL)
		{
			p = p->next;
			q = q->next;
		}
		else break;
	}
	if(p->next==NULL && q->next == NULL) ;
	else if(q->next == NULL)
	{
		p = p->next;
		while(p != NULL)
		{
			value = p->val + remain;
			p->val = value%10;
			remain = value/10;
			if(p->next != NULL) p = p -> next;
			else break;
		}
	}
	else if(p->next == NULL)
	{
		q = q->next;
		while(q != NULL)
		{
			p -> next = (struct ListNode *)malloc(sizeof(struct ListNode));
			p = p->next;
			value = q->val + remain;
			p -> val = value % 10;
			remain = value /10;
			p->next = NULL;
			q=q->next;
		}
	}
	if(remain)
	{
		p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
		p->next->val = remain;
		p -> next->next = NULL;
	}
	return l1;	
}
