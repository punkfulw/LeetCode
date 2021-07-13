# [205. Isomorphic Strings (Easy)](https://leetcode.com/problems/isomorphic-strings/)

<p>Given two strings <code>s</code> and <code>t</code>, <em>determine if they are isomorphic</em>.</p>

<p>Two strings <code>s</code> and <code>t</code> are isomorphic if the characters in <code>s</code> can be replaced to get <code>t</code>.</p>

<p>All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s = "egg", t = "add"
<strong>Output:</strong> true
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s = "foo", t = "bar"
<strong>Output:</strong> false
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> s = "paper", t = "title"
<strong>Output:</strong> true
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>t.length == s.length</code></li>
	<li><code>s</code> and <code>t</code> consist of any valid ascii character.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Word Pattern (Easy)](https://leetcode.com/problems/word-pattern/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/isomorphic-strings/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/isomorphic-strings/discuss/57796/My-6-lines-solution
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
```


## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/isomorphic-strings/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/205.%20Isomorphic%20Strings/README.md
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m, r;
        for (int i = 0; i < s.size(); ++i) {
            if (m.count(s[i]) && m[s[i]] != t[i]) return false;
            if (r.count(t[i]) && r[t[i]] != s[i]) return false;
            m[s[i]] = t[i];
            r[t[i]] = s[i];
        }
        return true;
    }
};
```
