# [994. Rotting Oranges (Medium)](https://leetcode.com/problems/rotting-oranges/)

<p>In a given grid, each cell can have one of three&nbsp;values:</p>

<ul>
	<li>the value <code>0</code> representing an empty cell;</li>
	<li>the value <code>1</code> representing a fresh orange;</li>
	<li>the value <code>2</code> representing a rotten orange.</li>
</ul>

<p>Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.</p>

<p>Return the minimum number of minutes that must elapse until no cell has a fresh orange.&nbsp; If this is impossible, return <code>-1</code> instead.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/02/16/oranges.png" style="width: 712px; height: 150px;"></strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[[2,1,1],[1,1,0],[0,1,1]]</span>
<strong>Output: </strong><span id="example-output-1">4</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[[2,1,1],[0,1,1],[1,0,1]]</span>
<strong>Output: </strong><span id="example-output-2">-1</span>
<strong>Explanation: </strong> The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[[0,2]]</span>
<strong>Output: </strong><span id="example-output-3">0</span>
<strong>Explanation: </strong> Since there are already no fresh oranges at minute 0, the answer is just 0.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= grid.length &lt;= 10</code></li>
	<li><code>1 &lt;= grid[0].length &lt;= 10</code></li>
	<li><code>grid[i][j]</code> is only <code>0</code>, <code>1</code>, or <code>2</code>.</li>
</ol>
</div>
</div>
</div>


**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Walls and Gates (Medium)](https://leetcode.com/problems/walls-and-gates/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/rotting-oranges/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int good = 0, n = grid.size(), m = grid[0].size(), mins = 0;
        queue<pair<int, int>> q;
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 0) continue;
                else if (grid[i][j] == 2) 
                    q.push({i, j});
                else good++;
            }
        }
        if (good == 0) return 0;
        while (!q.empty()){
            int k = q.size();
            for (int i = 0; i < k; i++){
                auto p = q.front(); q.pop();
                for (int i = 0; i < 4; i++){
                    int r = p.first + dir[i][0], c = p.second + dir[i][1];
                    if (r < n && r >= 0 && c < m && c >= 0 && grid[r][c] == 1){
                        q.push({r, c});
                        grid[r][c] = 2;
                        good--;
                    }
                }
            }
            mins++;
            if (good == 0) return mins;
        }
        return good == 0 ? mins : -1;
    }
};
```
