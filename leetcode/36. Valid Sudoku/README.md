# [36. Valid Sudoku (Medium)](https://leetcode.com/problems/valid-sudoku/)

<p>Determine if a <code>9 x 9</code> Sudoku board is valid. Only the filled cells need to be validated <b>according to the following rules:</b></p>

<ul>
  <li>Each row must contain the digits <code>1-9</code> without repetition.</li>
  <li>Each column must contain the digits <code>1-9</code> without repetition.</li>
  <li>Each of the nine <code>3 x 3</code> sub-boxes of the grid must contain the digits <code>1-9</code> without repetition.</li>
</ul>

<p><b>Note:</b></p>

<ul>
  <li>A Sudoku board (partially filled) could be valid but is not necessarily solvable.</li>
  <li>Only the filled cells need to be validated according to the mentioned rules.</li>
</ul>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong>  board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
<strong>Output:</strong> false
<strong>Explanation:</strong>  Same as Example 1, except with the 5 in the top left corner being modified to 8.
Since there are two 8's in the top left 3x3 sub-box, it is invalid.
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> nums = [3,3], target = 6
<strong>Output:</strong> [3,3]
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>board.length == 9</code></li>
  <li><code>board[i].length == 9</code></li>
  <li><code>board[i][j]</code> is a digit or <code>'.'</code>.</li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Matrix](https://leetcode.com/tag/matrix/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/valid-sudoku/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.' && (!check1(board, i, j) || !check2(board, i, j)))
                    return false;
            }
        }
        return true;
    }
    bool check1(vector<vector<char>>& board, int row, int col){
        int r = row / 3 * 3, c = col / 3 * 3;
        int cnt = 0;
        for (int i = r; i < r + 3; i++)
            for (int j = c; j < c + 3; j++)
                if (board[i][j] == board[row][col])
                    cnt++;
        return cnt == 1 ? true : false;

    }
    bool check2(vector<vector<char>>& board, int row, int col){
        int cntr = 0, cntc = 0;
        for (int i = 0; i < 9; i++){
            if (board[row][i] == board[row][col])
                cntc++;
            if (board[i][col] == board[row][col])
                cntr++;
        }
        if (cntc == 1 && cntr == 1)
            return true;
        return false;
    }
};
```

## Solution 2. optimize

```cpp
// OJ: https://leetcode.com/problems/valid-sudoku/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        vector<set<int>> row(9), col(9), box(9);
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (b[i][j] == '.') continue;
                int num = b[i][j] - '0', k = i / 3 * 3 + j / 3;
                if (row[i].count(num) || col[j].count(num) || box[k].count(num))
                    return false;
                row[i].insert(num);
                col[j].insert(num);
                box[k].insert(num);
            }
        }
        return true;
    }
};
```

```python3
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
```
