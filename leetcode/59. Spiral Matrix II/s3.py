# OJ: https://leetcode.com/problems/spiral-matrix-ii/
# Author: github.com/punkfulw
# Ref: https://leetcode.com/problems/spiral-matrix-ii/discuss/22282/4-9-lines-Python-solutions
# Time: O(N^2)
# Space: O(1)
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[0] * n for _ in range(n)]
        i, j, di, dj = 0, 0, 0, 1
        
        for k in range(n * n):
            ans[i][j] = k + 1
            if ans[(i + di) % n][(j + dj) % n] != 0:
                di, dj = dj, -di
            i += di
            j += dj
        return ans
