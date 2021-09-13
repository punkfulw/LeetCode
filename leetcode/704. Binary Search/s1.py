# OJ: https://leetcode.com/problems/binary-search/
# Author: github.com/punkfulw
# Time: O(logN)
# Space: O(1)
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            m = (l + r) // 2
            if nums[m] == target:
                return m
            if nums[m] > target:
                r = m - 1
            if nums[m] < target:
                l = m + 1
        return -1
