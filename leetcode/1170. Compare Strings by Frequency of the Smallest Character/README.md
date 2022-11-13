# [1170. Compare Strings by Frequency of the Smallest Character (Easy)](https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/)

<p>Let's define a function <code>f(s)</code> over a non-empty string <code>s</code>, which calculates the frequency of the smallest character in <code>s</code>. For example,&nbsp;if <code>s = "dcce"</code> then <code>f(s) = 2</code> because the smallest character is <code>"c"</code> and its frequency is 2.</p>

<p>Now, given string arrays <code>queries</code>&nbsp;and <code>words</code>, return an integer array <code>answer</code>, where each <code>answer[i]</code>&nbsp;is the number of words such that <code>f(queries[i])</code>&nbsp;&lt; <code>f(W)</code>, where <code>W</code>&nbsp;is a word in <code>words</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> queries = ["cbd"], words = ["zaaaz"]
<strong>Output:</strong> [1]
<strong>Explanation:</strong> On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") &lt; f("zaaaz").
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> On the first query only f("bbb") &lt; f("aaaa"). On the second query both f("aaa") and f("aaaa") are both &gt; f("cc").
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= queries.length &lt;= 2000</code></li>
	<li><code>1 &lt;= words.length &lt;= 2000</code></li>
	<li><code>1 &lt;= queries[i].length, words[i].length &lt;= 10</code></li>
	<li><code>queries[i][j]</code>, <code>words[i][j]</code> are English lowercase letters.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
// Author: github.com/punkfulw
// Time: O(NlogM)
// Space: O(M)
class Solution {
public:
    int cal_score(string &word){
        char sm = 'z';
        int cnt = 0;
        for (auto &c: word){
            if (c < sm){
                cnt = 1;
                sm = c;
            }
            else if (c == sm)
                cnt++;
        }
        return cnt;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& words) {
        int n = q.size(), m = words.size();
        vector<int> ans(n), scores(m);
        
        for (int i = 0; i < m; ++i)
            scores[i] = cal_score(words[i]);

        sort(scores.begin(), scores.end());
        
        for (int i = 0; i < n; i++){
            int cur = cal_score(q[i]);
            int greater_num = m - (upper_bound(scores.begin(), scores.end(), cur) - scores.begin());
            ans[i] = greater_num;
        }
        return ans;
    }
};
```
