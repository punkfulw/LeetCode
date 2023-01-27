# [472. Concatenated Words (Hard)](https://leetcode.com/problems/concatenated-words/)

Given a list of words (<b>without duplicates</b>), please write a program that returns all concatenated words in the given list of words.
<p>A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.</p>

<p><b>Example:</b><br>
</p><pre><b>Input:</b> ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

<b>Output:</b> ["catsdogcats","dogcatsdog","ratcatdogcat"]

<b>Explanation:</b> "catsdogcats" can be concatenated by "cats", "dog" and "cats"; <br> "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; <br>"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The number of elements of the given array will not exceed <code>10,000 </code>
</li><li>The length sum of elements in the given array will not exceed <code>600,000</code>. </li>
<li>All the input string will only include lower case letters.</li>
<li>The returned elements order does not matter. </li>
</ol>
<p></p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Trie](https://leetcode.com/tag/trie/)

**Similar Questions**:
* [Word Break II (Hard)](https://leetcode.com/problems/word-break-ii/)

## Solution 1. dfs

```cpp
// OJ: https://leetcode.com/problems/concatenated-words/
// Author: github.com/punkfulw
// Time: O(NW)
// Space: O(N) 
class Solution {
public:
    vector<string> ans;
    unordered_set<string> set;
    
    bool dfs(string &w, int idx, string cur, int cnt){
        if (idx == w.size()){
            if (cur.empty() && cnt > 1)
                return true;
            return false;
        }
        int ret = 0;
        cur += w[idx];
        if (set.find(cur) != set.end())
            ret |= dfs(w, idx + 1, "", cnt + 1);
        
        ret |= dfs(w, idx + 1, cur, cnt);
        return ret;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        set = unordered_set<string> (words.begin(), words.end());
        
        for (auto w: words)
            if (dfs(w, 0, "", 0))
                ans.push_back(w);
        
        return ans;
    }
};
```
