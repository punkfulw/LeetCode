// OJ: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int minInsertions(string s) {
        string t(s.rbegin(), s.rend());
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1));
        
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return n - dp[n][n];
    }
};
