# [576. Out of Boundary Paths (Medium)](https://leetcode.com/problems/out-of-boundary-paths/)

<p>There is an <code>m x n</code> grid with a ball. The ball is initially at the position <code>[startRow, startColumn]</code>. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply <strong>at most</strong> <code>maxMove</code> moves to the ball.</p>

<p>Given the five integers <code>m</code>, <code>n</code>, <code>maxMove</code>, <code>startRow</code>, <code>startColumn</code>, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_1.png" style="width: 500px; height: 296px;">
<pre><strong>Input:</strong> m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
<strong>Output:</strong> 6
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_2.png" style="width: 500px; height: 293px;">
<pre><strong>Input:</strong> m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
<strong>Output:</strong> 12
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>0 &lt;= maxMove &lt;= 50</code></li>
	<li><code>0 &lt;= startRow &lt; m</code></li>
	<li><code>0 &lt;= startColumn &lt; n</code></li>
</ul>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Knight Probability in Chessboard (Medium)](https://leetcode.com/problems/knight-probability-in-chessboard/)

## Solution 1. DP Top-down
```cpp
// OJ: https://leetcode.com/problems/out-of-boundary-paths/
// Author: github.com/punkfulw
// Time: O(MNK)
// Space: O(MNK)
class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}}, MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    
    int dfs(int i, int j, int n, int m, int maxMove, int cnt){
        if (i < 0 || i >= n || j < 0 || j >= m)
            return 1;
        if (cnt == maxMove)
            return 0;
        if (dp[i][j][cnt] != -1)
            return dp[i][j][cnt];
        
        int ret = 0;
        for (int d = 0; d < 4; d++){
            int r = i + dirs[d][0], c = j + dirs[d][1];
            ret = (ret + dfs(r, c, n, m, maxMove, cnt + 1)) % MOD;
        }
        return dp[i][j][cnt] = ret;
    }
    int findPaths(int n, int m, int maxMove, int i, int j) {
        dp.resize(n, vector<vector<int>> (m, vector<int> (maxMove + 1, -1)));
        return dfs(i, j, n, m, maxMove, 0);
    }
};
```
