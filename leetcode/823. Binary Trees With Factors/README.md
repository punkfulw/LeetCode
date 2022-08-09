# [823. Binary Trees With Factors (Medium)](https://leetcode.com/problems/binary-trees-with-factors/)

<p>Given an array of unique integers, each integer is strictly greater than 1.</p>

<p>We make a binary tree using these integers&nbsp;and each number may be used for any number of times.</p>

<p>Each non-leaf node's&nbsp;value should be equal to the product of the values of it's children.</p>

<p>How many binary trees can we make?&nbsp; Return the answer <strong>modulo 10 ** 9 + 7</strong>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> <code>A = [2, 4]</code>
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can make these trees: <code>[2], [4], [4, 2, 2]</code></pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> <code>A = [2, 4, 5, 10]</code>
<strong>Output:</strong> <code>7</code>
<strong>Explanation:</strong> We can make these trees: <code>[2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2]</code>.</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;=&nbsp;1000</code>.</li>
	<li><code>2 &lt;=&nbsp;A[i]&nbsp;&lt;=&nbsp;10 ^ 9</code>.</li>
</ol>


## Solution 1. DP + DFS

```cpp
// OJ: https://leetcode.com/problems/binary-trees-with-factors/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    long MOD = 1e9 + 7, ans = 0;
    unordered_map<int, int> cnt, dp;
    long dfs(int cur, vector<int>& arr){
        if (dp[cur])
            return dp[cur];
        long ret = 1;
        for (int j = 0; arr[j] < cur; j++){
            int l = arr[j], r = cur / arr[j];
            if (cur % l == 0 && cnt[r])
                ret = (ret + dfs(l, arr) * dfs(r, arr) % MOD) % MOD;
        }
        return dp[cur] = ret;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        for (auto i: arr)
            cnt[i]++;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++){
            ans = ans + dfs(arr[i], arr) % MOD;
        }
        return ans % MOD;
    }
};
```
