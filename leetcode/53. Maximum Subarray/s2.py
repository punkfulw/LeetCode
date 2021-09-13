# OJ: https://leetcode.com/problems/maximum-subarray/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1) 
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = cur = nums[0]
        for i in range(1, len(nums)):
            cur = max(nums[i], cur + nums[i])
            ans = max(ans, cur)
        return ans
