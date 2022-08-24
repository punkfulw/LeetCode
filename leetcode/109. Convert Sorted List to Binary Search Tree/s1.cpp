// OJ: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return NULL;
        ListNode* slow = head, *fast = head, *tail, *pre = head;
        while (fast && fast->next){
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        tail = slow->next;
        pre->next = NULL;
        TreeNode* root= new TreeNode(slow->val);
        if (slow != head)
            root->left = sortedListToBST(head);
        root->right = sortedListToBST(tail);
        return root;
    }
};
