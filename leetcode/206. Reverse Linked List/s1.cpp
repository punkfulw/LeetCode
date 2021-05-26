// OJ: https://leetcode.com/problems/reverse-linked-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL, *cur = NULL;
        while (head != NULL){
            pre = cur;
            cur = head;
            head = head->next;
            cur->next = pre;
        }
        return cur;
    }
};
