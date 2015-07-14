#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
	struct ListNode *p, *tmp , *p1 = l1, *p2 = l2;
	p = (struct ListNode *)malloc(sizeof(struct ListNode));
	tmp = p;
		while((p1 != NULL) && (p2 != NULL))
		{
			if(p1->val < p2->val)
			{
				tmp -> next = p1;
				tmp = tmp -> next;
				p1 = p1->next;
			}
			else
			{
				tmp -> next = p2;
				tmp = tmp -> next;
				p2 = p2 -> next;
			}
		}
		if(p1 == NULL) tmp -> next = p2;
		else tmp -> next = p1;
	return p->next;
}

int main()
{
	struct ListNode *l1, *l2, *p;
	l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	l1 -> val = 1;
	l2 -> val = 2;
	l1 -> next = NULL;	
	l2 -> next = NULL;	
	p = mergeTwoLists(l1, l2);
	while(p != NULL) 
	{
		printf("%d\n", p->val);
		p = p -> next;
	}
}
