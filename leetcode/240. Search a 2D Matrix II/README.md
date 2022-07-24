# [240. Search a 2D Matrix II (Medium)](https://leetcode.com/problems/search-a-2d-matrix-ii/)

<p>Write an efficient algorithm that searches for a <code>target</code> value in an <code>m x n</code>&nbsp;integer <code>matrix</code>. The <code>matrix</code> has the following properties:</p>

<ul>
	<li>Integers in each row are sorted in ascending from left to right.</li>
	<li>Integers in each column are sorted in ascending from top to bottom.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/24/searchgrid2.jpg" style="width: 300px; height: 300px;">
<pre><strong>Input:</strong> matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/24/searchgrid.jpg" style="width: 300px; height: 300px;">
<pre><strong>Input:</strong> matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= n, m &lt;= 300</code></li>
	<li><code>-10<sup>9</sup> &lt;= matix[i][j] &lt;= 10<sup>9</sup></code></li>
	<li>All the integers in each row are <strong>sorted</strong> in ascending order.</li>
	<li>All the integers in each column are <strong>sorted</strong> in ascending order.</li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/)

**Similar Questions**:
* [Search a 2D Matrix (Medium)](https://leetcode.com/problems/search-a-2d-matrix/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/search-a-2d-matrix-ii/
// Author: github.com/punkfulw
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n = nums.size(), m = nums[0].size(), i = 0, j = m - 1;
        while (i < n && j >= 0){
            if (nums[i][j] == target)
                return true;
            else if (nums[i][j] < target)
                i++;
            else 
                j--;
        }
        return false;
    }
};
```

## Solution 2. bs

```cpp
// OJ: https://leetcode.com/problems/search-a-2d-matrix-ii/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int n, m;
    bool bs(int i, int j, vector<vector<int>>& nums, int target, int RorC){
        int l = 0, r = RorC == 0 ? n - 1 : m - 1;
        while (l <= r){
            int m = l + (r - l) / 2;      
            if (RorC){  
                if (nums[i][m] == target)
                    return true;
                else if (nums[i][m] < target)
                    l = m + 1;
                else 
                    r = m - 1;
            }
            else {
                if (nums[m][j] == target)
                    return true;
                else if (nums[m][j] < target)
                    l = m + 1;
                else 
                    r = m - 1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        this->n = nums.size(), this->m = nums[0].size();
        for (int i = 0; i < n; i++)
            if (bs(i, 0, nums, target, 1))
                return true;
        
        for (int i = 0; i < m; i++)
            if (bs(0, i, nums, target, 0))
                return true;
        return false;
    }
};
```
