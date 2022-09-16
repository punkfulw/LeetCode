# [934. Shortest Bridge (Medium)](https://leetcode.com/problems/shortest-bridge/)

<p>In a given 2D binary array <code>grid</code>, there are two islands.&nbsp; (An island is a 4-directionally connected group of&nbsp;<code>1</code>s not connected to any other 1s.)</p>

<p>Now, we may change <code>0</code>s to <code>1</code>s so as to connect the two islands together to form 1 island.</p>

<p>Return the smallest number of <code>0</code>s that must be flipped.&nbsp; (It is guaranteed that the answer is at least 1.)</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> grid = [[0,1],[1,0]]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[0,1,0],[0,0,0],[0,0,1]]
<strong>Output:</strong> 2
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= grid.length == grid[0].length &lt;= 100</code></li>
	<li><code>grid[i][j] == 0</code> or <code>grid[i][j] == 1</code></li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Uber](https://leetcode.com/company/uber), [Bloomberg](https://leetcode.com/company/bloomberg), [Snapchat](https://leetcode.com/company/snapchat)

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. 2 BFS

```cpp
// OJ: https://leetcode.com/problems/shortest-bridge/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    #define pii pair<int, int>
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), step = 0, dirs[5] = {1, 0, -1, 0, 1}, done = 0;
        vector<vector<int>> vis(n, vector<int> (n));
        queue<pii> q1, q;
        for (int i = 0; i < n && !done; i++)
            for (int j = 0; j < n && !done; j++)
                if (grid[i][j] == 1){
                    q1.push({i, j});
                    vis[i][j] = 1;
                    while (!q1.empty()){
                        int sz = q1.size();
                        while (sz--){
                            auto [x, y] = q1.front();
                            q1.pop();
                            q.push({x, y});
                            for (int d = 0; d < 4; d++){
                                int r = x + dirs[d], c = y + dirs[d + 1];
                                if (r >= 0 && r < n && c >= 0 && c < n 
                                    && grid[r][c] == 1 && !vis[r][c]){
                                    q1.push({r, c});
                                    vis[r][c] = 1;
                                }
                            }
                        }
                    }
                    done = 1;
                }

        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++){
                    int r = x + dirs[d], c = y + dirs[d + 1];
                    if (r >= 0 && r < n && c >= 0 && c < n && !vis[r][c]){
                        if (grid[r][c] == 1)
                            return step;
                        q.push({r, c});
                        vis[r][c] = 1;
                    }
                }
            }
            step++;
        }
        return step;
    }
};



```
