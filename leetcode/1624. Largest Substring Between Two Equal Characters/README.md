# [1624. Largest Substring Between Two Equal Characters (Easy)](https://leetcode.com/problems/largest-substring-between-two-equal-characters/)

<p>Given a string <code>s</code>, return <em>the length of the longest substring between two equal characters, excluding the two characters.</em> If there is no such substring return <code>-1</code>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aa"
<strong>Output:</strong> 0
<strong>Explanation:</strong> The optimal substring here is an empty substring between the two <code>'a's</code>.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abca"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The optimal substring here is "bc".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "cbzxy"
<strong>Output:</strong> -1
<strong>Explanation:</strong> There are no characters that appear twice in s.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "cabbac"
<strong>Output:</strong> 4
<strong>Explanation:</strong> The optimal substring here is "abba". Other non-optimal substrings include "bb" and "".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 300</code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/largest-substring-between-two-equal-characters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size(), ans = -1;
        vector<vector<int>> rec(26, vector<int> (2, -1));
        for (int i = 0; i < n; i++){
            int c = s[i] - 'a';
            if (rec[c][0] != -1)
                rec[c][1] = i;
            else
                rec[c][0] = i;
        }
        
        for (int i = 0; i < 26; i++){
            if (rec[i][1] == -1)
                continue;
            ans = max(ans, rec[i][1] - rec[i][0] - 1);
        }
        return ans;
    }
};

```
