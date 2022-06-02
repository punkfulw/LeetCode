# [867. Transpose Matrix (Easy)](https://leetcode.com/problems/transpose-matrix/)

<p>Given a 2D integer array <code>matrix</code>, return <em>the <b>transpose</b> of</em> <code>matrix</code>.</p>

<p>The <b>transpose</b> of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.</p>

![image](https://assets.leetcode.com/uploads/2021/02/10/hint_transpose.png)

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> [[1,4,7],[2,5,8],[3,6,9]]
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> matrix = [[1,2,3],[4,5,6]]
<strong>Output:</strong> [[1,4],[2,5],[3,6]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>m == matrix.length</code></li>
  <li><code>n == matrix[i].length</code></li>
  <li><code>1 &lt;= m, n &lt;= 1000</code></li>
  <li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
  <li><code>-10<sup>9</sup> &lt;= matrix[i][j] &lt;= 10<sup>9</sup></code></li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)
## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/transpose-matrix/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix[0].size(), vector<int>(matrix.size()));
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
             ans[j][i] = matrix[i][j];   
            }
        }
        return ans;
    }
};
```

## Solution 1. -py

```python3
# OJ: https://leetcode.com/problems/transpose-matrix/
# Author: github.com/punkfulw
# Time: O(MN)
# Space: O(1)
class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        return list(zip(*matrix))
```

