# OJ: https://leetcode.com/problems/count-square-sum-triples/
# Author: github.com/punkfulw
# Time: O(N^2)
# Space: O(1)
class Solution:
    def countTriples(self, n: int) -> int:
        ans = 0
        for a in range(1, n + 1):
            for b in range(a + 1,  n + 1):
                cs = a * a + b * b
                c = int(cs ** 0.5)
                if c * c == cs and c <= n:
                    ans += 2           
        return ans
