# OJ: https://leetcode.com/problems/best-sightseeing-pair/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        premax, ans = values[0], 0
        for i in range(1, len(values)):
            premax -= 1
            ans = max(ans, premax + values[i])
            premax = max(premax, values[i])
        return ans
