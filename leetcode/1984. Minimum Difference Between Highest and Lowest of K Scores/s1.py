# OJ: https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
# Author: github.com/punkfulw
# Time: O(NlogN)
# Space: O(1)
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = sys.maxsize
        for i in range(len(nums) - k + 1):
            ans = min(ans, nums[i + k - 1] - nums[i])
        return ans
