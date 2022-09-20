// OJ: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int dp[1001] = {}, ans = 0;
        
        for (int i = 1; i <= n; i++)
            for (int j = 1, pre = 0, tmp; j <= m; j++){
                tmp = dp[j];
                if (nums1[i - 1] == nums2[j - 1])
                    dp[j] = pre + 1;
                else 
                    dp[j] = 0;
                pre = tmp;
                ans = max(ans, dp[j]);
            }

        return ans;
    }
};
