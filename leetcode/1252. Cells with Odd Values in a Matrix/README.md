# [1252. Cells with Odd Values in a Matrix (Easy)](https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/)

<p>Given&nbsp;<code>n</code>&nbsp;and&nbsp;<code>m</code>&nbsp;which are the dimensions of a matrix initialized by zeros and given an array <code>indices</code>&nbsp;where <code>indices[i] = [ri, ci]</code>. For each pair of <code>[ri, ci]</code>&nbsp;you have to increment all cells in row <code>ri</code> and column <code>ci</code>&nbsp;by 1.</p>

<p>Return <em>the number of cells with odd values</em> in the matrix after applying the increment to all <code>indices</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/10/30/e1.png" style="width: 600px; height: 118px;">
<pre><strong>Input:</strong> n = 2, m = 3, indices = [[0,1],[1,1]]
<strong>Output:</strong> 6
<strong>Explanation:</strong> Initial matrix = [[0,0,0],[0,0,0]].
After applying first increment it becomes [[1,2,1],[0,1,0]].
The final matrix will be [[1,3,1],[1,3,1]] which contains 6 odd numbers.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/10/30/e2.png" style="width: 600px; height: 150px;">
<pre><strong>Input:</strong> n = 2, m = 2, indices = [[1,1],[0,0]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Final matrix = [[2,2],[2,2]]. There is no odd number in the final matrix.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= m &lt;= 50</code></li>
	<li><code>1 &lt;= indices.length &lt;= 100</code></li>
	<li><code>0 &lt;= indices[i][0] &lt;&nbsp;n</code></li>
	<li><code>0 &lt;= indices[i][1] &lt;&nbsp;m</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> count(m, vector<int>(n, 0));
        int ans {};
        
        for (int i = 0; i < indices.size(); i++){
            int row = indices[i].at(0);
            int col = indices[i].at(1);
            for (int c = 0; c < n; c++)
                count[row][c]++;
            for (int r = 0; r < m; r++)
                count[r][col]++;
        }
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++)
                if(count[i][j] % 2 != 0)
                    ans++;
        }
        return ans;
    }
};
```
