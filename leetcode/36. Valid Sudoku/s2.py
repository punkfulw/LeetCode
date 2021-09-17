# OJ: https://leetcode.com/problems/valid-sudoku/
# Author: github.com/punkfulw
# Time: O(1)
# Space: O(1)
class Solution:
    def isValidSudoku(self, board):
        row, col, box = set(), set(), set()
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    cur = board[i][j]
                    if ((i, cur) in row) or ((j, cur) in col) or ((i//3, j//3, cur) in box):
                        return False
                    row.add((i, cur))
                    col.add((j, cur))
                    box.add((i//3, j//3, cur))
        return True
