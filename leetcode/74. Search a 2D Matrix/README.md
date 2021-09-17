# [74. Search a 2D Matrix (Medium)](https://leetcode.com/problems/search-a-2d-matrix/)

<p>Write an efficient algorithm that searches for a value in an <code>m x n</code> matrix. This matrix has the following properties:</p>

<ul>
	<li>Integers in each row are sorted from left to right.</li>
	<li>The first integer of each row is greater than the last integer of the previous row.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/mat.jpg" style="width: 322px; height: 242px;">
<pre><strong>Input:</strong> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg" style="width: 322px; height: 242px;">
<pre><strong>Input:</strong> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
<strong>Output:</strong> false
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> matrix = [], target = 0
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>0 &lt;= m, n &lt;= 100</code></li>
	<li><code>-10<sup>4</sup> &lt;= matrix[i][j], target &lt;= 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Search a 2D Matrix II (Medium)](https://leetcode.com/problems/search-a-2d-matrix-ii/)

## Solution 1. Binary Search

```cpp
// OJ: https://leetcode.com/problems/search-a-2d-matrix/
// Author: github.com/punkfulw
// Time: O(log(N)+log(M))
// Space: O(1)
class Solution {
public:
    bool findcol(vector<vector<int>>& mat, int target, int row) {
        int l = 0, r = mat[0].size() - 1;
        while (l <= r){
            int m = (l + r) / 2;
            if (mat[row][m] > target)
                r = m - 1;
            else if (mat[row][m] < target)
                l = m + 1;
            else
                return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int top = 0, bot = mat.size() - 1;
        int row = -1;
        while (top <= bot){
            int m = (top + bot) / 2;
            if (mat[m][0] < target){
                if (mat[m].back() >= target){
                    row = m;
                    break;
                }
                else
                    top = m + 1;
            }
            else if (mat[m][0] > target)
                bot = m - 1;   
            else 
                return true;
        }
        return row < 0 ? false : findcol(mat, target, row);
    }
};
```

## Solution 2. Binary Search

```cpp
// OJ: https://leetcode.com/problems/search-a-2d-matrix/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/74.%20Search%20a%202D%20Matrix/README.md
// Time: O(log(MN))
// Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size(), l = 0, r = m * n - 1;
        while (l <= r){
            int mid = (l + r) / 2;
            if (mat[mid / m][mid % m] < target)
                l = mid + 1;
            else if (mat[mid / m][mid % m] > target)
                r = mid - 1;
            else
                return true;
        }
        return false;
    }
};
```
