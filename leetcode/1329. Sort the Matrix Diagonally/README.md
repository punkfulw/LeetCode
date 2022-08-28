# [1329. Sort the Matrix Diagonally (Medium)](https://leetcode.com/problems/sort-the-matrix-diagonally/submissions/)

<p>A <strong>matrix diagonal</strong> is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the <strong>matrix diagonal</strong> starting from <code>mat[2][0]</code>, where <code>mat</code> is a <code>6 x 3</code> matrix, includes cells <code>mat[2][0]</code>, <code>mat[3][1]</code>, and <code>mat[4][2]</code>.</p>

<p>Given an <code>m x n</code> matrix <code>mat</code> of integers, sort each <strong>matrix diagonal</strong> in ascending order and return <em>the resulting matrix</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/01/21/1482_example_1_2.png" style="width: 500px; height: 198px;">
<pre><strong>Input:</strong> mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
<strong>Output:</strong> [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m ==&nbsp;mat.length</code></li>
	<li><code>n ==&nbsp;mat[i].length</code></li>
	<li><code>1 &lt;= m, n&nbsp;&lt;= 100</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 100</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sort](https://leetcode.com/tag/sort/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sort-the-matrix-diagonally/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/sort-the-matrix-diagonally/discuss/489749/JavaPython-Straight-Forward
// Time: O(MNlogD), where D is the length of diagonal with D = min(M,N).
// Space: O(MN)
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++)
                mp[i-j].push(mat[i][j]);
        }
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                mat[i][j] = mp[i-j].top();
                mp[i-j].pop();
            }
        }
        return mat;
    }
};
```

## Solution 2. 2022

```cpp
// OJ: https://leetcode.com/problems/sort-the-matrix-diagonally/
// Author: github.com/punkfulw
// Time: O((N + M)DlogD), where D is the length of diagonal with D = min(M,N).
// Space: O(D)
class Solution {
public:
    int n, m;
    
    void  sol(int i, int j, vector<vector<int>> &mat){
        vector<int> nums;
        int x = i, y = j, idx = 0;
        while (i < n && j < m)
            nums.push_back(mat[i++][j++]);
        sort(nums.begin(), nums.end());
        while (x < n && y < m)
            mat[x++][y++] = nums[idx++];
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        for (int i = n - 1; i >= 0; i--)
            sol(i, 0, mat);
        for (int j = 1; j < m; j++)
            sol(0, j, mat);
        return mat;
    }
};
```
