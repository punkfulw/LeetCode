# OJ: https://leetcode.com/problems/number-of-islands/
# Author: github.com/punkfulw
# Time: O(MN)
# Space: O(MN)
class Solution:
    def dfs(self, i, j, grid):
        grid[i][j] = "0"
        for k in range(4):
            x, y = i + self.dirs[k], j + self.dirs[k + 1]
            if x >= 0 and x < self.n and y >= 0 and y < self.m and grid[x][y] == "1":
                self.dfs(x, y, grid)
    def numIslands(self, grid: List[List[str]]) -> int:
        self.n, self.m = len(grid), len(grid[0])
        self.dirs = [0, 1, 0, -1, 0]
        ans = 0
        for i in range(self.n):
            for j in range(self.m):
                if grid[i][j] == "1":
                    ans += 1
                    self.dfs(i, j, grid)
        return ans
