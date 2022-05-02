# [200. Number of Islands (Medium)](https://leetcode.com/problems/number-of-islands/)

<p>Given a 2d grid map of <code>'1'</code>s (land) and <code>'0'</code>s (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.</p>

<p><b>Example 1:</b></p>

<pre><strong>Input:</strong>
11110
11010
11000
00000

<strong>Output:</strong>&nbsp;1
</pre>

<p><b>Example 2:</b></p>

<pre><strong>Input:</strong>
11000
11000
00100
00011

<strong>Output: </strong>3
</pre>

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/)

**Similar Questions**:
* [Surrounded Regions (Medium)](https://leetcode.com/problems/surrounded-regions/)
* [Walls and Gates (Medium)](https://leetcode.com/problems/walls-and-gates/)
* [Number of Islands II (Hard)](https://leetcode.com/problems/number-of-islands-ii/)
* [Number of Connected Components in an Undirected Graph (Medium)](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)
* [Number of Distinct Islands (Medium)](https://leetcode.com/problems/number-of-distinct-islands/)
* [Max Area of Island (Medium)](https://leetcode.com/problems/max-area-of-island/)


## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/number-of-islands/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int n, m, ans = 0;
    int dirs[5] = {1, 0, -1, 0, 1};
    
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        grid[i][j] = '0';
        for (int k = 0; k < 4; k++)
        {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1')
                dfs(x, y, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1')
                {
                    ans++;
                    dfs(i, j, grid);
                }

        return ans;
    }
};
```

## Solution 1. DFS -py

```python3
# OJ: https://leetcode.com/problems/number-of-islands/
# Author: github.com/punkfulw
# Time: O(MN)
# Space: O(MN)
class Solution:
    def dfs(self, i, j, grid):
        grid[i][j] = "0"
        for k in range(4):
            x, y = i + self.dirs[k], j + self.dirs[k + 1]
            if x >= 0 and x < self.n and y >= 0 and y < self.m and grid[x][y] == "1":
                self.dfs(x, y, grid)
    def numIslands(self, grid: List[List[str]]) -> int:
        self.n, self.m = len(grid), len(grid[0])
        self.dirs = [0, 1, 0, -1, 0]
        ans = 0
        for i in range(self.n):
            for j in range(self.m):
                if grid[i][j] == "1":
                    ans += 1
                    self.dfs(i, j, grid)
        return ans
```
