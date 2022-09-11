# [343. Integer Break (Medium)](https://leetcode.com/problems/integer-break/)

<p>Given a positive integer <i>n</i>, break it into the sum of <b>at least</b> two positive integers and maximize the product of those integers. Return the maximum product you can get.</p>

<p><strong>Example 1:</strong></p>

<div>
<pre><strong>Input: </strong><span id="example-input-1-1">2</span>
<strong>Output: </strong><span id="example-output-1">1</span>
<strong>Explanation: </strong>2 = 1 + 1, 1 × 1 = 1.</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">10</span>
<strong>Output: </strong><span id="example-output-2">36</span>
<strong>Explanation: </strong>10 = 3 + 3 + 4, 3 ×&nbsp;3 ×&nbsp;4 = 36.</pre>

<p><b>Note</b>: You may assume that <i>n</i> is not less than 2 and not larger than 58.</p>
</div>
</div>

**Companies**:  
[Google](https://leetcode.com/company/google), [Tencent](https://leetcode.com/company/tencent)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP


```cpp
// OJ: https://leetcode.com/problems/integer-break/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int sol(int n, vector<int> &dp){
        if (n == 0) return 0;
        if (n <= 2) return 1;
        if (dp[n])  return dp[n];
        int mx = 0;
        for (int i = 1; i <= n / 2; i++){
            mx = max(mx, i * (n - i));
            mx = max(mx, sol(i, dp) * sol(n - i, dp));
            mx = max(mx, sol(i, dp) * (n - i));
            mx = max(mx, i * sol(n - i, dp));
        }
        return dp[n] = mx;
    }
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        return sol(n, dp);
    }
};
```
