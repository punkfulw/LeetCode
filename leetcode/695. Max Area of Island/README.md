# [695. Max Area of Island (Medium)](https://leetcode.com/problems/max-area-of-island/)

<p>You are given an <code>m x n</code> binary matrix <code>grid</code>. 
  An island is a group of <code>1</code>'s (representing land) connected <b>4-directionally</b> (horizontal or vertical.) 
  You may assume all four edges of the grid are surrounded by water.</p>

<p>The <b>area</b> of an island is the number of cells with a value <code>1</code> in the island.</p>

<p>Return <em>the maximum area of an island in</em> <code>grid</code>. If there is no island, return <code>0</code>.</p>


<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/01/maxarea1-grid.jpg" style="width: 600px; height: 150px;">
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

## Solution 1. DFS

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
