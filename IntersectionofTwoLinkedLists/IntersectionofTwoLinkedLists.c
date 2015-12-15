/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
	if((headA== NULL) || (headB == NULL)) return NULL;
	int lenA= 0, lenB= 0;
	struct ListNode *pa = headA, *pb = headB;
	while(pa->next != NULL)
	{
		pa = pa->next;
		lenA ++;
	}
	while(pb->next != NULL)
	{
		pb = pb->next;
		lenB ++;
	}
	int i;
	pa = headA, pb = headB;
	for(i = 0; i < lenA-lenB; i++) pa = pa->next;
	for(i = 0; i < lenB-lenA; i++) pb = pb->next;

	while(1)
	{
		if(pa == pb) return pa;
		pa = pa->next;	
		pb = pb->next;
	}
}
