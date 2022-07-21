# [125. Valid Palindrome (Easy)](https://leetcode.com/problems/valid-palindrome/)

<p>Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.</p>

<p><strong>Note:</strong>&nbsp;For the purpose of this problem, we define empty string as valid palindrome.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> "A man, a plan, a canal: Panama"
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> "race a car"
<strong>Output:</strong> false
</pre>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Palindrome Linked List (Easy)](https://leetcode.com/problems/palindrome-linked-list/)
* [Valid Palindrome II (Easy)](https://leetcode.com/problems/valid-palindrome-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/valid-palindrome/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isPalindrome(string S) {
        string s;
        for (auto c: S){
            if (isalpha(c))
                s += tolower(c);
            if (isdigit(c))
                s += c;
        }
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
};
```
