# OJ: https://leetcode.com/problems/fibonacci-number/
# Author: github.com/punkfulw
# Time: O(2^N)
# Space: O(N)
class Solution:
    def fib(self, n: int) -> int:
        if n <= 1:
            return n
        return self.fib(n-1) + self.fib(n-2)
