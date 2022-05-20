# [63. Unique Paths II (Medium)](https://leetcode.com/problems/unique-paths-ii/)

<p>A robot is located at the top-left corner of a <code>m x n</code> grid (marked 'Start' in the diagram below).</p>

<p>The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).</p>

<p>Now consider if some obstacles are added to the grids. How many unique paths would there be?</p>

<p>An obstacle and space is marked as <code>1</code> and <code>0</code> respectively in the grid.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -&gt; Right -&gt; Down -&gt; Down
2. Down -&gt; Down -&gt; Right -&gt; Right
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg" style="width: 162px; height: 162px;">
<pre><strong>Input:</strong> obstacleGrid = [[0,1],[0,0]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m ==&nbsp;obstacleGrid.length</code></li>
	<li><code>n ==&nbsp;obstacleGrid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>obstacleGrid[i][j]</code> is <code>0</code> or <code>1</code>.</li>
</ul>

**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Mathworks](https://leetcode.com/company/mathworks), [Bloomberg](https://leetcode.com/company/bloomberg), [GoDaddy](https://leetcode.com/company/godaddy), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Lyft](https://leetcode.com/company/lyft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Unique Paths (Medium)](https://leetcode.com/problems/unique-paths/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/unique-paths-ii/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int n, m, ans = 0;
    int rec[100][100] {};
    
    int dfs(int r, int c, vector<vector<int>>& grid){
        if (grid[r][c])
            return 0;
        
        if (rec[r][c] || (r == n - 1 && c == m - 1)){
            ans += rec[r][c];
            return rec[r][c];
        }
        if (r + 1 < n)
            rec[r][c] += dfs(r + 1, c, grid);
        if (c + 1 < m)
            rec[r][c] += dfs(r, c + 1, grid);
        return rec[r][c];           
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        rec[n - 1][m - 1] = 1;
        dfs(0, 0, grid);
        
        
        return ans;
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/unique-paths-ii/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rec[101][101] {};
        int n = grid.size(), m = grid[0].size();
        rec[0][1] = 1;
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (!grid[i - 1][j - 1])
                    rec[i][j] += rec[i - 1][j] + rec[i][j - 1];
 
        
        return rec[n][m];
    }
};
```

## Solution 3. DP

```cpp
// OJ: https://leetcode.com/problems/unique-paths-ii/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rec[100] {};
        int n = grid.size(), m = grid[0].size();
        rec[0] = 1;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j])
                    rec[j] = 0;
                else if (j > 0)
                    rec[j] += rec[j - 1];
        return rec[m - 1];
    }
};
```
