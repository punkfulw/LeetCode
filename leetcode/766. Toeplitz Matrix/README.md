# [766. Toeplitz Matrix (Easy)](https://leetcode.com/problems/toeplitz-matrix/)

<p>Given an <code>m x n</code> <code>matrix</code>, return <em><code>true</code> if the matrix is Toeplitz. Otherwise, return <code>false</code>.</em></p>

<p>A matrix is <b>Toeplitz</b> if every diagonal from top-left to bottom-right has the same elements.</p>

<p><strong>Example 1:</strong></p>

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/ex1.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
<strong>Output:</strong> True
<strong>Explanation:</strong>
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/ex2.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> matrix = [[1,2],[2,2]]
<strong>Output:</strong> False
<strong>Explanation:</strong>
The diagonal "[1, 2]" has different elements.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>m == matrix.length</code></li>
  <li><code>n == matrix[i].length</code></li>
  <li><code>1 &lt;= m, n &lt;= 20</code></li>
  <li><code>0 &lt;= matrix[i][j] &lt;= 99</code></li>
</ul>



<strong>Follow up:</strong></p>

<ol>
	<li>What if the <code>matrix</code> is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?</li>
	<li>What if the <code>matrix</code> is so large that you can only load up a partial row into the memory at once?</li>
</ol>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Valid Word Square (Easy)](https://leetcode.com/problems/valid-word-square/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/toeplitz-matrix/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size()-1; i++){
            for (int j = 0; j < matrix[0].size()-1; j++){
                if (matrix[i][j] != matrix[i+1][j+1])
                    return false;
            }
        }
        return true;
    }
};
```

## Solution 2. Table

```cpp
// OJ: https://leetcode.com/problems/toeplitz-matrix/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> d(40, -1);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                int index = i - j + 20;
                if (d[index] == -1)
                    d[index] = matrix[i][j];
                else{
                    if (d[index] != matrix[i][j])
                        return false;
                }
            }
        }
        return true;
    }
};
```
