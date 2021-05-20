// OJ: https://leetcode.com/problems/delete-node-in-a-linked-list/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};
