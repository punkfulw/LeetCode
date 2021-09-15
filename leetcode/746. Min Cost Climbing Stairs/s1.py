# OJ: https://leetcode.com/problems/min-cost-climbing-stairs/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        for i in range(2, len(cost)):
            cost[i] += min(cost[i-1], cost[i-2])
        return min(cost[-1], cost[-2])
