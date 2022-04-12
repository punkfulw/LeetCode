# [289. Game of Life (Medium)](https://leetcode.com/problems/game-of-life/)

<p>According to the <a href="https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life" target="_blank">Wikipedia's article</a>: "The <b>Game of Life</b>, also known simply as <b>Life</b>, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."</p>

<p>Given a <i>board</i> with <i>m</i> by <i>n</i> cells, each cell has an initial state <i>live</i> (1) or <i>dead</i> (0). Each cell interacts with its <a href="https://en.wikipedia.org/wiki/Moore_neighborhood" target="_blank">eight neighbors</a> (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):</p>

<ol>
	<li>Any live cell with fewer than two live neighbors dies, as if caused by under-population.</li>
	<li>Any live cell with two or three live neighbors lives on to the next generation.</li>
	<li>Any live cell with more than three live neighbors dies, as if by over-population..</li>
	<li>Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.</li>
</ol>

<p>Write a function to compute the next state (after one update) of the board given its current state.&nbsp;<span>The next state is created by applying the above rules simultaneously to every cell in the current state, where&nbsp;births and deaths occur simultaneously.</span></p>

<p><strong>Example:</strong></p>

<pre><strong>Input: 
</strong><span id="example-input-1-1">[
&nbsp; [0,1,0],
&nbsp; [0,0,1],
&nbsp; [1,1,1],
&nbsp; [0,0,0]
]</span>
<strong>Output: 
</strong><span id="example-output-1">[
&nbsp; [0,0,0],
&nbsp; [1,0,1],
&nbsp; [0,1,1],
&nbsp; [0,1,0]
]</span>
</pre>

<p><b>Follow up</b>:</p>

<ol>
	<li>Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.</li>
	<li>In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?</li>
</ol>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Set Matrix Zeroes (Medium)](https://leetcode.com/problems/set-matrix-zeroes/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/game-of-life/
// Author: github.com/punkfulw
// Time: O(NM)
// Space: O(NM)
class Solution {
public:
    int n, m;
    void check(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& board)
    {
        int ones = 0;
        for (int i = row - 1; i <= row + 1 ; i++)
        {
            for (int j = col - 1; j <= col + 1; j++)
            {
                if ((i == row && j == col) || i < 0 || i >= n || j < 0 || j >= m)
                    continue;
                ones += board[i][j];
            }
        }
        if (board[row][col] == 1)
        {
            if (ones < 2)
                ans[row][col] = 0;
            else if (ones > 3)
                ans[row][col] = 0;
        }
        else
        {
            ans[row][col] = ones == 3 ? 1 : 0;
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        n = board.size(), m = board[0].size();
        vector<vector<int>> ans = board;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                check(i, j, ans, board);
        board = ans;
        
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/game-of-life/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/game-of-life/discuss/73230/C%2B%2B-O(1)-space-O(mn)-time
// Time: O(NM)
// Space: O(1)
class Solution {
public:
    int n, m;
    void check(int row, int col, vector<vector<int>>& board)
    {
        int ones = 0;
        for (int i = row - 1; i <= row + 1 ; i++)
        {
            for (int j = col - 1; j <= col + 1; j++)
            {
                if ((i == row && j == col) || i < 0 || i >= n || j < 0 || j >= m)
                    continue;
                ones += board[i][j] & 1;
            }
        }
        if ((board[row][col] & 1 && ones == 2) || ones == 3)
            board[row][col] |= 2;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                check(i, j, board);       
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] >>= 1;
    }
};
```

## Solution 2-1.

```python3
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
```
