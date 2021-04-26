# [1653. Minimum Deletions to Make String Balanced (Medium)](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/)

<p>You are given a string <code>s</code> consisting only of characters <code>'a'</code> and <code>'b'</code>.</p>

<p>You can delete any number of characters in <code>s</code> to make <code>s</code> balanced. 
  <code>s</code> is balanced if there is no pair of indices <code>(i,j)</code> such that <code>i < j</code> and <code>s[i] = 'b'</code> and <code>s[j]= 'a'</code>.</p>

<p>Return <em>the <b>minimum</b> number of deletions needed to make <code>s</code> <b>balanced</b></em>.</p>

<p>&nbsp;</p>
<p><b>Example 1:</b></p>

<pre><b>Input:</b> s = "aababbab"
<b>Output:</b> 2
<b>Explanation:</b>
You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> s = "bbaaaaabb"
<b>Output:</b> 2
<b>Explanation:</b> The only solution is to delete the first two characters.
</pre>

<p>&nbsp;</p>

<p><b>Constrains:</b></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
  <li><code>s[i]</code> is <code>'a'</code> or <code>'b'.</code></li>
</ul>



<p>&nbsp;</p>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/) 


## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
// Author: github.com/punkfulw
//reference: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/discuss/935701/DP-solution-beats-100-with-explanation
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minimumDeletions(string s) {
        int cntb {};
        int ans {};
        for (char c: s){
            if (c == 'a')
                ans = min(++ans, cntb);
            else 
                cntb++;
        }
        return ans;
    }
};
```
