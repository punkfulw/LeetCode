# OJ: https://leetcode.com/problems/shift-2d-grid/
# Author: github.com/punkfulw
# Time: O(MN)
# Space: O(MN)
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n, m = len(grid), len(grid[0])
        ans = [[0] * m for _ in range(n)]
        ttl = n * m
        k %= ttl
        for i in range(ttl):
            pos = (i - k + ttl) % ttl
            ans[i // m][i % m] = grid[pos // m][pos % m]
        return ans;
