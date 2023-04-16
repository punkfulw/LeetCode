# [1639. Number of Ways to Form a Target String Given a Dictionary (Hard)](https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/)

<p>You are given a list of strings of the <strong>same length</strong> <code>words</code> and a string <code>target</code>.</p>

<p>Your task is to form <code>target</code> using the given <code>words</code> under the following rules:</p>

<ul>
	<li><code>target</code> should be formed from left to right.</li>
	<li>To form the <code>i<sup>th</sup></code> character (<strong>0-indexed</strong>) of <code>target</code>, you can choose the <code>k<sup>th</sup></code> character of the <code>j<sup>th</sup></code> string in <code>words</code> if <code>target[i] = words[j][k]</code>.</li>
	<li>Once you use the <code>k<sup>th</sup></code> character of the <code>j<sup>th</sup></code> string of <code>words</code>, you <strong>can no longer</strong> use the <code>x<sup>th</sup></code> character of any string in <code>words</code> where <code>x &lt;= k</code>. In other words, all characters to the left of or at index <code>k</code> become unusuable for every string.</li>
	<li>Repeat the process until you form the string <code>target</code>.</li>
</ul>

<p><strong>Notice</strong>&nbsp;that you can use <strong>multiple characters</strong> from the <strong>same string</strong> in <code>words</code> provided the conditions above are met.</p>

<p>Return <em>the number of ways to form <code>target</code> from <code>words</code></em>. Since the answer may be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["acca","bbbb","caca"], target = "aba"
<strong>Output:</strong> 6
<strong>Explanation:</strong> There are 6 ways to form target.
"aba" -&gt; index 0 ("<u>a</u>cca"), index 1 ("b<u>b</u>bb"), index 3 ("cac<u>a</u>")
"aba" -&gt; index 0 ("<u>a</u>cca"), index 2 ("bb<u>b</u>b"), index 3 ("cac<u>a</u>")
"aba" -&gt; index 0 ("<u>a</u>cca"), index 1 ("b<u>b</u>bb"), index 3 ("acc<u>a</u>")
"aba" -&gt; index 0 ("<u>a</u>cca"), index 2 ("bb<u>b</u>b"), index 3 ("acc<u>a</u>")
"aba" -&gt; index 1 ("c<u>a</u>ca"), index 2 ("bb<u>b</u>b"), index 3 ("acc<u>a</u>")
"aba" -&gt; index 1 ("c<u>a</u>ca"), index 2 ("bb<u>b</u>b"), index 3 ("cac<u>a</u>")
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["abba","baab"], target = "bab"
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 ways to form target.
"bab" -&gt; index 0 ("<u>b</u>aab"), index 1 ("b<u>a</u>ab"), index 2 ("ab<u>b</u>a")
"bab" -&gt; index 0 ("<u>b</u>aab"), index 1 ("b<u>a</u>ab"), index 3 ("baa<u>b</u>")
"bab" -&gt; index 0 ("<u>b</u>aab"), index 2 ("ba<u>a</u>b"), index 3 ("baa<u>b</u>")
"bab" -&gt; index 1 ("a<u>b</u>ba"), index 2 ("ba<u>a</u>b"), index 3 ("baa<u>b</u>")
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> words = ["abcd"], target = "abcd"
<strong>Output:</strong> 1
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> words = ["abab","baba","abba","baab"], target = "abba"
<strong>Output:</strong> 16
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 1000</code></li>
	<li>All strings in <code>words</code> have the same length.</li>
	<li><code>1 &lt;= target.length &lt;= 1000</code></li>
	<li><code>words[i]</code> and <code>target</code> contain only lowercase English letters.</li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP


```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
// Author: github.com/punkfulw
// Time: O(LM + LN)
// Space: O(LM)
class Solution {
public:
    int sz, m;
    long M = 1e9 + 7;
    vector<vector<int>> count, dp;
    
    long dfs(int idx, int k, vector<string> &words, string &tar){
        if (k == sz)
            return 1;
        if (idx >= m)
            return 0;
        
        if (dp[idx][k] != -1)
            return dp[idx][k];
        
        int ret = dfs(idx + 1, k, words, tar);
        
        if (count[idx][tar[k] - 'a'])
            ret = (ret + count[idx][tar[k] - 'a'] * dfs(idx + 1, k + 1, words, tar)) % M;
        
        return dp[idx][k] = ret;
    }
    
    int numWays(vector<string>& words, string target) {
        m = words[0].size(), sz = target.size();
        count.resize(m, vector<int> (26));    
        dp.resize(m + 1, vector<int> (sz + 1, -1)); 
        
        for (auto &w: words){
            for (int i = 0; i < m; i++)
                count[i][w[i] - 'a']++;
        }
        
        return dfs(0, 0, words, target);
    }
};
```
