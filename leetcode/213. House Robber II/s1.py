# OJ: https://leetcode.com/problems/house-robber-ii/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def rob(self, nums: List[int]) -> int:
        def helper(nums, start, end):
            pp = p = cur = 0
            for i in range(start, end):
                cur = max(pp + nums[i], p)
                pp = p
                p = cur
            return cur
        
        ans = nums[0]
        ans = max(ans, helper(nums, 0, len(nums)-1))
        ans = max(ans, helper(nums, 1, len(nums)))
        return ans
