# [1684. Count the Number of Consistent Strings (Easy)](https://leetcode.com/problems/count-the-number-of-consistent-strings/)

<p>You are given a string <code>allowed</code> consisting of <b>distinct</b> characters and an array of strings <code>words</code>. 
  A string is <b>consistent</b> if all characters in the string appear in the string <code>allowed</code>.</p>

<p>Return <em>the number of <b>consistent</b> strings in the array <code>words</code>.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
<strong>Output:</strong> 7
<strong>Explanation:</strong> All strings are consistent.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Strings "cc", "acd", "ac", and "d" are consistent.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.

<ul>
	<li><code>1 &lt;= words.length &lt;= 104</code></li>
  <li><code>1 &lt;= allowed.length &lt;= 26</code></li>
  <li><code>1 &lt;= words[i].length &lt;= 10</code></li>
  <li>The characters in <code>allowed</code> are <b>distinct</b>.</li>
  <li><code>words[i]</code> and <code>allowed</code> contain only lowercase English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/count-the-number-of-consistent-strings/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = words.size();
        bool alpha[26] = {};
        for (char c: allowed) alpha[c - 'a'] = true;
        for (string word: words) {
            for (char c: word) if (!alpha[c - 'a']) {
                ans--;
                break;
            }
        }
        return ans;
    }
};
```
