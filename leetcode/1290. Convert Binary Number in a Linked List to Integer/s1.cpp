// OJ: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* index = head;
        vector<int> nums;
        while (index != nullptr){
            nums.push_back(index->val);
            index = index->next;
        }
        int ans {};
        for (int i = 0; i < nums.size(); i++){
            ans += nums[i] * pow(2, nums.size()-i-1);
        }
        return ans;
    }
};
