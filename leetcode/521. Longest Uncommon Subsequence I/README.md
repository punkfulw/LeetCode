# [521. Longest Uncommon Subsequence I  (Easy)](https://leetcode.com/problems/longest-uncommon-subsequence-i/)

<p>
Given two strings a and b, return the length of the longest uncommon subsequence between a and b. If the longest uncommon subsequence does not exist, return -1.
</p>

<p>An uncommon subsequence between two strings is a string that is a subsequence of one but not the other.</p>

<p>
The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.
</p>

<il>
<li>For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).</li>
</il>

<p>A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.</p>
<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> "aba", "cdc"
<b>Output:</b> 3
<b>Explanation:</b> The longest uncommon subsequence is "aba" (or "cdc"), <br>because "aba" is a subsequence of "aba", <br>but not a subsequence of any other strings in the group of two strings. 
</pre>
<p></p>

<p><b>Note:</b>
</p>
<il>
<li>Both strings' lengths will not exceed 100.</li>
<li>Only letters from a ~ z will appear in input strings. </li>
</il>
<p></p>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Longest Uncommon Subsequence II (Medium)](https://leetcode.com/problems/longest-uncommon-subsequence-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-uncommon-subsequence-i/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.size(), b.size());
    }
};
```
