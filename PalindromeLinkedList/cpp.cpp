class Solution {

public:

bool isPalindrome(ListNode* head) {

    if (head == NULL || head->next == NULL) return true;

    int n = 0;
    for (ListNode* node = head; node; node = node->next)
        ++n;

    ListNode* node = head;
    ListNode* prev = head;
    for (int i = 0; i < (n + 1) / 2; ++i) {
        prev = node;
        node = node->next;
    }

    ListNode* tail = NULL;
    while (node) {
        auto temp = node->next;
        node->next = tail;
        tail = node;
        node = temp;
    }

    prev->next = tail;

    while (tail && tail->val == head->val) {
        tail = tail->next;
        head = head->next;
    }

    return tail == NULL;
}
};
/////
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode* slow = head;
    ListNode* fast = head->next;

    //find midlle of the list
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //revert the list
    ListNode* prev = slow;
    ListNode* p = slow->next;
    slow->next = nullptr; 

    while (p)
    {
        ListNode* tmp = p->next;
        p->next = prev;
        prev = p;
        p = tmp;
    }

    //judge is palindrome
    ListNode* l = head;
    ListNode* r = prev;
    while (l && r)
    {
        if (l->val != r->val)
            return false;
        l = l->next;
        r = r->next;
    }

    return true;
}
///
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;

        if(check(head,head)) {
            return true;
        }
        return false;
    }

    ListNode* check(ListNode* head,ListNode* end) {
        ListNode* start;

        if(end->next) {
            start = check(head,end->next); //Go till end node
            if(start == NULL){ //Return null if mismatch found in between
                return NULL;
            }
        } else {
            start = head; //start is head when end is reached
        }
        if(start->val == end->val) {
            if(start->next == NULL) {
                //start reached end, return something non null
                return head;
            }
            return start->next; // next node from start should be compared with next node from end
        } else {
            return NULL; //mismatch found
        }
    }
};
//////
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        int size = 0;
        ListNode *node = head, *mid, *tmp;
        while(node){
            size++; node = node->next;
        }
        node = NULL; mid = head;
        for(int i = 0; i < size/2; i++){
            tmp = mid->next;
            mid->next = node;
            node = mid;
            mid = tmp;
        }
        ListNode *right = mid, *left = node;
        if(size%2) right = right->next;
        while(left && right){
            if(left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
/////
class Solution {
public:
    bool compare(ListNode* head1, ListNode* head2)
    {
        for(;head1!=NULL&&head2!=NULL;head1=head1->next, head2=head2->next)
        {
            if(head1->val!=head2->val)
            {
                return false;
            }
        }
        return true;
    }

    int measure(ListNode* head)
    {
        int count=0;
        while(head!=NULL)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    bool isPalindrome(ListNode* head) {
        int n = measure(head);
        /*
        if(n==1)
        {
            return true;
        }
        */
        int middle = n/2;
        cout<<middle<<'\n';
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* next=head;
        for(int i=0;i<middle;i++)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        head=prev;
        cout<<"head: "<<head<<'\n';
        ListNode*head2;
        head2=cur;
        if(n%2==1)
        {
            head2=head2->next;
            cout<<"head2: "<<head2<<'\n';
            cout<<cur->val<<'\n';
            //delete cur;
        }
        return compare(head, head2);
    }
};
///
bool isPalindrome(ListNode* head) {
    ListNode* slowp = head, fastp = head, revp = NULL;
    while (fastp && fastp->next){
        fastp = fastp->next->next;
        ListNode* tmp = slowp->next;
        slowp->next = revp;
        revp = slowp;
        slowp = tmp;
    }
    if (fastp) slowp = slowp->next;
    while (slowp && revp){
        if (slowp->val != revp->val) return false;
        slowp = slowp->next;
        revp = revp->next;
    }
    return true;
}
/////
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode *second = reverseList(fast);
        while (second && second->val == head->val) {
            second = second->next;
            head = head->next;
        }
        slow->next = fast;
        return second == NULL;
    }
private:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = NULL, *next = NULL;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
///
For an O(n)-O(1) answer, the common idea can be summarized as:

find the middle.
reverse half of the list (reverse the latter half would be more comprehensible).
easily check for palindromic-ness as if it's a double-link list.
restore the reversed half

class Solution { public: inline void reverse(ListNode* head) { ListNode *node1, *node2, *node3; node1 = head; node2 = node1->next; node1->next = NULL; while(node2) { node3 = node2->next; node2->next = node1; node1 = node2; node2 = node3; } }

bool isPalindrome(ListNode* head) {

// lengths 0, 1 are palindrome
if(!head || !head->next)
{
    return true;
}

// length 2 goes simple judging
if(!head->next->next)
{
    return head->val == head->next->val;
}

// step 1: find middle and tail nodes
ListNode *middle, *rbegin;
middle = rbegin = head;
while(rbegin->next)
{
    if(rbegin->next->next)
    {
        middle = middle->next;
        rbegin = rbegin->next->next;
    }
    else
    {
        rbegin = rbegin->next;
    }
}

// step 2: reverse the latter half
reverse(middle->next);

// step 3: check for palindrome
bool result = true;
ListNode* node1 = head;
ListNode* node2 = rbegin;
while(node2)
{
    if(node1->val != node2->val)
    {
        result = false;
        break;
    }

    node1 = node1->next;
    node2 = node2->next;
}

// step 4: restore the reversed latter half
reverse(rbegin);

return result;
} };

/////
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode *second = reverseList(fast);
        while (second && second->val == head->val) {
            second = second->next;
            head = head->next;
        }
        slow->next = fast;
        return second == NULL;
    }
private:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = NULL, *next = NULL;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
///
I reversed the first half except head, which is very convenient in my opinion. below is my code. len/2-2 node(s) been modified and restored.

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return 1;
        int len=1;
        ListNode *r=head;
        for(;r->next;r=r->next) { ++len; }
        if(head->val!=r->val) return 0; // early terminated if head->val!=tail->val
        // reverse the first half except head, only if len>=6
        int i=len/2-2;
        ListNode *ml,*mr, *p,*q;
        p=head->next, q=p->next;
        for(;i>0;--i) {
            r=q->next;
            q->next=p;
            p=q;
            q=r;
        }
        // record the boundaries in the middle
        ml=p;
        mr=q;
        // adjust the start pos of second half
        if(len&1) q=q->next;
        // palindrome check
        i=len/2-1;
        int isok=1;
        for(;i>0;--i) {
            if(p->val!=q->val) { isok=0; break; }
            p=p->next, q=q->next;
        }
        // restore the reversed half
        i=len/2-2;
        p=ml, q=mr;
        for(;i>0;--i) {
            r=p->next;
            p->next=q;
            q=p;
            p=r;

        }
        return isok;
    }
};
/////
ListNode reverse(ListNode head) {
    ListNode prev = null;
    while(head!=null) {
        ListNode tmp = head.next;
        head.next = prev;
        prev = head;
        head = tmp;
    }
    return prev;
}

public boolean isPalindrome(ListNode head) {
    if (head==null) return true;

    //Find middle node: use slow, fast pointers.
    ListNode fast = head.next;
    ListNode mid = head;
    while(fast !=null && fast.next != null) {
        fast = fast.next.next;
        mid = mid.next;
    }

    //Reverse: mid..end
    ListNode tail = reverse(mid);

    //Compare tail to mid and start to mid.
    while (tail !=null && head != null) {
        if (tail.val != head.val) {
            return false;
        }
        tail = tail.next;
        head = head.next;
    }
    return true;
}
/////
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        /***********EXEMPLE*****************
        * Original Linklist:
        *   1-->2-->3-->4-->3-->2-->1-->null
        * 
        * Then reverse the pre-half list.
        * After iteration:
        * head        prev slow        fast
        *   |           |   |            |
        *   1<--2<--3<--4   3-->2-->1-->null
        * And isOdd becomes false.
        ************************************/
        ListNode *fast, *slow, *prev, *next;
        prev = new ListNode(0);
        fast = slow = head;
        bool isOdd = true;
        while(fast) {
            if(fast->next) {
                fast = fast->next->next;
            }
            else {
                fast = fast->next;
                isOdd = false;
            }
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        if(!isOdd) prev = prev->next;
        //Here you can again reverse the list while I did not.
        while(slow) {
            if(slow->val != prev->val)
                return false;
            slow = slow->next;
            prev = prev->next;
        }
        return true;
    }
};
Actually, too much pointer operation makes it a little ambiguous. Any other methods without reversing the linklist?

/////
class Solution {
  public:
    ListNode* reverse(ListNode* head){
    ListNode* current = head;
    if (current == NULL || current->next == NULL) return current; // if there isn't a node or just one node, return the input
    ListNode* prev = NULL; // define the first previous as NULL since the previous node of the head in reverse order is NULL 
    ListNode* next;
    while(current != NULL){   
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev; // return the resultant head
}

bool isPalindrome(ListNode* head) {
     //Find the middle 
     //slownode moves by one, and fastnode moves by two


     if(head == NULL || head->next == NULL) return true;


     ListNode* fast = head;
     ListNode* slow = head;

     while(fast->next != NULL && fast->next->next != NULL){
         fast = fast->next;
         fast = fast->next;
         slow = slow->next;
     }


     ListNode* middle = slow;
     ListNode* second = reverse(middle->next);
     ListNode* first = head;
     //reverse the second half
     //compare the first half and the reversed second half

     while(first != NULL && second!=NULL){
        if (first->val != second->val){
            return false;
        }
        first = first->next;
        second = second->next;
     }
     return true;
  }  };
/////
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution 
{
    public boolean isPalindrome(ListNode head) 
    {
        Stack<Integer> s = new Stack<Integer>();
        ListNode temp = head;
        ListNode cur = head;
        while(temp != null)
        {
            s.push(temp.val);
            temp = temp.next;
        }
        while(cur != null)
        {
            if(cur.val != s.peek())
                return false;
            else
            {
                cur = cur.next;
                s.pop();
            }
        }
        return true;
    }
}
/////
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* tmp = head;
        int count = 0;
        while(tmp){
            count++;
            tmp = tmp->next;
        }
        if(count==1) return true;
        int half = count/2 + count%2;
        for(int i=1; i<=half;i++){
            s.push(head->val);
            head = head->next;
        }
        if(count%2) s.pop();    // incase of {1,0,0} such cases
        while(head && head->val == s.top()){
            head = head->next;
            s.pop();
        }
        if(!head) return true;
        return false;
    }
};
///
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = reverse(slow->next);
        if(fast == nullptr) slow = nullptr;
        else slow->next = nullptr;
        ListNode* first = head;
        while(first != nullptr && second != nullptr){
            if(first->val != second->val)
            return false;
            first = first->next;
            second = second->next;
        } 
        return true;
    }
    ListNode* reverse(ListNode* root){
        if(root == nullptr||root->next == nullptr) return root;
        ListNode* prev = nullptr;
        ListNode* cur = root;
        ListNode* nxt;
        while(cur){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};
///
I think it's better to recover the list in the end.

bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) return true;
    ListNode* slow= head, *fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    reverse(slow);
    ListNode* cur2 = slow->next, *cur1 = head;
    bool ret = true;
    while(cur2) {
        if (cur2->val != cur1->val) {
            ret = false;
            break;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    reverse(slow);
    return ret;
}

void reverse(ListNode* pre) {
    if (pre == NULL || pre->next == NULL) return;
    ListNode* cur = pre->next->next, *tmp = NULL;
    pre->next->next = NULL;
    while(cur) {
        tmp = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = tmp;
    }
}
/////
My solution has three parts.

Halve the list into two lists.
Reverse one of the sub lists.
Compare

bool isPalindrome(ListNode* head) {
if(!head) return true;

ListNode* slow = head;
ListNode* fast = slow->next;

// separate
while(fast && fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
}

ListNode* head2 = slow->next;
slow->next = NULL;

ListNode* prev = NULL;
ListNode* cur = head2;
ListNode* next = NULL;

//reverse
while(head2) {
    next = head2->next;
    head2->next = prev;
    prev = head2;
    head2 = next;
}

 ///compare
head2 = prev;
while(head && head2) {
    if(head->val != head2->val)
        return false;

    head = head->next;
    head2 = head2->next;
}

return true;
}
/////
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};

//
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    bool flag = true;
    recur_pal(head, head->next, flag);
    return flag;
}
void recur_pal(ListNode *&head, ListNode *tail, bool &flag) {
    if (head == tail || head == tail->next) return;
    if (tail->next) {
        recur_pal(head, tail->next, flag);
    }
    if (head->val != tail->val) { flag  = false; return;}
        head = head->next;
}
///
first reverse the second half ans compare it with first half to check whether linked list is palindrome or not.

     struct ListNode * rev(struct ListNode * head)  //function for reverse the list
     {
         struct ListNode *a=0,*b=head,*c,*hh;
         if(b) c=b->next;
         while(b)
         {
         b->next=a;
         a=b;
         b=c;
         if(c) c=c->next;
         }
         return a;
     }

    class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            struct ListNode *s,*f;
            s=f=head;
            if(!head || !head->next) return true;
            while(f->next && f->next->next)
            {
                s=s->next;
                f=f->next->next;
            }
             s=s->next;
             s=rev(s);   // s is reversed second half
             f=head;
             while(s!=0)  //compare first half with second half
             {
                 if(s->val==f->val){s=s->next,f=f->next;}
                 else return false;
             }
             return true;

        }
    };

///recursion is actually O(n) space.

bool isPalindrome(ListNode* head) {

    return !head||helper(head, head);
}

bool helper(ListNode* reverse, ListNode* &normal){
    bool isP = true;
    if(reverse->next)
        isP = helper(reverse->next, normal);

    isP  = isP && (reverse->val == normal->val);
    normal = normal->next;

    return isP;
}
///
The idea is

find the length of the list and then reverse the first half of the list,
compare the reversed first half with the second half to get the result,
reverse the first half again to recover the list
So the algorithm has O(N) time complexity

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int i, len =0;
        ListNode *prev, *cur = head, *suc, *sHead;
        bool res = true;

        // calculate the length of the list
        while(cur) 
        {
            ++len; 
            cur = cur->next;

        }

        if(len<=1) return true;
        else if(2==len) return (head->val == head->next->val);
        else
        {
            //reverse the first half of the list
            for(i = 0, cur = head, prev = nullptr; i<len/2; ++i)
            {
                suc = cur->next;
                cur->next = prev;
                prev = cur;
                cur = suc;
            }

            head  = prev; // head now points to the head of the reversed first half list
            sHead = len%2 ? suc->next:suc; // sHead is the head of the second half list, for odd length, skip the middle node

            // compare
            while(sHead && (sHead->val == head->val))
            {
                sHead = sHead->next;
                head  = head->next;
            }
            res = (nullptr == sHead); // update the return value

            //reverse the first half of the list again;
            cur  =prev;
            prev = suc;
            for(auto i = 0; i<len/2 ; ++i)
            {
                suc = cur->next;
                cur->next = prev;
                prev = cur;
                cur = suc;
            }

            return res;
        }
    }
};
///
ListNode *reverse(ListNode *head) {
    ListNode *prev = nullptr;
    while (head != nullptr) {
        ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(ListNode *head) {
    ListNode *tail = head, *mid = head;
    while ((tail != nullptr) && (tail->next != nullptr)) {
        tail = tail->next->next;
        mid = mid->next;
    }
    tail = reverse(mid);
    while (head != mid) {
        if (head->val != tail->val) {
            return false;
        }
        head = head->next;
        tail = tail->next;
    }
    return true;
}
///
bool isPalindrome(ListNode* head) {
    int len = 0;
    ListNode *p = head;

    /* get length of the link */
    while(p){
        len++;
        p = p->next;
    }

    /* get next node of middle of link */
    p = head;
    int mid = len / 2;
    while(mid--) p = p->next;
    if(len % 2 == 1) p = p->next;

    /* reverse the back of the link */
    ListNode *prev = NULL, *next = NULL;
    while(p){
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }

    /* jude palindrome */
    p = prev;
    while(p){
        if(head->val != p->val) return false;
        head = head->next;
        p = p->next;
    }
    return true;
}
///
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return isPalindrome(head, head);
    }
    bool isPalindrome(ListNode* head, ListNode* &t) {   // reference of pointer
        if(head == NULL)
            return true;
        if(isPalindrome(head->next, t) && (head->val == t->val))
        {
            t = t->next;
            return true;
        }
        else 
            return false;

    }
};

class Solution {
public:
    ListNode *t;     // member
    bool isPalindrome(ListNode* head) {
        t = head; 
        return helper(head);
    }
    bool helper(ListNode* head) {
        if(head == NULL)
            return true;
        if(helper(head->next) && (head->val == t->val))
        {
            t = t->next;
            return true;
        }
        else 
            return false;

    }
};
///
class Solution {
public:
    bool isPalindrome(ListNode* slow, ListNode* fast)
    {
      if (fast == nullptr) {
        half = slow;
        return true;
      }
      if (fast->next == nullptr) {
        half = slow->next;
        return true;
      }

      if (isPalindrome(slow->next, fast->next->next) && slow->val == half->val) {
        half = half->next;
        return true;
      }

      return false;
    }

    bool isPalindrome(ListNode* head) {
      return isPalindrome(head, head);
    }

    ListNode* half;
};
