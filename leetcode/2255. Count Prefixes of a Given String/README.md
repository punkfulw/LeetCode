# [2255. Count Prefixes of a Given String (Easy)]([https://leetcode.com/problems/3sum-closest](https://leetcode.com/problems/count-prefixes-of-a-given-string/))

<p>You are given a string array words and a string s, where words[i] and s comprise only of lowercase English letters.</p>

<p>Return the number of strings in words that are a prefix of s.</p>

<p>A prefix of a string is a substring that occurs at the beginning of the string. A substring is a contiguous sequence of characters within a string.</p>


<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: words = ["a","b","c","ab","bc","abc"], s = "abc"
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
The strings in words which are a prefix of s = "abc" are:
"a", "ab", and "abc".
Thus the number of strings in words which are a prefix of s is 3.
</pre>

<p>&nbsp;</p>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: words = ["a","a"], s = "aa"
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
Both of the strings are a prefix of s. 
Note that the same string can occur multiple times in words, and it should be counted each time.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &nbsp;&lt;= words[i].length, s.length &nbsp;&lt;= 10</code></li>
	<li><code>words[i] and s consist of lowercase English letters only.</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/3sum-closest/
// Author: github.com/punkfulw
// Time: O(NS)
// Space: O(1)
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int res = 0;
        for (auto& w : words)
            res += s.find(w) == 0;
        return res; 
    }
};
```
