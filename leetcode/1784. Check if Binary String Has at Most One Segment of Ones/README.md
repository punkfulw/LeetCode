# [1784. Check if Binary String Has at Most One Segment of Ones (Easy)](https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/)

<p>Given a binary string <code>s</code> <strong>​​​​​without leading zeros</strong>, return <code>true</code>​​​ <em>if </em><code>s</code><em> contains <strong>at most one contiguous segment of ones</strong></em>. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "1001"
<strong>Output:</strong> false
<strong>Explanation: </strong>The ones do not form a contiguous segment.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "110"
<strong>Output:</strong> true</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s[i]</code>​​​​ is either <code>'0'</code> or <code>'1'</code>.</li>
	<li><code>s[0]</code> is&nbsp;<code>'1'</code>.</li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkOnesSegment(string s) {
        int flag = 0;
        for (int i = 1; i < s.size(); i++){
            if (s[i] == '0')
                flag = 1;
            else
                if (flag)
                    return 0;
        }
        return 1;
    }
};
```
