# [680. Valid Palindrome II (Easy)](https://leetcode.com/problems/valid-palindrome-ii/)

<p>
Given a non-empty string <code>s</code>, you may delete <b>at most</b> one character.  Judge whether you can make it a palindrome.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> "aba"
<b>Output:</b> True
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> "abca"
<b>Output:</b> True
<b>Explanation:</b> You could delete the character 'c'.
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The string will only contain lowercase characters a-z.
The maximum length of the string is 50000.</li>
</ol>
<p></p>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Valid Palindrome (Easy)](https://leetcode.com/problems/valid-palindrome/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/valid-palindrome-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool check(int l, int r, string s)
    {
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++; r--;
                continue;
            }
            return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++; r--;
                continue;
            }  
            return check(l, r-1, s) || check(l+1, r, s);
        }
        return true;
    }
};
```
