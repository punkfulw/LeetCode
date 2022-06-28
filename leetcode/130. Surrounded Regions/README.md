# [130. Surrounded Regions (Medium)](https://leetcode.com/problems/surrounded-regions/)

<p>Given an <code>m x n</code> matrix <code>board</code> containing <code>'X'</code> and <code>'O'</code>, <em>capture all regions that are 4-directionally&nbsp;surrounded by</em> <code>'X'</code>.</p>

<p>A region is <strong>captured</strong> by flipping all <code>'O'</code>s into <code>'X'</code>s in that surrounded region.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg" style="width: 550px; height: 237px;">
<pre><strong>Input:</strong> board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
<strong>Output:</strong> [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
<strong>Explanation:</strong> Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> board = [["X"]]
<strong>Output:</strong> [["X"]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>board[i][j]</code> is <code>'X'</code> or <code>'O'</code>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Number of Islands (Medium)](https://leetcode.com/problems/number-of-islands/)
* [Walls and Gates (Medium)](https://leetcode.com/problems/walls-and-gates/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/surrounded-regions/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int n, m;
    int dirs[5] = {0, 1, 0, -1, 0};
    
    void dfs(int i, int j, vector<vector<char>>& board){
        board[i][j] = '#';
        
        for (int d = 0; d < 4; d++){
            int r = i + dirs[d], c = j + dirs[d + 1];
            if (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 'O')
                dfs(r, c, board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++){
            if (board[i][0] == 'O')
                dfs(i, 0, board);
            if (board[i][m - 1] == 'O')
                dfs(i, m - 1, board);
        }
        
        for (int j = 0; j < m; j++){
            if (board[0][j] == 'O')
                dfs(0, j, board);
            if (board[n - 1][j] == 'O')
                dfs(n - 1, j, board);
        }
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        
        return;
    }
};
```
