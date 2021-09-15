# OJ: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        l, r = 0, len(nums)-1
        while nums[l] + nums[r] != target:
            if nums[l] + nums[r] > target:
                r -= 1
            else:
                l += 1
        return [l+1, r+1]
