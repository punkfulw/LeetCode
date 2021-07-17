# [64. Minimum Path Sum (Medium)](https://leetcode.com/problems/minimum-path-sum/)

<p>Given a <code>m x n</code> grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.</p>

<p><b>Note:</b> You can only move either down or right at any point in time.</p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> grid = [[1,3,1],[1,5,1],[4,2,1]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> grid = [[1,2,3],[4,5,6]]
<strong>Output:</strong> 12
</pre>

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>m == grid.length</code></li>
  <li><code>n == grid[i].length</code></li>
  <li><code>1 &lt;= m, n &lt;= 200/code></li>
  <li><code>0 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Unique Paths (Medium)](https://leetcode.com/problems/unique-paths/)
* [Dungeon Game (Hard)](https://leetcode.com/problems/dungeon-game/)
* [Cherry Pickup (Hard)](https://leetcode.com/problems/cherry-pickup/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/minimum-path-sum/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int minPathSum(vector<vector<int>>& dp) {
        int n = dp.size(), m = dp[0].size();
        for (int i = 1; i < n; i++)
            dp[i][0] += dp[i-1][0];
        for (int j = 1; j < m; j++)
            dp[0][j] += dp[0][j-1];
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};
```
