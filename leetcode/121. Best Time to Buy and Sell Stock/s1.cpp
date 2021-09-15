// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int mn = nums[0];
        for (int i = 1; i < n; i++){
            mn = min(nums[i], mn);
            ans = max(ans, nums[i] - mn);
        }
        return ans;
    }
};
