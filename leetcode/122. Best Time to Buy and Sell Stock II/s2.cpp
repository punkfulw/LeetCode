// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans = 0;
        for (int i = 1; i < p.size(); i++)
            ans += max(p[i] - p[i-1], 0);
        return ans;
    }
};
