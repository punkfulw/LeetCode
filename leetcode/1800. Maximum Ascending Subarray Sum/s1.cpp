// OJ: https://leetcode.com/problems/maximum-ascending-subarray-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0], cnt = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (nums[i-1] < nums[i])
                cnt += nums[i];
            else
                cnt = nums[i];
            ans = max(ans, cnt);
        }
        return ans;
    }
};
