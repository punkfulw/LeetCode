# [329. Longest Increasing Path in a Matrix (Hard)](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)

<p>Given an <code>m x n</code> integers <code>matrix</code>, return <em>the length of the longest increasing path in </em><code>matrix</code>.</p>

<p>From each cell, you can either move in four directions: left, right, up, or down. You <strong>may not</strong> move <strong>diagonally</strong> or move <strong>outside the boundary</strong> (i.e., wrap-around is not allowed).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> matrix = [[9,9,4],[6,6,8],[2,1,1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest increasing path is <code>[1, 2, 6, 9]</code>.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/27/tmp-grid.jpg" style="width: 253px; height: 253px;">
<pre><strong>Input:</strong> matrix = [[3,4,5],[3,2,6],[2,2,1]]
<strong>Output:</strong> 4
<strong>Explanation: </strong>The longest increasing path is <code>[3, 4, 5, 6]</code>. Moving diagonally is not allowed.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> matrix = [[1]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= matrix[i][j] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Topological Sort](https://leetcode.com/tag/topological-sort/), [Memoization](https://leetcode.com/tag/memoization/)

# Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int dirs[5] = {1, 0, -1, 0, 1}, ans = 1, n, m;
    bool inbound(int i, int j){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    int dfs(int r, int c, vector<vector<int>>& length, vector<vector<int>>& mat){
        if (length[r][c])
            return length[r][c];
        int mxChildLen = 1;
         
        for (int k = 0; k < 4; k++){
            int i = r + dirs[k], j = c + dirs[k + 1], curChildLen = 1;
            if (inbound(i, j) && mat[i][j] > mat[r][c]){
                curChildLen += dfs(i, j, length, mat);   
                mxChildLen = max(mxChildLen, curChildLen);    
            }
            length[r][c] = mxChildLen;
        }         
        return length[r][c];
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        vector<vector<int>> length(n, vector<int> (m));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!length[i][j])
                    ans = max(ans, dfs(i, j, length, mat));
        
        return ans;
    }
};
```
