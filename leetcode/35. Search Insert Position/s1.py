# OJ: https://leetcode.com/problems/search-insert-position/
# Author: github.com/punkfulw
# Time: O(logN)
# Space: O(1)
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            m = (r + l) // 2
            if nums[m] < target:
                l = m + 1
            elif nums[m] > target:
                r = m - 1
            else:
                return m
        return l
