// OJ: https://leetcode.com/problems/merge-in-between-linked-lists/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* mergeStart,  *cur = list1;
        for (int i = 0; i <= b; i++){
            if (i == a-1)
                mergeStart = cur;
            cur = cur->next;
        }
        mergeStart->next = list2;
        while (list2->next != NULL)
            list2 = list2->next;
        list2->next = cur;
        return list1;
    }
};
