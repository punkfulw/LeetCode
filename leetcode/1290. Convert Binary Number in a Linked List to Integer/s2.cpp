// OJ: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans {};
        ListNode* index = head;
        while (index){
            ans = (ans << 1) + index -> val;
            index = index -> next;
        }
        return ans;
    }
};
