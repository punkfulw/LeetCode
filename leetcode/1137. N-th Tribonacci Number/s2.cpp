// OJ: https://leetcode.com/problems/n-th-tribonacci-number/
// Author: github.com/punkfulw
// Time: O(3^N)
// Space: O(N)
class Solution {
public:
    int dp[38] = {0, 1, 1};
    int tribonacci(int n) {
        if (n < 2) 
            return n;
        if (n == 2) return 1;
        if (dp[n])
            return dp[n];
        dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return dp[n];      
    }
};
