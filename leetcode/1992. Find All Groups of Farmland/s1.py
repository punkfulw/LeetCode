# OJ: https://leetcode.com/problems/find-all-groups-of-farmland/
# Author: github.com/punkfulw
# Time: O(MN)
# Space: O(MN)
class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        n = len(land)
        m = len(land[0])
        ans = []
        for i in range(n):
            for j in range(m):
                if land[i][j] == 0:
                    continue
                if i > 0 and land[i-1][j]:
                    continue
                if j > 0 and land[i][j-1]:
                    continue
                r2 = i
                c2 = j
                while c2+1 < m and land[i][c2+1] == 1: 
                    c2 += 1
                while r2+1 < n and land[r2+1][c2] == 1: 
                    r2 += 1
                ans.append([i, j, r2, c2])
        return ans
            
