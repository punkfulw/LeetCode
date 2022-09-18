# [941. Valid Mountain Array (Easy)](https://leetcode.com/problems/valid-mountain-array/)

<p>Given an array <code>A</code> of integers, return <code>true</code> if and only if it is a <em>valid mountain array</em>.</p>

<p>Recall that A is a mountain array if and only if:</p>

<ul>
	<li><code>A.length &gt;= 3</code></li>
	<li>There exists some <code>i</code> with&nbsp;<code>0 &lt; i&nbsp;&lt; A.length - 1</code>&nbsp;such that:
	<ul>
		<li><code>A[0] &lt; A[1] &lt; ... A[i-1] &lt; A[i] </code></li>
		<li><code>A[i] &gt; A[i+1] &gt; ... &gt; A[B.length - 1]</code></li>
	</ul>
	</li>
</ul>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[2,1]</span>
<strong>Output: </strong><span id="example-output-1">false</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[3,5,5]</span>
<strong>Output: </strong><span id="example-output-2">false</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[0,3,2,1]</span>
<strong>Output: </strong><span id="example-output-3">true</span></pre>
</div>
</div>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>0 &lt;= A.length &lt;= 10000</code></li>
	<li><code>0 &lt;= A[i] &lt;= 10000&nbsp;</code></li>
</ol>

<div>
<p>&nbsp;</p>

<div>
<div>&nbsp;</div>
</div>
</div>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1. Two pointers

```cpp
// OJ: https://leetcode.com/problems/valid-mountain-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int l = 0, n = arr.size(), r = n - 1;
        while (l < n - 1 && arr[l + 1] > arr[l])
            l++;
        while(r - 1 >= 0 && arr[r - 1] > arr[r])
            r--;
        return l != 0 && r != n - 1 && l == r;
    }
};
```
