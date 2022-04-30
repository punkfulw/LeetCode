# [399. Evaluate Division (Medium)](https://leetcode.com/problems/evaluate-division/)

<p>You are given <code>equations</code>&nbsp;in the format <code>A / B = k</code>, where <code>A</code> and <code>B</code> are variables represented as strings, and <code>k</code> is a real number (floating-point number). Given some <code>queries</code>, return <em>the answers</em>. If the answer does not exist, return <code>-1.0</code>.</p>

<p>The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
<strong>Output:</strong> [6.00000,0.50000,-1.00000,1.00000,-1.00000]
<strong>Explanation:</strong> 
Given: <em>a / b = 2.0</em>, <em>b / c = 3.0</em>
queries are: <em>a / c = ?</em>, <em>b / a = ?</em>, <em>a / e = ?</em>, <em>a / a = ?</em>, <em>x / x = ?</em>
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
<strong>Output:</strong> [3.75000,0.40000,5.00000,0.20000]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
<strong>Output:</strong> [0.50000,2.00000,-1.00000,-1.00000]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= equations.length &lt;= 20</code></li>
	<li><code>equations[i].length == 2</code></li>
	<li><code>1 &lt;= equations[i][0], equations[i][1] &lt;= 5</code></li>
	<li><code>values.length ==&nbsp;equations.length</code></li>
	<li><code>0.0 &lt;&nbsp;values[i] &lt;= 20.0</code></li>
	<li><code>1 &lt;= queries.length &lt;= 20</code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>1 &lt;= queries[i][0], queries[i][1] &lt;= 5</code></li>
	<li><code>equations[i][0], equations[i][1],&nbsp;queries[i][0], queries[i][1]</code>&nbsp;consist of lower case English letters and digits.</li>
</ul>


**Related Topics**:  
[Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/evaluate-division/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    
    map<string, vector<pair<string, double>>> mp;
    void dfs(string s1, string s2, map<string, int> &vis, double &cur, double run)
    {
        if (vis[s1]) return;
        vis[s1] = true;
        
        for (auto pair: mp[s1])
        {
            if (pair.first == s2)
            {
                cur = run * pair.second;
                return;
            }
            dfs(pair.first, s2, vis, cur, run * pair.second);
        }
        return;
    }
    
    vector<double> calcEquation(vector<vector<string>>& E, vector<double>& V, vector<vector<string>>& Q) {
        int n = Q.size(), m = E.size();
        vector<double> ans(n);
        
        for (int i = 0; i < m; i++)
        {
            string s1 = E[i][0], s2 = E[i][1];
            mp[s1].push_back({s2, V[i]});
            mp[s1].push_back({s1, 1});
            mp[s2].push_back({s1, 1 / V[i]});
            mp[s2].push_back({s2, 1});
        }
        
        for (int i = 0; i < n; i++)
        {
            string s1 = Q[i][0], s2 = Q[i][1];
            map<string, int> vis;
            double cur = -1;
            dfs(s1, s2, vis, cur, 1.0);
            ans[i] = cur;
        }
        return ans;
    }
};
```
