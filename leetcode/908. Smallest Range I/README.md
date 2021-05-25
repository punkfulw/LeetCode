# [908. Smallest Range I (Easy)](https://leetcode.com/problems/smallest-range-i/)

<p>Given an array <code>num</code> of integers, for each integer <code>num[i]</code> we may choose any <code>x</code> with <code>-k &lt;= x &lt;= k</code>, and add <code>x</code> to <code>num[i]</code>.</p>

<p>After this process, we have some array <code>result</code>.</p>

<p>Return the smallest possible difference between the maximum value of <code>result</code>&nbsp;and the minimum value of <code>result</code>.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>num = <span id="example-input-1-1">[1]</span>, k = <span id="example-input-1-2">0</span>
<strong>Output: </strong><span id="example-output-1">0
<strong>Explanation</strong>: B = [1]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>num = <span id="example-input-2-1">[0,10]</span>, k = <span id="example-input-2-2">2</span>
<strong>Output: </strong><span id="example-output-2">6
</span><span id="example-output-1"><strong>Explanation</strong>: B = [2,8]</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>num = <span id="example-input-3-1">[1,3,6]</span>, k = <span id="example-input-3-2">3</span>
<strong>Output: </strong><span id="example-output-3">0
</span><span id="example-output-1"><strong>Explanation</strong>: B = [3,3,3] or B = [4,4,4]</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= num.length &lt;= 10000</code></li>
	<li><code>0 &lt;= num[i] &lt;= 10000</code></li>
	<li><code>0 &lt;= k &lt;= 10000</code></li>
</ol>
</div>
</div>
</div>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/smallest-range-i/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxV = nums[0], minV = nums[0];
        
        for (int i: nums){
            maxV = max(maxV, i);
            minV = min(minV, i);
        }
        if (abs(maxV - minV) < (2 * k))
            return 0;
        else
            return abs(maxV - minV) - 2 * k;
    }
};
```
