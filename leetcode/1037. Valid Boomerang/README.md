# [1037. Valid Boomerang (Easy)](https://leetcode.com/problems/valid-boomerang)

<p>A <em>boomerang</em> is a set of 3 points that are all distinct and <strong>not</strong> in a straight line.</p>

<p>Given a list&nbsp;of three points in the plane, return whether these points are a boomerang.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[[1,1],[2,3],[3,2]]</span>
<strong>Output: </strong><span id="example-output-1">true</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[[1,1],[2,2],[3,3]]</span>
<strong>Output: </strong><span id="example-output-2">false</span></pre>
</div>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>points.length == 3</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 &lt;= points[i][j] &lt;= 100</code></li>
</ol>

<div>
<div>&nbsp;</div>
</div>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/valid-boomerang
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/valid-boomerang/discuss/286656/C%2B%2B-1-liner%3A-Triangle-Area
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& p) {
        return p[0][0] * (p[1][1] - p[2][1]) + p[1][0] * (p[2][1] - p[0][1]) + p[2][0] * (p[0][1] - p[1][1]);
    }
};
```
