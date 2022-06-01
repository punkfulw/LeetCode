# OJ: https://leetcode.com/problems/running-sum-of-1d-array/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        return accumulate(nums)
