// OJ: https://leetcode.com/problems/merge-k-sorted-lists/
// Author: github.com/punkfulw
// Time: O(NlogK)
// Space: O(N)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        while (lists.size() > 1){
            int n = lists.size();
            vector<ListNode*> cur;
            for (int i = 0; i < n - 1; i += 2){
                ListNode* dummy = new ListNode(0), *head = dummy, *l1 = lists[i], *l2 = lists[i + 1];
                while (l1 && l2){
                    if (l1->val < l2->val){
                        head->next = l1;
                        l1 = l1->next;
                    }
                    else {
                        head->next = l2;
                        l2 = l2->next;
                    }
                    head = head->next;
                }
                if (l1)
                    head->next = l1;
                else
                    head->next = l2;
                head = dummy->next;
                delete(dummy);
                cur.push_back(head);
            }
            if (n % 2)
                cur.push_back(lists.back());
            lists = cur;
        }
        
        return lists[0];
    }
};
