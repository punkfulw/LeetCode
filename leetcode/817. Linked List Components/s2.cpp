// OJ: https://leetcode.com/problems/linked-list-components/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 0;
        
        while (head){
            while (head && set.find(head->val) == set.end())
                head = head->next;
            if (!head)
                break;
            ans++;
            while (head && set.find(head->val) != set.end())
                head = head->next;
        }
        return ans;
    }
};
