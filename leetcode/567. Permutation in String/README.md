# [567. Permutation in String (Medium)](https://leetcode.com/problems/permutation-in-string/)

<p>Given two strings <code>s1</code> and <code>s2</code>, return <code>true</code><em> if </em><code>s2</code><em> contains a permutation of </em><code>s1</code><em>, or </em><code>false</code><em> otherwise</em>.</p>

<p>In other words, return <code>true</code> if one of <code>s1</code>'s permutations is the substring of <code>s2</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s1 = "ab", s2 = "eidbaooo"
<strong>Output:</strong> true
<strong>Explanation:</strong> s2 contains one permutation of s1 ("ba").
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s1 = "ab", s2 = "eidboaoo"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s1</code> and <code>s2</code> consist of lowercase English letters.</li>
</ul>


**Companies**:  
[Yandex](https://leetcode.com/company/yandex), [Amazon](https://leetcode.com/company/amazon), [Oracle](https://leetcode.com/company/oracle), [Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Minimum Window Substring (Hard)](https://leetcode.com/problems/minimum-window-substring/)
* [Find All Anagrams in a String (Medium)](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

## Solution 1. Sliding Window

```cpp
// OJ: https://leetcode.com/problems/permutation-in-string/
// Author: github.com/punkfulw
// Time: O(s2)
// Space: O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (m < n)
            return false;
        vector<int> cnt1(26), cnt2(26);
        
        for (auto &c: s1)
            cnt1[c - 'a']++;
        
        for (int i = 0; i < m; i++){
            char c = s2[i];
            cnt2[c - 'a']++;
            if (i >= n)
                cnt2[s2[i - n] - 'a']--; 
            
            if (cnt1 == cnt2)
                return true;
        }
        return false;
    }
};
```
