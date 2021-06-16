# [566. Reshape the Matrix (Easy)](https://leetcode.com/problems/reshape-the-matrix/)

<p>In MATLAB, there is a handy function called <code>reshape</code> which can reshape an <code>m x n</code> matrix into a new one with a different size <code>r x c</code> keeping its original data.</p>

<p>You are given an <code>m x n</code> matrix <code>mat</code> and two integers <code>r</code> and <code>c</code> representing the row number and column number of the wanted reshaped matrix.</p>

<p>The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.</p>

<p>If the <code>reshape</code> operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.</p>

<p><strong>Example 1:</strong></p>
<pre>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/reshape1-grid.jpg" style="width: 600px; height: 150px;">
<strong>Input:</strong> mat = [[1,2],[3,4]], r = 1, c = 4
<strong>Output:</strong> [[1,2,3,4]]
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/reshape2-grid.jpg" style="width: 600px; height: 150px;">
<strong>Input:</strong> mat = [[1,2],[3,4]], r = 2, c = 4
<strong>Output:</strong> [[1,2],[3,4]]
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>m == mat.length</code></li>
  <li><code>n == mat[i].length</code></li>
  <li><code>1 &lt;= m, n &lt;= 100</code></li>
  <li><code>-1000 &lt;= mat[i][j] &lt;= 1000</code></li>
  <li><code>1 &lt;= r, c &lt;= 300</code></li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/)
## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reshape-the-matrix/
// Author: github.com/punkfulw
// Time: O(N*M)
// Space: O(r*c)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        if (r * c != n * m)
            return mat;
        vector<vector<int>> ans(r, vector<int>(c));
        int row = 0, col = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                ans[row][col++] = mat[i][j];
                if (col == c){
                    col = 0;
                    row++;
                }
            }
        }
        return ans;
    }
};
```
