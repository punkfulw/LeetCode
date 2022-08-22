# [140. Word Break II (Hard)](https://leetcode.com/problems/word-break-ii/)

<p>Given a <strong>non-empty</strong> string <em>s</em> and a dictionary <em>wordDict</em> containing a list of <strong>non-empty</strong> words, add spaces in <em>s</em> to construct a sentence where each word is a valid dictionary word.&nbsp;Return all such possible sentences.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>The same word in the dictionary may be reused multiple times in the segmentation.</li>
	<li>You may assume the dictionary does not contain duplicate words.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:
</strong>s = "<code>catsanddog</code>"
wordDict = <code>["cat", "cats", "and", "sand", "dog"]</code>
<strong>Output:
</strong><code>[
&nbsp; "cats and dog",
&nbsp; "cat sand dog"
]</code>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:
</strong>s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
<strong>Output:
</strong>[
&nbsp; "pine apple pen apple",
&nbsp; "pineapple pen apple",
&nbsp; "pine applepen apple"
]
<strong>Explanation:</strong> Note that you are allowed to reuse a dictionary word.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:
</strong>s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
<strong>Output:
</strong>[]</pre>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Pinterest](https://leetcode.com/company/pinterest)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Word Break (Medium)](https://leetcode.com/problems/word-break/)
* [Concatenated Words (Hard)](https://leetcode.com/problems/concatenated-words/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/word-break-ii/
// Author: github.com/punkfulw
// Time: O(N!)
// Space: O(N + D)
class Solution {
public:
    vector<string> ans;
    int n;
    void dfs(int i, string s, string &ori, unordered_set<string> &dic){
        if (i == n){
            s.pop_back();
            ans.push_back(s);
            return;
        }
        for (int j = i; j < min(i + 10, n); j++){
            string cur = ori.substr(i, j - i + 1);
            if (dic.find(cur) != dic.end()){
                string new_s = s + cur + " ";
                dfs(j + 1, new_s, ori, dic);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dic(wordDict.begin(), wordDict.end());
        n = s.size();
        dfs(0, "", s, dic);
        return ans;
    }
};
```
