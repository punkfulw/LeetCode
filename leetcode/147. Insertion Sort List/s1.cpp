// OJ: https://leetcode.com/problems/insertion-sort-list/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0), *p, *pre, *nxt; 
        while (head){
            int num = head->val;
            nxt = head->next, pre = dummy, p = dummy->next;
            while (p && num > p->val){
                pre = p;
                p = p->next;
            }
            head->next = p;
            pre->next = head;
            head = nxt;
        }
        return dummy->next;
    }
};
