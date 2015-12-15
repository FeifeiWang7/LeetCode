void deleteNode(struct ListNode* node) 
{
	ListNode *tmp = node -> next;
	node->next = tmp->next;
	node->val = tmp->val;    
	free(tmp);
}
