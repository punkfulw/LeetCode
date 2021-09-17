# [54. Spiral Matrix (Medium)](https://leetcode.com/problems/spiral-matrix/solution/)

<p>Given an m x n matrix, return all elements of the matrix in spiral order.</p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg">
<pre>
<strong>Input:</strong> matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> [1,2,3,6,9,8,7,4,5]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg">
<pre>
<strong>Input:</strong> matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
<strong>Output:</strong> [1,2,3,4,8,12,11,10,9,5,6,7]
</pre>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Spiral Matrix II (Medium)](https://leetcode.com/problems/spiral-matrix-ii/)
* [Spiral Matrix III (Medium)](https://leetcode.com/problems/spiral-matrix-iii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/spiral-matrix
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans(n*m);
        int r = 0, c = 0, d = 0;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < n * m; i++){
            ans[i] = mat[r][c];
            mat[r][c] = -101;
            int nextR = r + dir[d % 4][0];
            int nextC = c + dir[d % 4][1];
            if (nextR >= n || nextR < 0 || nextC >= m || nextC < 0 || mat[nextR][nextC] < -100)
                d++;
            r += dir[d % 4][0], c += dir[d % 4][1];
        }
        return ans;
    }
};
```

