# [792. Number of Matching Subsequences (Medium)](https://leetcode.com/problems/number-of-matching-subsequences/)

<p>Given a string <code>s</code> and an array of strings <code>words</code>, return <em>the number of</em> <code>words[i]</code> <em>that is a subsequence of</em> <code>s</code>.</p>

<p>A <strong>subsequence</strong> of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.</p>

<ul>
	<li>For example, <code>"ace"</code> is a subsequence of <code>"abcde"</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcde", words = ["a","bb","acd","ace"]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three strings in words that are a subsequence of s: "a", "acd", "ace".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words.length &lt;= 5000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 50</code></li>
	<li><code>s</code> and <code>words[i]</code> consist of only lowercase English letters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Coupang](https://leetcode.com/company/coupang)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Is Subsequence (Easy)](https://leetcode.com/problems/is-subsequence/)
* [Shortest Way to Form String (Medium)](https://leetcode.com/problems/shortest-way-to-form-string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-matching-subsequences/
// Author: github.com/punkfulw
// Time: O(S + NWlogS)
// Space: O(S)
class Solution {
public:
    int solve(vector<vector<int>> &rec, string w){
        int pre = -1;
        vector<int> idx(26, 0);
        for (auto c: w){
            int pos = c - 'a';
            auto it = upper_bound(rec[pos].begin() + idx[pos], rec[pos].end(), pre);
            if (it == rec[pos].end())
                return false;
            pre = *it;
            idx[pos] = it - rec[pos].begin() + 1;
        }
        return true;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0, n = s.size(), m = words.size();
        vector<vector<int>> rec(26); 
        for (int i = 0; i < n; i++)
            rec[s[i] - 'a'].push_back(i);      
        for (auto w: words)
            ans += solve(rec, w);        
        return ans;
    }
};
```
