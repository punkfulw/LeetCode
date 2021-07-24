# [49. Group Anagrams (Medium)](https://leetcode.com/problems/group-anagrams/)

<p>Given an array of strings <code>strs</code>., group <b>the anagrams</b> together. You can return the answer in <b>any order</b>.</p>

<p>An <b>Anagram</b> is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.</p>


<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> ["eat", "tea", "tan", "ate", "nat", "bat"]
<strong>Output:</strong> [["bat"],["nat","tan"],["ate","eat","tea"]]
</pre>


<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong>  strs = [""]
<strong>Output:</strong> [[""]]
</pre>


<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> strs = ["a"]
<strong>Output:</strong> [["a"]]
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= strs.length &lt;= 10<sup>4</sup></code></li>
  <li><code>0 &lt;= strs[i].length &lt;= 100</code></li>
  <li><code>strs[i]</code> consists of lower-case English letters.</li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Valid Anagram (Easy)](https://leetcode.com/problems/valid-anagram/)
* [Group Shifted Strings (Medium)](https://leetcode.com/problems/group-shifted-strings/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/group-anagrams/
// Author: github.com/punkfulw
// Time: O(NK)
// Space: O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (auto s: strs){
            string ori = s;
            sort(s.begin(), s.end());
            mp[s].push_back(ori);
        }
        for (auto p: mp)
            ans.push_back(p.second);
        return ans;
    }
};
```
