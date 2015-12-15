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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        int lena = 1;
        ListNode *pa = headA;
        while(pa->next)
        {
            pa=pa->next; ++lena;
        }
        int lenb = 1;
        ListNode *pb = headB;
        while(pb->next)
        {
            pb=pb->next;
            ++lenb;
        }
        if(pa!=pb) return NULL;/// check end node 

        int dif = abs(lena-lenb);
        if(lena>lenb)
        {
            while(dif-->0)
            headA=headA->next;
        }
        else
        {
            while(dif-->0)
            headB=headB->next;
        }

        while(headA && headB && headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;


    }
};

////
class Solution {
public:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pA = headA;
    ListNode *pB = headB;
    int lenA = 0;
    int lenB = 0;
    while (pA) {++lenA;  pA = pA->next; }
    while (pB) {++lenB;  pB = pB->next; }
    for (int diff = abs(lenA - lenB); diff > 0; --diff) {
        if (lenA > lenB) {
            headA = headA->next;
        }
        else {
            headB = headB->next;
        }
    }
    while (headA && headB) {
        if (headA == headB) {
            return headA;
        }
        headA = headA ->next;
        headB = headB ->next;
    }
    return NULL;
}
};
////
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        struct ListNode* currentA = headA;
        struct ListNode* currentB = headB;
        int lenA = 0;
        int lenB = 0;
        if(headA == NULL || headB == NULL) return NULL; //Base case if any empty list return NULL;
//Calculate the length of each list;
        while(currentA){
            currentA = currentA->next;
            lenA++;
        }
        while(currentB){
            currentB = currentB->next;
            lenB++;
        }
//Push the longest list equal to the difference so they reach end at the same time;
        for(int diff = abs(lenA - lenB); diff>0; diff--){
            if(lenA>lenB){
                headA = headA->next;
            }
            else headB = headB->next;
        }
//Now both list has equal length, if we found any node that is equal is the intersection point
        while(headA && headB){
            if(headA == headB){
                return headA;}
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;

    }
};
////
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* cur_node_1 = headA;
    ListNode* cur_node_2 = headB;
    //cal diff of length
    while(cur_node_1 != nullptr && cur_node_2 != nullptr){
        cur_node_1 = cur_node_1->next;
        cur_node_2 = cur_node_2->next;
    }
    //make two start point with same length
    //will exchange point to the other list
    if(cur_node_1 != nullptr) {
        cur_node_2 = headA;
        while(cur_node_1 != nullptr){
            cur_node_1 = cur_node_1->next;
            cur_node_2 = cur_node_2->next;
        }
        cur_node_1 = headB;
    }
    else if(cur_node_2 != nullptr){
        cur_node_1 = headB;
        while(cur_node_2 != nullptr){
            cur_node_2 = cur_node_2->next;
            cur_node_1 = cur_node_1->next;
        }
        cur_node_2 = headA;
    }
    else{
        cur_node_1 = headB;
        cur_node_2 = headA;
    }
    //because len is same, they will meet each other if has joinpoint
    while(cur_node_1 != cur_node_2){
        cur_node_1 = cur_node_1->next;
        cur_node_2 = cur_node_2->next;
    }
    return cur_node_1;
}
/////
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    ListNode* s1 = headA, *s2 = headB;
    int dis = getdis(s1, s2);
    dis>=0? moveHead(dis, headA) : moveHead(-dis, headB);
    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

int getdis(ListNode* s1, ListNode* s2) {
    int i = 0;
    while (s1&&s2) {
        s1 = s1->next;
        s2 = s2->next;
    }
    if (s1){
        while (s1){ s1 = s1->next; i++; }
    }
    else
    while (s2){ s2 = s2->next; i--; };
    return i;
}

void moveHead(int i, ListNode*& n) {
    while (i > 0 && n) {
        n = n->next;
        i--;
    }
}
/////
The idea is to first fast forward each pointer to the end to find their distances from the end. Then we can fast forward the farther pointer so they're the same distance from the end. Finally we can fast forward both at the same time until they coincide.

This same exact approach can also be used to find the least common ancestor (LCA) of two nodes in a tree where nodes have parent pointers.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        auto currA = headA, currB = headB;
        int countA = 0, countB = 0;

        while (currA) { 
            currA = currA->next, countA++;
        }
        while (currB) {
            currB = currB->next, countB++;
        }
        int diff = std::abs(countA - countB);
        if (countB > countA) { swap(headA, headB); }
        while (diff--) { 
            headA = headA->next;
        }
        while (headA != headB) {
            headA = headA->next, headB = headB->next;
        }
        return headA;
    }
};
///

// time: O(n); memory: O(1);
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    int lenA = getLength(headA);
    int lenB = getLength(headB);

    ListNode *rootA = headA, *rootB = headB;

    while (lenA > lenB) {
        rootA = rootA->next;
        --lenA;
    }

    while (lenB > lenA) {
        rootB = rootB->next;
        --lenB;
    }

    while (rootA != nullptr && rootA != rootB) {

        rootA = rootA->next;
        rootB = rootB->next;
    }

    return rootA;

}

int getLength(ListNode *root) {

    int len = 0;

    while (root != nullptr) {
        root = root->next;
        ++len;
    }

    return len;
}

////
We assume that the length of headA is 'lenA' and the length of headB is 'lenB', we will find the node at which the intersection of two singly linked lists begins within 'lenA + lenB - 1' steps. The corresponding C++ code is:

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        if (headA == headB)
            return headA;
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = std::numeric_limits<int>::max() / 2, lenB = lenA;
        for (int i = 0; i != lenA + lenB - 1; ++i)
            if (curA->next)
                curA = curA->next;
            else {
                curA = headB;
                lenA = i + 1;
            }
            if (curB->next)
                curB = curB->next;
            else {
                curB = headA;
                lenB = i + 1;
            }
            if (curA == curB)
                return curA;
        }
        return NULL;
    }
};
