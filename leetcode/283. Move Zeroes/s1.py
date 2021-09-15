# OJ: https://leetcode.com/problems/move-zeroes/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        j, n = 0, len(nums)
        for i in range(n):
            while i < n and nums[i] == 0:
                i += 1
            if i >= n: 
                break;
            nums[i], nums[j] = nums[j], nums[i]
            j += 1
