// OJ: https://leetcode.com/problems/merge-two-sorted-lists/
// Author: github.com/punkfulw
// Time: O(m + n)
// Space: O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(INT_MIN);
        ListNode *p = &dummy;
        while (l1 != NULL && l2 != NULL){
            if (l1->val <= l2->val){
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }    
        }
        p->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
