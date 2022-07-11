# [58. Length of Last Word (Easy)](https://leetcode.com/problems/length-of-last-word/)

<p>Given a string <i>s</i> consists of upper/lower-case alphabets and empty space characters <code>' '</code>, return the length of last word (last word means the last appearing word if we loop from left to right) in the string.</p>

<p>If the last word does not exist, return 0.</p>

<p><b>Note:</b> A word is defined as a <strong>maximal substring</strong> consisting&nbsp;of non-space characters only.</p>

<p><b>Example:</b></p>

<pre><b>Input:</b> "Hello World"
<b>Output:</b> 5
</pre>

<p>&nbsp;</p>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/length-of-last-word/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, pos = s.size() - 1;
        while (s[pos] == ' ')
            pos--;
        while (pos >= 0 && s[pos] != ' '){
            ans++;
            pos--;
        }
        return ans;
    }
};
```
