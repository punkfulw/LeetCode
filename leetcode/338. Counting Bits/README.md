# [338. Counting Bits (Easy)](https://leetcode.com/problems/counting-bits/)

<p>Given an integer <code>n</code>, return <em>an array ans of length </em><code>n + 1</code><em> such that for each</em> <code>i (0 <= i <= n)</code>,
  <code>ans[i]</code><em> is the <b>number of</b> </em><code>1</code><em><b>'s</b> in the binary representation of </em><code>i</code>.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input: </strong><span id="example-input-1-1">2</span>
<strong>Output: </strong><span id="example-output-1">[0,1,1]</span>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">5</span>
<strong>Output: </strong><code>[0,1,1,2,1,2]</code>
</pre>

<p><b>Follow up:</b></p>

<ul>
	<li>It is very easy to come up with a solution with run time <b>O(n*sizeof(integer))</b>. But can you do it in linear time <b>O(n)</b> /possibly in a single pass?</li>
	<li>Space complexity should be <b>O(n)</b>.</li>
	<li>Can you do it like a boss? Do it without using any builtin function like <b>__builtin_popcount</b> in c++ or in any other language.</li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Number of 1 Bits (Easy)](https://leetcode.com/problems/number-of-1-bits/)

## Solution 1. DP


```cpp
// OJ: https://leetcode.com/problems/counting-bits
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans (n+1, 0);
        for (int i = 1; i <= n; i++){
            ans[i] = ans[i & (i-1)] + 1;
        }
        return ans;
    }
};
```

