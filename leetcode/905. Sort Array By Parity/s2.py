# OJ: https://leetcode.com/problems/sort-array-by-parity/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        i = 0
        for j, num in enumerate(nums):
            if num % 2 == 0:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
        return nums
