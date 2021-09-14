# [1137. N-th Tribonacci Number (Easy)](https://leetcode.com/problems/n-th-tribonacci-number/)

<p>The Tribonacci sequence T<sub>n</sub> is defined as follows:&nbsp;</p>

<p>T<sub>0</sub> = 0, T<sub>1</sub> = 1, T<sub>2</sub> = 1, and T<sub>n+3</sub> = T<sub>n</sub> + T<sub>n+1</sub> + T<sub>n+2</sub> for n &gt;= 0.</p>

<p>Given <code>n</code>, return the value of T<sub>n</sub>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 4
<strong>Output:</strong> 4
<strong>Explanation:</strong>
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 25
<strong>Output:</strong> 1389537
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 37</code></li>
	<li>The answer is guaranteed to fit within a 32-bit integer, ie. <code>answer &lt;= 2^31 - 1</code>.</li>
</ul>

**Related Topics**:  
[Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Climbing Stairs (Easy)](https://leetcode.com/problems/climbing-stairs/)
* [Fibonacci Number (Easy)](https://leetcode.com/problems/fibonacci-number/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/n-th-tribonacci-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int tribonacci(int n) {
        int fir = 0, sec = 1, thr = 1;
        if (n < 2) return n;
        if (n == 2) return 1;
        for (int i = 3; i <= n; i++){
            int cur =  fir + sec + thr;
            fir = sec; sec = thr; thr = cur;
        }        
        return thr;
    }
};
```

## Solution 2. memo

```cpp
// OJ: https://leetcode.com/problems/n-th-tribonacci-number/
// Author: github.com/punkfulw
// Time: O(3^N)
// Space: O(N)
class Solution {
public:
    int dp[38] = {0, 1, 1};
    int tribonacci(int n) {
        if (n < 2) 
            return n;
        if (n == 2) return 1;
        if (dp[n])
            return dp[n];
        dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return dp[n];      
    }
};
```
