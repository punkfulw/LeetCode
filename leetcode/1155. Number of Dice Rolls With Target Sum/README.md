# [1155. Number of Dice Rolls With Target Sum (Medium)](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/)

<p>You have <code>d</code> dice, and each die has <code>f</code> faces numbered <code>1, 2, ..., f</code>.</p>

<p>Return the number of possible ways (out of <code>f<sup>d</sup></code>&nbsp;total ways) <strong>modulo <code>10^9 + 7</code></strong> to roll the dice so the sum of the face up numbers equals <code>target</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> d = 1, f = 6, target = 3
<strong>Output:</strong> 1
<strong>Explanation: </strong>
You throw one die with 6 faces.  There is only one way to get a sum of 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> d = 2, f = 6, target = 7
<strong>Output:</strong> 6
<strong>Explanation: </strong>
You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> d = 2, f = 5, target = 10
<strong>Output:</strong> 1
<strong>Explanation: </strong>
You throw two dice, each with 5 faces.  There is only one way to get a sum of 10: 5+5.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> d = 1, f = 2, target = 3
<strong>Output:</strong> 0
<strong>Explanation: </strong>
You throw one die with 2 faces.  There is no way to get a sum of 3.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> d = 30, f = 30, target = 500
<strong>Output:</strong> 222616187
<strong>Explanation: </strong>
The answer must be returned modulo 10^9 + 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= d, f &lt;= 30</code></li>
	<li><code>1 &lt;= target &lt;= 1000</code></li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP Top-down

```cpp
// OJ: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
// Author: github.com/punkfulw
// Time: O(NK)
// Space: O(NK)
class Solution {
public:
    long MOD = 1e9 + 7;
    vector<vector<long>> dp;
    
    long dfs(int n, int K, int tar, int i, long cnt){
        if (n == i && cnt == tar)
            return 1;
        if (cnt > tar || n == i)
            return 0;
        if (dp[i][cnt] != -1)
            return dp[i][cnt];
        
        dp[i][cnt] = 0;
        for (int k = 1; k <= K; k++)
            dp[i][cnt] = (dp[i][cnt] + dfs(n, K, tar, i + 1, cnt + k)) % MOD; 

        return dp[i][cnt];
    }
    
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n, vector<long> (1001, -1));
        return dfs(n, k, target, 0, 0);
    }
};
```
