// OJ: https://leetcode.com/problems/count-sorted-vowel-strings/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp = {0, 1, 1, 1, 1, 1};
        
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= 5; j++)
                dp[j] += dp[j - 1];
        
        return dp[5];
    }
};
