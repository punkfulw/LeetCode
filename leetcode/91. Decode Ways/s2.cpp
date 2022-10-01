// OJ: https://leetcode.com/problems/decode-ways
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);        
        dp[n] = 1;
        
        for (int i = n - 1; i >= 0; i--){
            if (s[i] == '0'){
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i + 1];
            int dig2 = i < n - 1 ? 10 * (s[i] - '0') + (s[i + 1] - '0') : 0;
            if (dig2 >= 10 && dig2 <= 26)
                dp[i] += dp[i + 2];
        }
        return dp[0];
    }
};
