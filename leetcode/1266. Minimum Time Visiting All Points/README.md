# [1266. Minimum Time Visiting All Points (Easy)](https://leetcode.com/problems/minimum-time-visiting-all-points/)

<p>On a plane there are <code>n</code> points with integer coordinates <code>points[i] = [xi, yi]</code>. Your task is to find the minimum time in seconds to visit all points.</p>

<p>You can move according to the next rules:</p>

<ul>
	<li>In one second always you can either move vertically, horizontally by one unit or diagonally (it means to move one unit vertically and one unit horizontally in one second).</li>
	<li>You have to visit the points in the same order as they appear in the array.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/11/14/1626_example_1.PNG" style="width: 500px; height: 428px;">
<pre><strong>Input:</strong> points = [[1,1],[3,4],[-1,0]]
<strong>Output:</strong> 7
<strong>Explanation: </strong>One optimal path is <strong>[1,1]</strong> -&gt; [2,2] -&gt; [3,3] -&gt; <strong>[3,4] </strong>-&gt; [2,3] -&gt; [1,2] -&gt; [0,1] -&gt; <strong>[-1,0]</strong>   
Time from [1,1] to [3,4] = 3 seconds 
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> points = [[3,2],[-2,2]]
<strong>Output:</strong> 5
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>points.length == n</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 100</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-1000&nbsp;&lt;= points[i][0], points[i][1]&nbsp;&lt;= 1000</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Geometry](https://leetcode.com/tag/geometry/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-time-visiting-all-points/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans {};
        int size = points.size();
        
        for (int i = 0; i < size - 1; i++){
            int x1 = points[i].at(0);
            int y1 = points[i].at(1);
            int x2 = points[i+1].at(0);
            int y2 = points[i+1].at(1);
            
            ans += max(abs(x1 - x2), abs(y1 - y2));
        }
        return ans;
    }
};
```
