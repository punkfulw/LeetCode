# [695. Max Area of Island (Medium)](https://leetcode.com/problems/max-area-of-island/)

<p>You are given an <code>m x n</code> binary matrix <code>grid</code>. 
  An island is a group of <code>1</code>'s (representing land) connected <b>4-directionally</b> (horizontal or vertical.) 
  You may assume all four edges of the grid are surrounded by water.</p>

<p>The <b>area</b> of an island is the number of cells with a value <code>1</code> in the island.</p>

<p>Return <em>the maximum area of an island in</em> <code>grid</code>. If there is no island, return <code>0</code>.</p>


<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/01/maxarea1-grid.jpg">
<pre>
<strong>Input:</strong> grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,1,1,0,1,0,0,0,0,0,0,0,0],
[0,1,0,0,1,1,0,0,1,0,1,0,0],
[0,1,0,0,1,1,0,0,1,1,1,0,0],
[0,0,0,0,0,0,0,0,0,0,1,0,0],
[0,0,0,0,0,0,0,1,1,1,0,0,0],
[0,0,0,0,0,0,0,1,1,0,0,0,0]]
<strong>Output:</strong> 6
<strong>Explanation: </strong> The answer is not 11, because the island must be connected 4-directionally.
</pre>


<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> grid = [[0,0,0,0,0,0,0,0]]
<strong>Output:</strong> 0
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>m == grid.length</code></li>
  <li><code>n == grid[i].length</code></li>
  <li><code>1 &lt;= m, n &lt;= 50</code></li>
  <li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Affirm](https://leetcode.com/company/affirm), [Amazon](https://leetcode.com/company/amazon), [Qualtrics](https://leetcode.com/company/qualtrics), [Facebook](https://leetcode.com/company/facebook), [Uber](https://leetcode.com/company/uber), [DoorDash](https://leetcode.com/company/doordash)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Number of Islands (Medium)](https://leetcode.com/problems/number-of-islands/)
* [Island Perimeter (Easy)](https://leetcode.com/problems/island-perimeter/)

## Solution 1. DFS -ver.2021

```cpp
// OJ: https://leetcode.com/problems/max-area-of-island/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    int cur = dfs(i, j, grid);
                    ans = max(ans, cur);
                }
            }
        }
        return ans;
    }
    
    int dfs(int i, int j, vector<vector<int>>& grid){
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {
            grid[i][j] = -1;
            return 1 + dfs(i-1, j, grid) + dfs(i+1, j, grid) + dfs(i, j-1, grid) + dfs(i, j+1, grid);
        }
        return 0;
    }
};
```

## Solution 1. DFS -ver.2022

```cpp
// OJ: https://leetcode.com/problems/max-area-of-island/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int n, m, ans = 0;
    int dirs[5] = {1, 0, -1, 0, 1};
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        int cur = 1;
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++)
        {
            int r = i + dirs[k], c = j + dirs[k + 1];
            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c])
                cur += dfs(r, c, grid);
        }
        return cur;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    ans = max(ans, dfs(i, j, grid));  
        
        return ans;
    }
};
```

## Solution 1. DFS -ver.2022 -py

```python3
# OJ: https://leetcode.com/problems/max-area-of-island/
# Author: github.com/punkfulw
# Time: O(MN)
# Space: O(MN)
class Solution:
    def dfs(self, i, j, grid):
        grid[i][j] = 0
        cur = 1
        for k in range(4):
            x, y = i + self.dirs[k], j + self.dirs[k + 1]
            if x >= 0 and x < self.n and y >= 0 and y < self.m and grid[x][y]:
                cur += self.dfs(x, y, grid)
        return cur
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.n, self.m = len(grid), len(grid[0])
        self.dirs = [0, 1, 0, -1, 0]
        ans = 0       
        for i in range(self.n):
            for j in range(self.m):
                if grid[i][j]:
                    ans = max(ans, self.dfs(i, j, grid))
        return ans
```
