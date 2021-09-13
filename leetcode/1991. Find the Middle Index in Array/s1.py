# OJ: https://leetcode.com/problems/find-the-middle-index-in-array/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution(object):
    def findMiddleIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, sum(nums)
        for i, num in enumerate(nums):
            right -= num;
            if right == left:
                return i
            left += num
        return -1
