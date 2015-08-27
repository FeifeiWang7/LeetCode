return h && (h->next = deleteDuplicates(h->next)) && h->next->val == h->val ? h->next : h;
Update after shawnyi's comment:

While the above does remove the duplicates from the list, it doesn't delete the nodes from memory, causing memory leaks. Here's a version which takes care of that.

if (h && (h->next = deleteDuplicates(h->next)) && h->next->val == h->val) delete h, h = h->next; return h;
