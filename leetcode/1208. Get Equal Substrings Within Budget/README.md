# [1208. Get Equal Substrings Within Budget (Medium)](https://leetcode.com/problems/get-equal-substrings-within-budget/)

<p>You are given two strings <code>s</code> and <code>t</code> of the same length. You want to change <code>s</code> to <code>t</code>. Changing the <code>i</code>-th character of <code>s</code> to <code>i</code>-th character of <code>t</code> costs <code>|s[i] - t[i]|</code> that is, the absolute difference between the ASCII values of the characters.</p>

<p>You are also given an integer <code>maxCost</code>.</p>

<p>Return the maximum length of a substring of <code>s</code> that can be changed to be the same as the corresponding substring of <code>t</code>with a cost less than or equal to <code>maxCost</code>.</p>

<p>If there is no substring from&nbsp;<code>s</code> that can be changed to its corresponding substring from <code>t</code>, return <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcd", t = "bcdf", maxCost = 3
<strong>Output:</strong> 3
<strong>Explanation: </strong>"abc" of s can change to "bcd". That costs 3, so the maximum length is 3.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abcd", t = "cdef", maxCost = 3
<strong>Output:</strong> 1
<strong>Explanation: </strong>Each character in s costs 2 to change to charactor in <code>t, so the maximum length is 1.</code>
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "abcd", t = "acde", maxCost = 0
<strong>Output:</strong> 1
<strong>Explanation: </strong>You can't make any change, so the maximum length is 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= maxCost &lt;= 10^6</code></li>
	<li><code>s</code> and&nbsp;<code>t</code> only contain lower case English letters.</li>
</ul>


**Companies**:  
[Traveloka](https://leetcode.com/company/traveloka)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

## Solution 1. Sliding Window

```cpp
// OJ: https://leetcode.com/problems/get-equal-substrings-within-budget/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0, cnt = maxCost;
        for (int p = 0, i = 0; i < s.size(); i++){
            int dif = abs(s[i] - t[i]);
            if (dif > maxCost){
                p = i + 1;
                cnt = maxCost;
                continue;
            }
            while (dif > cnt){
                cnt += abs(s[p] - t[p]);
                p++;
            }
            cnt -= dif;
            ans = max(ans, i - p + 1);
        }
        return ans;
    }
};
```



## Discuss

https://leetcode.com/problems/get-equal-substrings-within-budget/discuss/1529234/C%2B%2B-Sliding-Window-(%2B-Cheat-Sheet)
