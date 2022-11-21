// OJ: https://leetcode.com/problems/divisor-game/
// Author: github.com/punkfulw
// Time: O(N * sqrt(N))
// Space: O(N)
class Solution {
public:
    int dp[1001] = {};
    bool divisorGame(int n) {
        if (n == 1)
            return false;
        if (n == 2)
            return true;
        if (dp[n])
            return dp[n];
        bool ret = false;
        
        for (int i = 1; i <= n / 2 && !ret; i++)
            if (n % i == 0)
                ret |= !divisorGame(n - i);

        return dp[n] = ret;
    }
};
