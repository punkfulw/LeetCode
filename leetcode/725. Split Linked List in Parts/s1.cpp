// OJ: https://leetcode.com/problems/split-linked-list-in-parts/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = ListSize(head);
        vector<ListNode*> ans(k, NULL);
        int n = cnt / k, remain = cnt % k;
        ListNode* node = head, *pre;
        
        for (int i = 0; node && i < k; i++, remain--){
            ans[i] = node;
            for (int j = 0; j < n + (remain > 0); j++){
                pre = node;
                node = node->next;
            }
            pre->next = NULL;
        }
        
        return ans;
    }
    
    int ListSize(ListNode* head){
        int cnt = 0;
        while (head != NULL){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
};
