// OJ: https://leetcode.com/problems/longest-increasing-subsequence/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        vector<int> dp (nums.size(), 1);
        for (int i = 1; i < nums.size(); i++){
            int cnt = 0;
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i])
                    cnt = max(cnt, dp[j]);
            
            dp[i] = cnt + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
