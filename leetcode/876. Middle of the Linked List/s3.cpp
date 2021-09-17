// OJ: https://leetcode.com/problems/middle-of-the-linked-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        bool cnt = true;
        ListNode* p = head;
        while (head->next){
            head = head->next;
            if (cnt) p = p->next;
            cnt = !cnt;
        }
        return p;
    }
};
