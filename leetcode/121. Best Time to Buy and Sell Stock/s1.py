# OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans, mn = 0, prices[0]
        for price in prices:
            mn = min(mn, price)
            ans = max(ans, price - mn)
        return ans
        
