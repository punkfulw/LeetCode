// OJ: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/109068/JavaC%2B%2B-Clean-Code-8-lines
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp (n+1, vector<int> (m+1));
        int ans = 0;
        
        for (int i = n-1; i >= 0; i--){
            for (int j = m-1; j >= 0; j--){
                if (nums1[i] == nums2[j]){
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
