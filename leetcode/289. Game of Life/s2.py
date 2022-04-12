# OJ: https://leetcode.com/problems/game-of-life/
# Author: github.com/punkfulw
# Ref: https://leetcode.com/problems/game-of-life/discuss/73230/C%2B%2B-O(1)-space-O(mn)-time
# Time: O(NM)
# Space: O(1)
class Solution:
        
    def gameOfLife(self, board: List[List[int]]) -> None:
        n, m = len(board), len(board[0])
        
        def check(self, i, j) -> None:
            cnt = 0
            for r in range (i-1, i+2):
                for c in range (j-1, j+2):
                    if r < 0 or c < 0 or r >= n or c >= m or (r == i and c == j):
                        continue
                    cnt += board[r][c] & 1
            if cnt == 3 or (cnt == 2 and board[i][j] == 1):
                board[i][j] |= 2
                
        for i in range(n):
            for j in range(m):
                check(self, i, j)
                
        for i in range(n):
            for j in range(m):
                board[i][j] >>= 1
