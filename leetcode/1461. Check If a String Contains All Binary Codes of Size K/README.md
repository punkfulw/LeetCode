# [1461. Check If a String Contains All Binary Codes of Size K (Medium)](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/)

<p>Given a binary string <code>s</code> and an integer <code>k</code>.</p>

<p>Return <em>True</em> if any binary code of length <code>k</code> is a substring of <code>s</code>. Otherwise, return <em>False</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "00110110", k = 2
<strong>Output:</strong> true
<strong>Explanation:</strong> The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indicies 0, 1, 3 and 2 respectively.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "00110", k = 2
<strong>Output:</strong> true
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "0110", k = 1
<strong>Output:</strong> true
<strong>Explanation:</strong> The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "0110", k = 2
<strong>Output:</strong> false
<strong>Explanation:</strong> The binary code "00" is of length 2 and doesn't exist in the array.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> s = "0000000001011100", k = 4
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10^5</code></li>
	<li><code>s</code> consists of 0's and 1's only.</li>
	<li><code>1 &lt;= k &lt;= 20</code></li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1. 


```cpp
// OJ: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(2^K)
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        long long fac = pow(2, k), n = s.size();
        if (fac > n - k + 1)
            return false;
        unordered_set<string> st;
        for (int i = 0; i < n - k + 1; i++){
            string cur = s.substr(i, k);
            st.insert(cur);
        }
        return st.size() == fac;
    }
};
```
