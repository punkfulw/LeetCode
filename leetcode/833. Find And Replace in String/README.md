# [833. Find And Replace in String (Medium)](https://leetcode.com/problems/find-and-replace-in-string/)

<p>To some string <code>s</code>, we will perform some replacement operations that replace groups of letters with new ones (not necessarily the same size).</p>

<p>Each replacement operation has <code>3</code> parameters: a starting index <code>i</code>, a source word <code>x</code> and a target word <code>y</code>. The rule is that if <code><font face="monospace">x</font></code> starts at position <code>i</code> in the <strong>original</strong> <strong>string</strong> <strong><code>S</code></strong>, then we will replace that occurrence of <code>x</code> with <code>y</code>. If not, we do nothing.</p>

<p>For example, if we have <code>s = "abcd"</code> and we have some replacement operation <code>i = 2, x = "cd", y = "ffff"</code>, then because <code>"cd"</code> starts at position <code><font face="monospace">2</font></code> in the original string <code>s</code>, we will replace it with <code>"ffff"</code>.</p>

<p>Using another example on <code>s = "abcd"</code>, if we have both the replacement operation <code>i = 0, x = "ab", y = "eee"</code>, as well as another replacement operation <code>i = 2, x = "ec", y = "ffff"</code>, this second operation does nothing because in the original string <code>s[2] = 'c'</code>, which doesn't match <code>x[0] = 'e'</code>.</p>

<p>All these operations occur simultaneously. It's guaranteed that there won't be any overlap in replacement: for example, <code>s = "abc", indexes = [0, 1], sources = ["ab","bc"]</code> is not a valid test case.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcd", indexes = [0, 2], sources = ["a", "cd"], targets = ["eee", "ffff"]
<strong>Output:</strong> "eeebffff"
<strong>Explanation:</strong>
"a" starts at index 0 in s, so it's replaced by "eee".
"cd" starts at index 2 in s, so it's replaced by "ffff".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abcd", indexes = [0, 2], sources = ["ab","ec"], targets = ["eee","ffff"]
<strong>Output:</strong> "eeecd"
<strong>Explanation:</strong>
"ab" starts at index 0 in s, so it's replaced by "eee".
"ec" doesn't starts at index 2 in the <strong>original</strong> s, so we do nothing.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
	<li><code>0 &lt;= indexes.length &lt;= 100</code></li>
	<li><code>0 &lt;= indexes[i] &lt; s.length</code></li>
	<li><code>sources.length == indexes.length</code></li>
	<li><code>targets.length == indexes.length</code></li>
	<li><code>1 &lt;= sources[i].length, targets[i].length &lt;= 50</code></li>
	<li><code>sources[i]</code> and <code>targets[i]</code> consist of only lowercase English letters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-and-replace-in-string/
// Author: github.com/punkfulw
// Time: O(N^N + KlogK)
// Space: O(K)
class Solution {
public:
    bool check(string &s, int idx, string &ss){
        if (idx + ss.size() > s.size())
            return false;
        for (int i = 0; i < ss.size(); i++)
            if (s[idx + i] != ss[i])
                return false;
        return true;
    }
    string findReplaceString(string s, vector<int>& idxs, vector<string>& srs, vector<string>& tars) {
        int k = idxs.size();
        string ans = "";
        map<int, pair<string, string>> mp;
        
        for (int i = 0; i < k; i++){
            int idx = idxs[i];
            string ss = srs[i], tar = tars[i];
            mp[-idx] = {ss, tar};
        }
        
        for (auto p: mp){
            int idx = -p.first;
            string ss = p.second.first, tar = p.second.second;
            // cout << idx << " " << ss << " " << tar << endl;
            if (!check(s, idx, ss))
                continue;
            string head = s.substr(0, idx), tail = s.substr(idx + ss.size());
            // cout << head << " " << tail << endl;
            s = head + tar + tail;
        } 
        return s;
    }
};
```
