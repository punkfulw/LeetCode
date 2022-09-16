// OJ: https://leetcode.com/problems/longest-common-subsequence/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/1143.%20Longest%20Common%20Subsequence/README.md
// Time: O(MN)
// Space: O(min(M, N))
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int dp[1002] = {};      
        for (int i = 1; i <= n; i++){
            int pre = 0;
            for (int j = 1; j <= m; j++){
                int cur = dp[j];
                if (s1[i - 1] == s2[j - 1])
                    dp[j] = pre + 1;
                else
                    dp[j] = max(dp[j - 1], dp[j]);
                pre = cur;
            }
        }
        return dp[m];
    }
};
