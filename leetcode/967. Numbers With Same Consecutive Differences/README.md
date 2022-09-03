# [967. Numbers With Same Consecutive Differences (Medium)](https://leetcode.com/problems/numbers-with-same-consecutive-differences/)

<p>Return all <strong>non-negative</strong> integers of length <code>N</code> such that the absolute difference between every two consecutive digits is <code>K</code>.</p>

<p>Note that <strong>every</strong> number in the answer <strong>must not</strong> have leading zeros <strong>except</strong> for the number <code>0</code> itself. For example, <code>01</code> has one leading zero and is invalid, but <code>0</code> is valid.</p>

<p>You may return the answer in any order.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>N = <span id="example-input-1-1">3</span>, K = <span id="example-input-1-2">7</span>
<strong>Output: </strong><span id="example-output-1">[181,292,707,818,929]</span>
<strong>Explanation: </strong>Note that 070 is not a valid number, because it has leading zeroes.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>N = <span id="example-input-2-1">2</span>, K = <span id="example-input-2-2">1</span>
<strong>Output: </strong><span id="example-output-2">[10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]</span></pre>

<p>&nbsp;</p>
</div>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= N &lt;= 9</code></li>
	<li><code>0 &lt;= K &lt;= 9</code></li>
</ol>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/numbers-with-same-consecutive-differences/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int n, k;
    vector<int> ans;
        
    void dfs(int num, int pre, int sz){
        if (sz == n){
            ans.push_back(num);
            return;
        }
        for (int d = 0; d < 10; d++)
            if (abs(d - pre) == k)
                dfs(num * 10 + d, d, sz + 1);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        this->n = n;
        this->k = k;
        
        for (int i = 1; i < 10; i++)
            dfs(i, i, 1);
        
        return ans;
    }
};
```
