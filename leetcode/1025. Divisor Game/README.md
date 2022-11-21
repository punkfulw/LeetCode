# [1025. Divisor Game (Easy)](https://leetcode.com/problems/divisor-game/)

<p>Alice and Bob take turns playing a game, with Alice starting first.</p>

<p>Initially, there is a number <code>N</code>&nbsp;on the chalkboard.&nbsp; On each player's turn, that player makes a <em>move</em>&nbsp;consisting of:</p>

<ul>
	<li>Choosing&nbsp;any <code>x</code> with <code>0 &lt; x &lt; N</code> and <code>N % x == 0</code>.</li>
	<li>Replacing&nbsp;the number&nbsp;<code>N</code>&nbsp;on the chalkboard with <code>N - x</code>.</li>
</ul>

<p>Also, if a player cannot make a move, they lose the game.</p>

<p>Return <code>True</code> if and only if Alice wins the game, assuming both players play optimally.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">2</span>
<strong>Output: </strong><span id="example-output-1">true</span>
<strong>Explanation:</strong> Alice chooses 1, and Bob has no more moves.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">3</span>
<strong>Output: </strong><span id="example-output-2">false</span>
<strong>Explanation:</strong> Alice chooses 1, Bob chooses 1, and Alice has no more moves.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= N &lt;= 1000</code></li>
</ol>
</div>
</div>

**Companies**:  
[Visa](https://leetcode.com/company/visa)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/divisor-game/
// Author: github.com/punkfulw
// Time: O(N * sqrt(N))
// Space: O(N)
class Solution {
public:
    int dp[1001] = {};
    bool divisorGame(int n) {
        if (n == 1)
            return false;
        if (n == 2)
            return true;
        if (dp[n])
            return dp[n];
        bool ret = false;
        
        for (int i = 1; i <= n / 2 && !ret; i++)
            if (n % i == 0)
                ret |= !divisorGame(n - i);

        return dp[n] = ret;
    }
};
```

