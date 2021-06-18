# [892. Surface Area of 3D Shapes (Easy)](https://leetcode.com/problems/surface-area-of-3d-shapes/)

<p>You are given an <code>n x n</code> grid where you have placed some <code>1 x 1 x 1</code> cubes. 
  Each value <code>v = grid[i][j]</code> represents a tower of v cubes placed on top of cell <code>(i, j)</code>.</p>

<p>After placing these cubes, you have decided to glue any directly adjacent cubes to each other, forming several irregular 3D shapes.</p>

<p>Return<em> the total surface area of the resulting shapes</em>.</p>

<p><b>Note:</b> The bottom face of each shape counts toward its surface area.</p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/08/tmp-grid1.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> grid = [[2]]
<strong>Output:</strong> 10
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/08/tmp-grid2.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> grid = [[1,2],[3,4]]
<strong>Output:</strong> 34
</pre>


<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/08/tmp-grid3.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> grid = [[1,0],[0,2]]
<strong>Output:</strong> 16
</pre>

<p><strong>Example 4:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/08/tmp-grid4.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> grid = [[1,1,1],[1,0,1],[1,1,1]]
<strong>Output:</strong> 32
</pre>


<p><strong>Example 5:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/08/tmp-grid5.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> grid = [[2,2,2],[2,1,2],[2,2,2]]
<strong>Output:</strong> 46
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>n == grid.length</code></li>
  <li><code>n == grid[i].length</code></li>
  <li><code>1 &lt;= n &lt;= 50</code></li>
  <li><code>0 &lt;= grid[i][j] &lt;= 50</code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Geometry](https://leetcode.com/tag/geometry/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/surface-area-of-3d-shapes/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int cur = grid[i][j];
                if (cur != 0){
                    ans += cnt_surface(cur);
                    if (j + 1 < n)
                        ans -= 2 * min(cur, grid[i][j+1]);
                    if (i + 1 < n)
                        ans -= 2 * min(cur, grid[i+1][j]);
                }
            }
        }
        return ans;
    }
    
    int cnt_surface(int n){
        if (n == 1)
            return 6;
        return (5 * 2) + (4 * (n - 2)); 
    }
};
```
