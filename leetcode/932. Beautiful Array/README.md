# [932. Beautiful Array (Medium)](https://leetcode.com/problems/beautiful-array/)

<p>For some fixed <code>N</code>, an array <code>A</code> is <em>beautiful</em> if it is a permutation of the integers <code>1, 2, ..., N</code>, such that:</p>

<p>For every <code>i &lt; j</code>, there is <strong>no</strong>&nbsp;<code>k</code> with <code>i &lt; k &lt; j</code>&nbsp;such that <code>A[k] * 2 = A[i] + A[j]</code>.</p>

<p>Given <code>N</code>, return <strong>any</strong> beautiful array <code>A</code>.&nbsp; (It is guaranteed that one exists.)</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">4</span>
<strong>Output: </strong><span id="example-output-1">[2,1,4,3]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">5</span>
<strong>Output: </strong><span>[3,1,2,5,4]</span></pre>

<p>&nbsp;</p>
</div>

<p><strong>Note:</strong></p>

<ul>
	<li><code>1 &lt;= N &lt;= 1000</code></li>
</ul>

<div>
<div>&nbsp;</div>
</div>

**Related Topics**:  
[Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/)

## Solution 1. odd + even


```cpp
// OJ: https://leetcode.com/problems/beautiful-array/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/beautiful-array/discuss/186679/Odd-%2B-Even-Pattern-O(N)
// Time: O(NlogN)
// Space: O(NlogN)
class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans = {1};
        
        while (ans.size() < n){
            vector<int>tmp;
            for (auto i: ans)
                if (2 * i - 1 <= n)
                    tmp.push_back(2 * i - 1);
            for (auto i: ans)
                if (2 * i <= n)
                    tmp.push_back(2 * i);
            ans = tmp;
        }
        return ans;
    }
};
```
