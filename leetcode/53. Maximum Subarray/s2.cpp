// OJ: https://leetcode.com/problems/maximum-subarray/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/53.%20Maximum%20Subarray/README.md
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN, cur = 0;
        
        for (int i = 0; i < n; i++){
            cur = max(cur, 0) + nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};
