# [883. Projection Area of 3D Shapes (Easy)](https://leetcode.com/problems/projection-area-of-3d-shapes/)

<p>On a&nbsp;<code>N&nbsp;*&nbsp;N</code> grid, we place some&nbsp;<code>1 * 1 * 1&nbsp;</code>cubes that are axis-aligned with the x, y, and z axes.</p>

<p>Each value&nbsp;<code>v = grid[i][j]</code>&nbsp;represents a tower of&nbsp;<code>v</code>&nbsp;cubes placed on top of grid cell <code>(i, j)</code>.</p>

<p>Now we view the&nbsp;<em>projection</em>&nbsp;of these cubes&nbsp;onto the xy, yz, and zx planes.</p>

<p>A projection is like a shadow, that&nbsp;maps our 3 dimensional figure to a 2 dimensional plane.&nbsp;</p>

<p>Here, we are viewing the "shadow" when looking at the cubes from the top, the front, and the side.</p>

<p>Return the total area of all three projections.</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[[2]]</span>
<strong>Output: </strong><span id="example-output-1">5</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[[1,2],[3,4]]</span>
<strong>Output: </strong><span id="example-output-2">17</span>
<strong>Explanation: </strong>
Here are the three projections ("shadows") of the shape made with each axis-aligned plane.
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/02/shadow.png" style="width: 749px; height: 200px;">
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[[1,0],[0,2]]</span>
<strong>Output: </strong><span id="example-output-3">8</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong><span id="example-input-4-1">[[1,1,1],[1,0,1],[1,1,1]]</span>
<strong>Output: </strong><span id="example-output-4">14</span>
</pre>

<div>
<p><strong>Example 5:</strong></p>

<pre><strong>Input: </strong><span id="example-input-5-1">[[2,2,2],[2,1,2],[2,2,2]]</span>
<strong>Output: </strong><span id="example-output-5">21</span>
</pre>

<p>&nbsp;</p>

<div>
<div>
<div>
<p><span><strong>Note:</strong></span></p>

<ul>
	<li><code>1 &lt;= grid.length = grid[0].length&nbsp;&lt;= 50</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 50</code></li>
</ul>
</div>
</div>
</div>
</div>
</div>
</div>
</div>
</div>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/projection-area-of-3d-shapes/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int x, y;
        
        for (int i = 0; i < n; i++){
            x = 0; y = 0;
            for (int j = 0; j < n; j++){
                x = max(x, grid[i][j]);
                y = max(y, grid[j][i]);
                if (grid[i][j]) ans++;
            }
            ans += x + y;
        }
        return ans;
    }
};

```
