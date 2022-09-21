# [1139. Largest 1-Bordered Square (Medium)](https://leetcode.com/problems/largest-1-bordered-square/)

<p>Given a 2D <code>grid</code> of <code>0</code>s and <code>1</code>s, return the number of elements in&nbsp;the largest <strong>square</strong>&nbsp;subgrid that has all <code>1</code>s on its <strong>border</strong>, or <code>0</code> if such a subgrid&nbsp;doesn't exist in the <code>grid</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,1],[1,0,1],[1,1,1]]
<strong>Output:</strong> 9
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[1,1,0,0]]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= grid.length &lt;= 100</code></li>
	<li><code>1 &lt;= grid[0].length &lt;= 100</code></li>
	<li><code>grid[i][j]</code> is <code>0</code> or <code>1</code></li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)


## Solution 1. Prefix Sum for Row and Column

```cpp
// OJ: https://leetcode.com/problems/largest-1-bordered-square/
// Author: github.com/punkfulw
// Time: O(MNN)
// Space: O(MN)
class Solution {
public:
    bool check(vector<vector<int>> &prerow, vector<vector<int>> &precol, int i, int j, int len){
        int r1, r2, c1, c2;
        r1 = prerow[i][j + len - 1] - prerow[i][j - 1];
        r2 = prerow[i + len - 1][j + len - 1] - prerow[i + len - 1][j - 1];
        c1 = precol[i + len - 1][j] - precol[i - 1][j];
        c2 = precol[i + len - 1][j + len - 1] - precol[i - 1][j + len - 1];
        return r1 == len && r2 == len && 
               c1 == len && c2 == len;
    }
    
    
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), len = min(n, m);
        vector<vector<int>> prerow(n + 1, vector<int> (m + 1)), precol(n + 1, vector<int> (m + 1));
        
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                precol[i][j] = precol[i - 1][j] + grid[i - 1][j - 1];
                prerow[i][j] = prerow[i][j - 1] + grid[i - 1][j - 1];
            }
        }
        
        for (; len >= 1; len--)
            for (int i = 0; i < n - len + 1; i++)
                for (int j = 0; j < m - len + 1; j++)
                    if (check(prerow, precol, i + 1, j + 1, len))
                        return len * len;

        return len;
    }
};
```
