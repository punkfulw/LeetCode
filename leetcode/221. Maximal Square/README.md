# [221. Maximal Square (Medium)](https://leetcode.com/problems/maximal-square/)

<p>Given an <code>m x n</code> binary <code>matrix</code> filled with <code>0</code>'s and <code>1</code>'s, <em>find the largest square containing only</em> <code>1</code>'s <em>and return its area</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/26/max1grid.jpg" style="width: 400px; height: 319px;">
<pre><strong>Input:</strong> matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/26/max2grid.jpg" style="width: 165px; height: 165px;">
<pre><strong>Input:</strong> matrix = [["0","1"],["1","0"]]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> matrix = [["0"]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>matrix[i][j]</code> is <code>'0'</code> or <code>'1'</code>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Visa](https://leetcode.com/company/visa), [Microsoft](https://leetcode.com/company/microsoft), [IBM](https://leetcode.com/company/ibm), [Google](https://leetcode.com/company/google), [Twitter](https://leetcode.com/company/twitter), [Apple](https://leetcode.com/company/apple), [Booking.com](https://leetcode.com/company/bookingcom), [Indeed](https://leetcode.com/company/indeed)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Maximal Rectangle (Hard)](https://leetcode.com/problems/maximal-rectangle/)
* [Largest Plus Sign (Medium)](https://leetcode.com/problems/largest-plus-sign/)

## Solution 1. dp

```cpp
// OJ: https://leetcode.com/problems/maximal-square/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:  
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size(), ans = 0;
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                dp[i + 1][j + 1] = mat[i][j] == '1' ? 1 : 0;
                if (mat[i][j] == '1')
                    dp[i + 1][j + 1] = min({dp[i][j + 1], dp[i][j], dp[i + 1][j]}) + 1;
                ans = max(ans, dp[i + 1][j + 1]);
            }
        }
        return ans * ans;
    }
};
```



