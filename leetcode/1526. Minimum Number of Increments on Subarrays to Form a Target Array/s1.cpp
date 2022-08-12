// OJ: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minNumberOperations(vector<int>& nums) {
        int ans = nums[0], n = nums.size();
        for (int i = 1; i < n; i++)
            if (nums[i] > nums[i - 1])
                ans += nums[i] - nums[i - 1];
        return ans;
    }
};
