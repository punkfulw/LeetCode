# OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        for i in range(len(prices)-1):
            ans += max(0, prices[i+1] - prices[i])
        return ans
