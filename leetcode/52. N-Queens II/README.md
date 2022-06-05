# [52. N-Queens II (Hard)](https://leetcode.com/problems/n-queens-ii/)

<p>The <strong>n-queens</strong> puzzle is the problem of placing <code>n</code> queens on an <code>n x n</code> chessboard such that no two queens attack each other.</p>

<p>Given an integer <code>n</code>, return <em>the number of distinct solutions to the&nbsp;<strong>n-queens puzzle</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/queens.jpg" style="width: 600px; height: 268px;">
<pre><strong>Input:</strong> n = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two distinct solutions to the 4-queens puzzle as shown.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 9</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Zenefits](https://leetcode.com/company/zenefits)

**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [N-Queens (Hard)](https://leetcode.com/problems/n-queens/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/n-queens-ii/
// Author: github.com/punkfulw
// Time: O(N!)
// Space: O(N)
class Solution {
public:
    vector<int> col, rdia, ldia;
    int dfs(int row, int n){
        if (row == n)
            return 1;
        int ans = 0;
        for (int j = 0; j < n; j++){
            if (!col[j] && !rdia[row + j] && !ldia[row - j + n - 1]){
                col[j] = rdia[row + j] = ldia[row - j + n - 1] = 1;
                ans += dfs(row + 1, n);
                col[j] = rdia[row + j] = ldia[row - j + n - 1] = 0;
            }
        }
        return ans;
    }
    
    int totalNQueens(int n) {
        col.resize(n), rdia.resize(2 * n - 1), ldia.resize(2 * n - 1);
        return dfs(0, n);
    }
};
```
