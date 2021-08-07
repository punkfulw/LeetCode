# [409. Longest Palindrome (Easy)](https://leetcode.com/problems/longest-palindrome/)

<p>Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.</p>

<p>This is case sensitive, for example <code>"Aa"</code> is not considered a palindrome here.</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> s = "abccccdd"
<strong>Output:</strong> 7
<strong>Explanation:</strong> 
One longest palindrome that can be built is "dccaccd", whose length is 7.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> s = "a"
<strong>Output:</strong> 1
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> s = "bb"
<strong>Output:</strong> 2
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= s.length &lt;= 2000</code></li>
  <li><code>s</code> consists of lowercase and/or uppercase English letters only.</li>
</ul>

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [Palindrome Permutation (Easy)](https://leetcode.com/problems/palindrome-permutation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-palindrome/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1) because there are at most 52 unique characters
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (auto c: s)
            mp[c]++;
        bool ones = false;
        int ans = 0;
        for (auto p: mp){
            if (p.second % 2 == 0)
                ans += p.second;
            else{
                ones = true;
                ans += (p.second / 2) * 2;
            }
        }
        ans += ones;
        return ans;
    }
};
```
