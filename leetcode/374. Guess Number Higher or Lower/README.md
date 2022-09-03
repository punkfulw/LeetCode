# [374. Guess Number Higher or Lower (Easy)](https://leetcode.com/problems/guess-number-higher-or-lower/)

<p>We are playing the Guess Game. The game is as follows:</p>

<p>I pick a number from <code>1</code> to <code>n</code>. You have to guess which number I picked.</p>

<p>Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.</p>

<p>You call a pre-defined API <code>int guess(int num)</code>, which returns 3 possible results:</p>

<ul>
	<li><code>-1</code>: The number I picked is lower than your guess (i.e. <code>pick &lt; num</code>).</li>
	<li><code>1</code>: The number I picked is higher than your guess (i.e. <code>pick &gt; num</code>).</li>
	<li><code>0</code>: The number I picked is equal to your guess (i.e. <code>pick == num</code>).</li>
</ul>

<p>Return <em>the number that I picked</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> n = 10, pick = 6
<strong>Output:</strong> 6
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> n = 1, pick = 1
<strong>Output:</strong> 1
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> n = 2, pick = 1
<strong>Output:</strong> 1
</pre><p><strong>Example 4:</strong></p>
<pre><strong>Input:</strong> n = 2, pick = 2
<strong>Output:</strong> 2
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>1 &lt;= pick &lt;= n</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Interactive](https://leetcode.com/tag/interactive/)

**Similar Questions**:
* [First Bad Version (Easy)](https://leetcode.com/problems/first-bad-version/)
* [Guess Number Higher or Lower II (Medium)](https://leetcode.com/problems/guess-number-higher-or-lower-ii/)
* [Find K Closest Elements (Medium)](https://leetcode.com/problems/find-k-closest-elements/)

## Solution 1. Binary Search 

```cpp
// OJ: https://leetcode.com/problems/guess-number-higher-or-lower/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(logN)
class Solution {
public:
    int sol(int l, int r){
        int mid = l + (r - l) / 2;
        int ret = guess(mid);
        if (ret == 0)
            return mid;
        else if (ret == -1)
            return sol(l, mid - 1);
        else
            return sol(mid + 1, r);
    }
    int guessNumber(int n) {
        return sol(1, n);
    }
};
```
