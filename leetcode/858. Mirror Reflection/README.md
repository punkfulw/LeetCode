# [858. Mirror Reflection (Medium)](https://leetcode.com/problems/mirror-reflection/)

<p>There is&nbsp;a special square room with mirrors on each of the four&nbsp;walls.&nbsp; Except for the southwest&nbsp;corner, there are receptors on each of the remaining corners, numbered <code>0</code>, <code>1</code>, and <code>2</code>.</p>

<p>The square room has walls of length <code>p</code>, and a laser ray from the southwest corner&nbsp;first meets the east wall at a distance <code>q</code>&nbsp;from the <code>0</code>th receptor.</p>

<p>Return the number of the receptor that the ray meets first.&nbsp; (It is guaranteed that the ray will meet&nbsp;a receptor eventually.)</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>p = <span id="example-input-1-1">2</span>, q = <span id="example-input-1-2">1</span>
<strong>Output: </strong><span id="example-output-1">2</span>
<strong>Explanation: </strong>The ray meets receptor 2 the first time it gets reflected back to the left wall.
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/18/reflection.png" style="width: 218px; height: 217px;">
</pre>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= p &lt;= 1000</code></li>
	<li><code>0 &lt;= q &lt;= p</code></li>
</ol>
</div>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1. Simulation


```cpp
// OJ: https://leetcode.com/problems/mirror-reflection/
// Author: github.com/punkfulw
// Time: O(P)
// Space: O(1)
class Solution {
public:
    int check(vector<vector<int>> &conner, vector<int> &start){
        int ans = -1;
        for (int i = 0; i < 3; i++)
            if (start == conner[i])
                ans = i;
        return ans;
    }
    int mirrorReflection(int p, int q) {
        int n = p, ans = -1, dir = 1;
        vector<vector<int>> conner = {{0, n}, {n, n}, {n, 0}};
        vector<int> start = {0, 0};

        while (ans == -1){
            start[1] = dir == 1 ? n : 0;
            if (start[0] + q > n || start[0] + q < 0){
                start[0] = start[0] + q > n ? n - (start[0] + q - n) : -(start[0] + q);
                q = -q;
            }
            else
                start[0] += q;

            dir = -dir;
            ans = check(conner, start);
        }
        return ans;
    }
};
```



