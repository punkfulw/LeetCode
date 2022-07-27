# [139. Word Break (Medium)](https://leetcode.com/problems/word-break/)

<p>Given a <strong>non-empty</strong> string <em>s</em> and a dictionary <em>wordDict</em> containing a list of <strong>non-empty</strong> words, determine if <em>s</em> can be segmented into a space-separated sequence of one or more dictionary words.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>The same word in the dictionary may be reused multiple times in the segmentation.</li>
	<li>You may assume the dictionary does not contain duplicate words.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "leetcode", wordDict = ["leet", "code"]
<strong>Output:</strong> true
<strong>Explanation:</strong> Return true because <code>"leetcode"</code> can be segmented as <code>"leet code"</code>.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "applepenapple", wordDict = ["apple", "pen"]
<strong>Output:</strong> true
<strong>Explanation:</strong> Return true because <code>"</code>applepenapple<code>"</code> can be segmented as <code>"</code>apple pen apple<code>"</code>.
&nbsp;            Note that you are allowed to reuse a dictionary word.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
<strong>Output:</strong> false
</pre>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Word Break II (Hard)](https://leetcode.com/problems/word-break-ii/)


## Solution 1. DP Top-down

```cpp
// OJ: https://leetcode.com/problems/word-break/
// Author: github.com/punkfulw
// Time: O(S^3)
// Space: O(S + W)
class Solution {
public:
    int n;
    vector<int> dp;
    bool sol(string s, set<string> &st, int i){
        if (i == n)
            return true;
        if (dp[i] != -1)
            return dp[i];
        bool ret = 0;
        for (int j = n - i; j >= 0 && !ret; j--){
            string cur = s.substr(i, j);
            if (st.find(cur) != st.end())
                ret |= sol(s, st, i + j);
        }
        return dp[i] = ret;
    }
    
    bool wordBreak(string s, vector<string>& dic) {
        n = s.size();
        dp.resize(n, -1);
        set<string> st(dic.begin(), dic.end());
        return sol(s, st, 0);
    }
};
```
