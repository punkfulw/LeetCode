# OJ: https://leetcode.com/problems/house-robber/
# Author: github.com/punkfulw
# Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/198.%20House%20Robber/README.md
# Time: O(N)
# Space: O(1)
class Solution:
    def rob(self, nums: List[int]) -> int:
        cur = pp = p = 0
        for i in nums:
            cur = max(pp + i, p)
            pp = p
            p = cur
        return cur
