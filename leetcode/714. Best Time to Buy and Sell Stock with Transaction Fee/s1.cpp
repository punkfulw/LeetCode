// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = INT_MIN / 2, sold = 0, rest = 0, n = prices.size();
        
        for (int i = 0; i < n; i++){
            int preHold = hold;
            hold = max(hold, rest - prices[i]);  
            sold = max(sold, preHold + prices[i] - fee);
            rest = max(rest, sold);
        }        
        return max(sold, rest);
    }
};
