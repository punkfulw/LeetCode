# [915. Partition Array into Disjoint Intervals (Medium)](https://leetcode.com/problems/partition-array-into-disjoint-intervals/)

<p>Given an array <code>nums</code>, partition it&nbsp;into two (contiguous) subarrays&nbsp;<code>left</code>&nbsp;and <code>right</code>&nbsp;so that:</p>

<ul>
	<li>Every element in <code>left</code>&nbsp;is less than or equal to every element in <code>right</code>.</li>
	<li><code>left</code> and <code>right</code> are non-empty.</li>
	<li><code>left</code>&nbsp;has the smallest possible size.</li>
</ul>

<p>Return the <strong>length</strong> of <code>left</code> after such a partitioning.&nbsp; It is guaranteed that such a partitioning exists.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[5,0,3,8,6]</span>
<strong>Output: </strong><span id="example-output-1">3</span>
<strong>Explanation: </strong>left = [5,0,3], right = [8,6]
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[1,1,1,0,6,12]</span>
<strong>Output: </strong><span id="example-output-2">4</span>
<strong>Explanation: </strong>left = [1,1,1,0], right = [6,12]
</pre>

<p>&nbsp;</p>
</div>

<p><strong>Note:</strong></p>

<ol>
	<li><code>2 &lt;= A.length&nbsp;&lt;= 30000</code></li>
	<li><code>0 &lt;= A[i] &lt;= 10^6</code></li>
	<li>It is guaranteed there is at least one way to partition <code>A</code> as described.</li>
</ol>

<div>
<div>&nbsp;</div>
</div>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/partition-array-into-disjoint-intervals/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int curmax = nums[0];
        int n = nums.size();
        vector<int> cnt = nums;
        int curmin = INT_MAX;
        for (int i = n-1; i >= 0; i--){
            curmin = min(curmin, cnt[i]);
            cnt[i] = curmin;
        }
        int i = 1;
        for (; i < n; i++){
            if (curmax <= cnt[i])
                break;
            curmax = max(curmax, nums[i]);
        }
        return i;
    }
};
```
