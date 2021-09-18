# [383. Ransom Note (Easy)](https://leetcode.com/problems/ransom-note/)

<p>
Given two stings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.</p>
<p>
Each letter in magazine can only be used once in ransomNote.
</p>



<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> ransomNote = "a", magazine = "b"
<strong>Output:</strong> false
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> ransomNote = "aa", magazine = "ab"
<strong>Output:</strong> false
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> ransomNote = "aa", magazine = "aab"
<strong>Output:</strong> true
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= ransomNote.length, magazine.length &lt;= 10<sup>5</sup></code></li>
  <li><code>ransomNote and magazine consist of lowercase English letters.</code></li>
</ul>



**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Stickers to Spell Word (Hard)](https://leetcode.com/problems/stickers-to-spell-word/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/ransom-note/
// Author: github.com/punkfulw
// Time: O(M)
// Space: O(1)
class Solution {
public:
    bool canConstruct(string r, string m) {
        int cnt[26] = {};
        for (auto c: m)
            cnt[c - 'a']++;
        for (auto c: r){
            if (cnt[c - 'a'] <= 0)
                return false;
            cnt[c - 'a']--;
        }
        return true;
    }
};
```
