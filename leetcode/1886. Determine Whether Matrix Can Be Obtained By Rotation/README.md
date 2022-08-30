# [1886. Determine Whether Matrix Can Be Obtained By Rotation (Easy)](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/)

<p>Given two <code>n x n</code> binary matrices <code>mat</code> and <code>target</code>, return <code>true</code><em> if it is possible to make </em><code>mat</code><em> equal to </em><code>target</code><em> by <strong>rotating</strong> </em><code>mat</code><em> in <strong>90-degree increments</strong>, or </em><code>false</code><em> otherwise.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/20/grid3.png" style="width: 301px; height: 121px;">
<pre><strong>Input:</strong> mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
<strong>Output:</strong> true
<strong>Explanation: </strong>We can rotate mat 90 degrees clockwise to make mat equal target.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/20/grid4.png" style="width: 301px; height: 121px;">
<pre><strong>Input:</strong> mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
<strong>Output:</strong> false
<strong>Explanation:</strong> It is impossible to make mat equal to target by rotating mat.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/26/grid4.png" style="width: 661px; height: 184px;">
<pre><strong>Input:</strong> mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
<strong>Output:</strong> true
<strong>Explanation: </strong>We can rotate mat 90 degrees clockwise two times to make mat equal target.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == mat.length == target.length</code></li>
	<li><code>n == mat[i].length == target[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>mat[i][j]</code> and <code>target[i][j]</code> are either <code>0</code> or <code>1</code>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Rotate Image (Medium)](https://leetcode.com/problems/rotate-image/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bool c[4];
        memset(c, true, sizeof(c));
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] != target[i][j]) c[0] = false;
                if (mat[n-j-1][i] != target[i][j]) c[1] = false;
                if (mat[n-i-1][n-j-1] != target[i][j]) c[2] = false;
                if (mat[j][n-i-1] != target[i][j]) c[3] = false;
            }
        }
        return (c[0] || c[1] || c[2] || c[3]);
    }
};
```


## Solution 2. rotate image

```cpp
// OJ: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    bool sol(vector<vector<int>>& mat, vector<vector<int>>& target){
        reverse(mat.begin(), mat.end());
        
        for (int i = 0; i < mat.size(); i++)
            for (int j = i + 1; j < mat.size(); j++)
                swap(mat[i][j], mat[j][i]);
        return mat == target;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool ans = 0;
        for (int i = 0; i < 4; i++){
            ans |= sol(mat, target);
        }
        return ans;
    }
};
```
