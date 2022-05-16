# [1091. Shortest Path in Binary Matrix (Medium)](https://leetcode.com/problems/shortest-path-in-binary-matrix/)

<p>In an N by N square grid, each cell is either empty (0) or blocked (1).</p>

<p>A&nbsp;<em>clear&nbsp;path from top-left to bottom-right</em>&nbsp;has length <code>k</code> if and only if it is composed of cells <code>C_1, C_2, ..., C_k</code>&nbsp;such that:</p>

<ul>
	<li>Adjacent cells <code>C_i</code> and <code>C_{i+1}</code> are connected 8-directionally (ie., they are different and&nbsp;share an edge or corner)</li>
	<li><code>C_1</code> is at location <code>(0, 0)</code> (ie. has value <code>grid[0][0]</code>)</li>
	<li><code>C_k</code>&nbsp;is at location <code>(N-1, N-1)</code> (ie. has value <code>grid[N-1][N-1]</code>)</li>
	<li>If <code>C_i</code> is located at&nbsp;<code>(r, c)</code>, then <code>grid[r][c]</code> is empty (ie.&nbsp;<code>grid[r][c] ==&nbsp;0</code>).</li>
</ul>

<p>Return the length of the shortest such clear path from top-left to bottom-right.&nbsp; If such a path does not exist, return -1.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[[0,1],[1,0]]
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/04/example1_1.png" style="width: 151px; height: 152px;">
</span>
<strong>Output: </strong>2
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/04/example1_2.png" style="width: 151px; height: 152px;">
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[[0,0,0],[1,1,0],[1,1,0]]
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/04/example2_1.png" style="width: 151px; height: 152px;">
</span>
<strong>Output:</strong> 4
<img alt="" src="https://assets.leetcode.com/uploads/2019/08/04/example2_2.png" style="width: 151px; height: 152px;">
</pre>

<p>&nbsp;</p>
</div>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= grid.length == grid[0].length &lt;= 100</code></li>
	<li><code>grid[r][c]</code> is <code>0</code> or <code>1</code></li>
</ol>


**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(Q)
class Solution {
public: 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), cnt = 1, ans = -1;
        if (grid[0][0] || grid[n-1][n-1]) return -1;
        queue<pair<int, int>> q;
        grid[0][0] = 1;
        q.push({0, 0});
        
        while (!q.empty() && ans == -1){
            int m = q.size();
            for (int i = 0; i < m; i++){
                auto [x, y] = q.front(); q.pop();
                if (x == n - 1 && y == n - 1){
                    ans = cnt;
                    break;
                }  
                for (int i = x - 1; i <= x + 1; i++)
                    for (int j = y - 1; j <= y + 1; j++)
                        if (i >= 0 && i < n && j >= 0 && j < n && !grid[i][j]){
                            grid[i][j] = 1;
                            q.push({i, j});
                        } 
            }
            cnt++;
        }
        return ans;
    }
};
```
