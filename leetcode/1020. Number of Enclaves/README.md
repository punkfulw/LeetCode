# [1020. Number of Enclaves (Medium)](https://leetcode.com/problems/number-of-enclaves/)

<p>Given a 2D array <code>A</code>, each cell is 0 (representing sea) or 1 (representing land)</p>

<p>A move consists of walking from one land square 4-directionally to another land square, or off the boundary of the grid.</p>

<p>Return the number of land squares in the grid for which we <strong>cannot</strong> walk off the boundary of the grid in any number of moves.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]</span>
<strong>Output: </strong><span id="example-output-1">3</span>
<strong>Explanation: </strong>
There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed because its on the boundary.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]</span>
<strong>Output: </strong><span id="example-output-2">0</span>
<strong>Explanation: </strong>
All 1s are either on the boundary or can reach the boundary.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 500</code></li>
	<li><code>1 &lt;= A[i].length &lt;= 500</code></li>
	<li><code>0 &lt;= A[i][j] &lt;= 1</code></li>
	<li>All rows have the same size.</li>
</ol>

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/number-of-enclaves/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int n, m, dirs[5] = {1, 0, -1, 0, 1}, ans = 0;
    
    bool dfs(vector<vector<int>>&grid, int i, int j, int &cnt){
        grid[i][j] = 0;
        cnt++;
        bool reach = 0;
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            reach = 1;
        for (int d = 0; d < 4; d++){
            int r = i + dirs[d], c = j + dirs[d + 1];
            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c])
                reach |= dfs(grid, r, c, cnt);
        }
        return reach;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    int cnt = 0;
                    bool reach = dfs(grid, i, j, cnt);
                    if (!reach)
                        ans += cnt;
                }
            }
        }
        return ans;
    }
};
```


## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/number-of-enclaves/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int n, m, dirs[5] = {1, 0, -1, 0, 1}, ans = 0;
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    int cnt = 0, reach = 0;
                    q.push({i, j});
                    grid[i][j] = 0;
                    while (!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();
                        cnt++;
                        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
                            reach = 1;
                        for (int d = 0; d < 4; d++){
                            int r = x + dirs[d], c = y + dirs[d + 1];
                            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c]){
                                grid[r][c] = 0;
                                q.push({r, c});
                            }
                        }
                    }
                    if (!reach)
                        ans += cnt;
                }
            }
        }
        return ans;
    }
};
```
