# [1219. Path with Maximum Gold (Medium)](https://leetcode.com/problems/path-with-maximum-gold/)

<p>In a gold mine <code>grid</code>&nbsp;of size <code>m * n</code>,&nbsp;each cell in this mine has an integer representing the amount of gold&nbsp;in that cell,&nbsp;<code>0</code> if it is empty.</p>

<p>Return the maximum amount of gold you&nbsp;can collect under the conditions:</p>

<ul>
	<li>Every time you are located in a cell you will collect all the gold in that cell.</li>
	<li>From your position you can walk one step to the left, right, up or down.</li>
	<li>You can't visit the same cell more than once.</li>
	<li>Never visit a cell with&nbsp;<code>0</code> gold.</li>
	<li>You can start and stop collecting gold from&nbsp;<strong>any </strong>position in the grid that has some gold.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> grid = [[0,6,0],[5,8,7],[0,9,0]]
<strong>Output:</strong> 24
<strong>Explanation:</strong>
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -&gt; 8 -&gt; 7.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
<strong>Output:</strong> 28
<strong>Explanation:</strong>
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 5 -&gt; 6 -&gt; 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= grid.length,&nbsp;grid[i].length &lt;= 15</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 100</code></li>
	<li>There are at most <strong>25&nbsp;</strong>cells containing gold.</li>
</ul>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/path-with-maximum-gold/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/path-with-maximum-gold/discuss/398228/C%2B%2B-DFS
// Time: O(k * 3 ^ k), where k is the number of cells with gold. We perform the analysis for k cells, and from each cell we can go in three directions.
// Space: O(k) for the recursion.
class Solution {
public:
    int dir[5] = {0, 1, 0, -1, 0}; 
    int n, m, ans;
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans = max(ans, dig(grid, i, j));
        return ans;
    }
    int dig(vector<vector<int>>& grid, int r, int c){
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] <= 0)
            return 0;
        grid[r][c] = -grid[r][c];
        int next = 0;
        for (int i = 0; i < 4; i++){
            int row = r + dir[i], col = c + dir[i+1];
            next = max(next, dig(grid, row, col));
        }
        grid[r][c] = -grid[r][c];
        return grid[r][c] + next;;
    }
};
```
