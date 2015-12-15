////
Scan both lists
For each list once it reaches the end, continue scanning the other list
Once the two runner equal to each other, return the position
Time O(n+m), space O(1)

public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if( null==headA || null==headB )
            return null;

        ListNode curA = headA, curB = headB;
        while( curA!=curB){
            curA = curA==null?headB:curA.next;
            curB = curB==null?headA:curB.next;
        }
        return curA;
    }
///
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    int len1 = 0;
    int len2 = 0;

    if(!headA || !headB) return NULL;

    struct ListNode *p1 = headA;
    struct ListNode *p2 = headB;

    for(; headA; len1++, headA = headA->next);
    for(; headB; len2++, headB = headB->next);

    if(len1 > len2)
        for(int i=0; i<len1-len2; i++, p1 = p1->next);
    else
        for(int j=0; j<len2-len1; j++, p2 = p2->next);

    for(; p1&&p2; p1=p1->next, p2=p2->next)
        if( p1 == p2 ) return p1;

    return NULL;
}
/////
#define NEXT(x) (x=x->next)
typedef struct ListNode ln;

ln* getIntersectionNode(ln *headA, ln *headB)
{
  /* if(!headA || !headB) return NULL; */

  /* first get the lengths of the two lists */
  int lenA = 0, lenB =0;
  for(ln* pA = headA; pA; NEXT(pA)) lenA++;
  for(ln* pB = headB; pB; NEXT(pB)) lenB++;

  /* move the longer one forward to match two lists at the start-line */
  for(int i = 0; i<(lenA-lenB); i++) NEXT(headA);
  for(int i = 0; i<(lenB-lenA); i++) NEXT(headB);

  /* move simultaneously and check the first meeting point */
  while(headA!=headB)
  {
    NEXT(headA);
    NEXT(headB);
  }

  return headA; /* NULL or the intersection */
}
