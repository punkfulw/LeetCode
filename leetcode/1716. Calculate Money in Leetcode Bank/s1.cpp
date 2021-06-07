// OJ: https://leetcode.com/problems/calculate-money-in-leetcode-bank/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int week = 0;
        for (int i = 1; i <= n; i++){
            if (i % 7)
                ans = ans + (i % 7) + week;
            else{
                ans = ans + 7 + week;
                week++;
            }
        }
        return ans;
    }
};
