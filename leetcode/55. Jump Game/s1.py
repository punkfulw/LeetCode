# OJ: https://leetcode.com/problems/jump-game/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        power = nums[0]
        for i in range(len(nums)-1):
            power = max(power, nums[i]) - 1
            if power < 0:
                return False
        return True 
            
