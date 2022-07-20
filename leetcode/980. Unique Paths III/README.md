# [980. Unique Paths III (Hard)](https://leetcode.com/problems/unique-paths-iii/)

<p>You are given an <code>m x n</code> integer array <code>grid</code> where <code>grid[i][j]</code> could be:</p>

<ul>
	<li><code>1</code> representing the starting square. There is exactly one starting square.</li>
	<li><code>2</code> representing the ending square. There is exactly one ending square.</li>
	<li><code>0</code> representing empty squares we can walk over.</li>
	<li><code>-1</code> representing obstacles that we cannot walk over.</li>
</ul>

<p>Return <em>the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/02/lc-unique1.jpg" style="width: 324px; height: 245px;">
<pre><strong>Input:</strong> grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/02/lc-unique2.jpg" style="width: 324px; height: 245px;">
<pre><strong>Input:</strong> grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/02/lc-unique3-.jpg" style="width: 164px; height: 165px;">
<pre><strong>Input:</strong> grid = [[0,1],[2,0]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 20</code></li>
	<li><code>1 &lt;= m * n &lt;= 20</code></li>
	<li><code>-1 &lt;= grid[i][j] &lt;= 2</code></li>
	<li>There is exactly one starting cell and one ending cell.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Cruise Automation](https://leetcode.com/company/cruise-automation), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Sudoku Solver (Hard)](https://leetcode.com/problems/sudoku-solver/)
* [Unique Paths II (Medium)](https://leetcode.com/problems/unique-paths-ii/)
* [Word Search II (Hard)](https://leetcode.com/problems/word-search-ii/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/unique-paths-iii/
// Author: github.com/punkfulw
// Time: O(3^(MN))
// Space: O(MN) 
class Solution {
public:
    int n, m, dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, ans = 0, end_x, end_y, ttl = 1;
    
    void dfs(int x, int y, int cnt, vector<vector<int>>& grid){
        if (grid[x][y] == -1)
            return;
        if (grid[x][y] == 2){
            ans += cnt == ttl;
            return;
        }
        
        grid[x][y] = 1;
        for (int d = 0; d < 4; d++){
            int r = x + dirs[d][0], c = y + dirs[d][1];
            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != 1)
                dfs(r, c, cnt + 1, grid);
        }
        grid[x][y] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int x, y;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1)
                    x = i, y = j;
                else if (grid[i][j] == 2)
                    end_x = i, end_y = j;
                else if (grid[i][j] == 0)
                    ttl++;
            }
        }
        dfs(x, y, 0, grid);
        return ans;
    }
};
```
