# [459. Repeated Substring Pattern (Easy)](https://leetcode.com/problems/repeated-substring-pattern/)

<p>Given a string <code>s</code>, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abab"
<strong>Output:</strong> true
<strong>Explanation:</strong> It is the substring "ab" twice.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aba"
<strong>Output:</strong> false
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "abcabcabcabc"
<strong>Output:</strong> true
<strong>Explanation:</strong> It is the substring "abc" four times or the substring "abcabc" twice.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Salesforce](https://leetcode.com/company/salesforce)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [String Matching](https://leetcode.com/tag/string-matching/)

**Similar Questions**:
* [Implement strStr() (Easy)](https://leetcode.com/problems/implement-strstr/)
* [Repeated String Match (Medium)](https://leetcode.com/problems/repeated-string-match/)
* 
## Solution 1. Brute force

```cpp
// OJ: https://leetcode.com/problems/repeated-substring-pattern/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        string t;
        for (int i = 1; i <= n / 2; i++){
            t += s[i - 1];
            if (n % i)
                continue;
            int mul = n / i;
            string tmp = "";
            for (int j = 0; j < mul; j++)
                tmp += t;
            if (s == tmp)
                return true;
        }
        return false;
    }
};
```
