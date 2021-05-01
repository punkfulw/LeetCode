# [1380. Lucky Numbers in a Matrix (Easy)](https://leetcode.com/problems/lucky-numbers-in-a-matrix)

<p>Given a <code>m * n</code> matrix of <strong>distinct </strong>numbers, return all lucky numbers in the&nbsp;matrix in <strong>any </strong>order.</p>

<p>A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> matrix = [[3,7,8],[9,11,13],[15,16,17]]
<strong>Output:</strong> [15]
<strong>Explanation:</strong> 15 is the only lucky number since it is the minimum in its row and the maximum in its column
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
<strong>Output:</strong> [12]
<strong>Explanation:</strong> 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> matrix = [[7,8],[1,2]]
<strong>Output:</strong> [7]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= n, m &lt;= 50</code></li>
	<li><code>1 &lt;=&nbsp;matrix[i][j]&nbsp;&lt;= 10^5</code>.</li>
	<li>All elements in the matrix are distinct.</li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/lucky-numbers-in-a-matrix
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(M + N)
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        vector<int> minrow;
        vector<int> maxcol;
        
        for (int i = 0; i < matrix.size(); i++){
            int r = matrix[i][0];
            for (int j = 0; j < matrix[i].size(); j++){
                r = min(r, matrix[i][j]);
            }
            minrow.push_back(r);
        }
        
        for (int j = 0; j < matrix[0].size(); j++){
            int c = 0;
            for (int i = 0; i < matrix.size(); i++){
                c = max(c, matrix[i][j]);
            }
            maxcol.push_back(c);
        }
        for (int i = 0; i < minrow.size(); i++){
            for (int j = 0; j < maxcol.size(); j++){
                if (minrow[i] == maxcol[j]){
                    ans.push_back(minrow[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
```
