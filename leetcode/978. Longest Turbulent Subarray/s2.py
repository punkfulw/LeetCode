# OJ: https://leetcode.com/problems/longest-turbulent-subarray/
# Author: github.com/punkfulw
# Ref: https://leetcode.com/problems/longest-turbulent-subarray/discuss/221929/C%2B%2BJava-6-lines-flip-the-sign
# Time: O(N)
# Space: O(1)
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        ans = cur = 0
        for i in range(len(arr)-1):
            if arr[i] > arr[i+1]:
                if cur > 0: cur += 1
                else: cur = 1
            elif arr[i] < arr[i+1]:
                if cur < 0: cur -= 1
                else: cur = -1
            else: 
                cur = 0
            ans = max(ans, abs(cur))
            cur *= -1
        return ans+1
        
