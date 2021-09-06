// OJ: https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 0; i <= nums.size()-k; i++)
            ans = min(ans, nums[i + k - 1] - nums[i]);
        return ans;
    }
};
