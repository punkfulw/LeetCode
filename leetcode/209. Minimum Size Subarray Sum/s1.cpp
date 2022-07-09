// OJ: https://leetcode.com/problems/minimum-size-subarray-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, n = nums.size(), j = 0;
        for (int i = 0; i < n; i++){
            target -= nums[i];
            while (target <= 0){
                ans = min(ans, i - j + 1);
                target += nums[j++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
