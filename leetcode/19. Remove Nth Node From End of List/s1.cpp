// OJ: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        int cnt = 1;
        for (auto p = head; p->next; p = p->next)
            cnt++;
        cnt -= n;
        if (cnt == 0){
            dummy.next = head->next;
            delete(head);
            return dummy.next;
        }
        for (auto p = head; p; p = p->next){
            if (cnt == 1){
                auto d = p->next;
                p->next = d->next;
                delete(d);
                break;
            }
            cnt--;
        }
        return head;
    }
};
