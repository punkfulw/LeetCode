# [1568. Minimum Number of Days to Disconnect Island (Medium)](https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/)

<p>Given a 2D&nbsp;<code>grid</code> consisting&nbsp;of <code>1</code>s (land)&nbsp;and <code>0</code>s (water).&nbsp; An <em>island</em> is a maximal 4-directionally (horizontal or vertical) connected group of <code>1</code>s.</p>

<p>The grid is said to be <strong>connected</strong> if we have <strong>exactly one&nbsp;island</strong>, otherwise is said <strong>disconnected</strong>.</p>

<p>In one day, we are allowed to change <strong>any </strong>single land cell <code>(1)</code> into a water cell <code>(0)</code>.</p>

<p>Return <em>the minimum number of days</em> to disconnect the grid.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/08/13/1926_island.png" style="width: 498px; height: 139px;"></strong></p>

<pre><strong>Input:</strong> grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1]]
<strong>Output:</strong> 2
<strong>Explanation: </strong>Grid of full water is also disconnected ([[1,1]] -&gt; [[0,0]]), 0 islands.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1,0,1,0]]
<strong>Output:</strong> 0
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,0,1,1],
&nbsp;              [1,1,1,1,1],
&nbsp;              [1,1,0,1,1],
&nbsp;              [1,1,0,1,1]]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,0,1,1],
&nbsp;              [1,1,1,1,1],
&nbsp;              [1,1,0,1,1],
&nbsp;              [1,1,1,1,1]]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= grid.length, grid[i].length &lt;= 30</code></li>
	<li><code>grid[i][j]</code>&nbsp;is <code>0</code> or <code>1</code>.</li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/1568.%20Minimum%20Number%20of%20Days%20to%20Disconnect%20Island/README.md
// Time: O((MN)^2)
// Space: O(MN)
class Solution {
public:
    int n, m, cnt = 0, dirs[5] = {1, 0, -1, 0, 1};
    
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis){
        vis[i][j] = 1;
        
        for (int d = 0; d < 4; d++){
            int r = i + dirs[d], c = j + dirs[d + 1];
            if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c] == 1)
                dfs(grid, r, c, vis);
        }
    }
    
    bool disCon(vector<vector<int>>& grid){
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int> (m));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1 && !vis[i][j]){
                    if (++cnt > 1)
                        return true;
                    dfs(grid, i, j, vis);
                }
            }
        return cnt == 0;
    }
    
    int minDays(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        if (disCon(grid))
            return 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1){
                    grid[i][j] = 0;
                    if (disCon(grid))
                        return 1;
                    grid[i][j] = 1;
                }

        
        return 2;
    }
};
```
