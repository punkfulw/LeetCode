# [51. N-Queens (Hard)](https://leetcode.com/problems/n-queens/)

<p>The <strong>n-queens</strong> puzzle is the problem of placing <code>n</code> queens on an <code>n x n</code> chessboard such that no two queens attack each other.</p>

<p>Given an integer <code>n</code>, return <em>all distinct solutions to the <strong>n-queens puzzle</strong></em>.</p>

<p>Each solution contains a distinct board configuration of the n-queens' placement, where <code>'Q'</code> and <code>'.'</code> both indicate a queen and an empty space, respectively.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/queens.jpg" style="width: 600px; height: 268px;">
<pre><strong>Input:</strong> n = 4
<strong>Output:</strong> [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
<strong>Explanation:</strong> There exist two distinct solutions to the 4-queens puzzle as shown above
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> [["Q"]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 9</code></li>
</ul>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [N-Queens II (Hard)](https://leetcode.com/problems/n-queens-ii/)
* [Grid Illumination (Hard)](https://leetcode.com/problems/grid-illumination/)

## Solution 1. Backtracking

```cpp
// OJ: https://leetcode.com/problems/n-queens/
// Author: github.com/punkfulw
// Time: O(N!)
// Space: O(N^2)
class Solution {
public:
    int n;
    vector<vector<string>> ans;
    vector<bool> rdia, ldia, row, col;
    
    void dfs(int i, vector<string>& cur){  
        if (i == n){
            ans.push_back(cur);
            return;
        }
        for (int c = 0; c < n; c++){
            if (!col[c] && !rdia[i + c] && !ldia[i - c + n - 1]){
                col[c] = rdia[i + c] = ldia[i - c + n - 1] = 1;
                cur[i][c] = 'Q';
                dfs(i + 1, cur);
                col[c] = rdia[i + c] = ldia[i - c + n - 1] = 0;
                cur[i][c] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int N) {
        n = N;
        rdia.resize(2 * n - 1, 0);
        ldia.resize(2 * n - 1, 0);
        row.resize(n, 0);
        col.resize(n, 0);
        vector<string> cur(n, string(n, '.'));
        
        dfs(0, cur);
        return ans;
    }
};
```
