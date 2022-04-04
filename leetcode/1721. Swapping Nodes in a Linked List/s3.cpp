// OJ: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/discuss/1110270/7-lines-C%2B%2B-1-pass-no-value-swapping
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode **a = &head;
        while (--k)  
            a = &(*a)->next; 
        ListNode **b = &head, **x = &(*a)->next;
        while (*x) 
        { 
            x = &(*x)->next; 
            b = &(*b)->next; 
        }
        swap(*a, *b);  //change the incoming link
        swap((*a)->next, (*b)->next);  //change the outgoing link  //order matters!!
        return head;
    }
};
