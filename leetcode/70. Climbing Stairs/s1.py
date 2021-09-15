# OJ: https://leetcode.com/problems/climbing-stairs/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        a, b, c = 1, 2, 0
        for i in range(n-2):
            c = a + b
            a = b
            b = c
        return c
