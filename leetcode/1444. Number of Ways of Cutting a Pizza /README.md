# [1444. Number of Ways of Cutting a Pizza (Hard)](https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/)

<p>Given a rectangular pizza represented as a <code>rows x cols</code>&nbsp;matrix containing the following characters: <code>'A'</code> (an apple) and <code>'.'</code> (empty cell) and given the integer <code>k</code>. You have to cut the pizza into <code>k</code> pieces using <code>k-1</code> cuts.&nbsp;</p>

<p>For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.</p>

<p><em>Return the number of ways of cutting the pizza such that each piece contains <strong>at least</strong> one apple.&nbsp;</em>Since the answer can be a huge number, return this modulo 10^9 + 7.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/04/23/ways_to_cut_apple_1.png" style="width: 500px; height: 378px;"></strong></p>

<pre><strong>Input:</strong> pizza = ["A..","AAA","..."], k = 3
<strong>Output:</strong> 3 
<strong>Explanation:</strong> The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> pizza = ["A..","AA.","..."], k = 3
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> pizza = ["A..","A..","..."], k = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= rows, cols &lt;= 50</code></li>
	<li><code>rows ==&nbsp;pizza.length</code></li>
	<li><code>cols ==&nbsp;pizza[i].length</code></li>
	<li><code>1 &lt;= k &lt;= 10</code></li>
	<li><code>pizza</code> consists of characters <code>'A'</code>&nbsp;and <code>'.'</code> only.</li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP + presum

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
// Author: github.com/punkfulw
// Time: O(MNK * max(M, N))
// Space: O(MNK)
class Solution {
public:
    int n, m, M = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    vector<vector<int>> pre;
    vector<string> s;
    
    int sol(int i, int j, int k){
        if (i >= n || j >= m)
            return 0;
        
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        
        if (k == 1)
            return pre[n][m] - pre[n][j] - pre[i][m] + pre[i][j] > 0;
        
        int ret = 0;
        for (int r = i, cnt = 0; r < n; r++)
            if (pre[r + 1][m] - pre[r + 1][j] - pre[i][m] + pre[i][j] > 0)
                ret = (ret + sol(r + 1, j, k - 1)) % M;
        
        for (int c = j; c < m; c++)
            if (pre[n][c + 1] - pre[i][c + 1] - pre[n][j] + pre[i][j] > 0)
                ret = (ret + sol(i, c + 1, k - 1)) % M;
        
        return dp[i][j][k] = ret;
    }
    
    int ways(vector<string>& s, int k) {
        n = s.size(), m = s[0].size();
        dp.resize(n, vector<vector<int>> (m, vector<int> (k + 1, -1)));
        pre.resize(n + 1, vector<int> (m + 1));
        this->s = s;
        
        for (int i = 0; i < n; i++)
            for (int j = 0, cnt = 0; j < m; j++){
                cnt += s[i][j] == 'A';
                pre[i + 1][j + 1] = pre[i][j + 1] + cnt;
            }
        return sol(0, 0, k);
    }
};
```
