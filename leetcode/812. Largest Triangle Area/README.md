# [812. Largest Triangle Area (Easy)](https://leetcode.com/problems/largest-triangle-area/)

<p>You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.</p>

<pre><strong>Example:</strong>
<strong>Input:</strong> points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
The five points are show in the figure below. The red triangle is the largest.
</pre>

<p><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/04/1027.png" style="height:328px; width:400px"></p>

<p><strong>Notes: </strong></p>

<ul>
	<li><code>3 &lt;= points.length &lt;= 50</code>.</li>
	<li>No points will be duplicated.</li>
	<li>&nbsp;<code>-50 &lt;= points[i][j] &lt;= 50</code>.</li>
	<li>Answers within&nbsp;<code>10^-6</code>&nbsp;of the true value will be accepted as correct.</li>
</ul>

<p>&nbsp;</p>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.  Math

```cpp
// OJ: https://leetcode.com/problems/largest-triangle-area/
// Author: github.com/punkfulw
// Time: O(N^3)
// Space: O(1)
// Ref: https://leetcode.com/problems/largest-triangle-area/solution/
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        
        for (auto &a: points)
            for (auto &b: points)
                for (auto &c: points)
                    ans = max(ans, 0.5 * abs(a[0] * b[1] + b[0] * c[1] + c[0] * a[1] -
                                             a[0] * c[1] - c[0] * b[1] - b[0] * a[1]));
        return ans;
    }
};

```
