# [1492. The kth Factor of n (Medium)](https://leetcode.com/problems/the-kth-factor-of-n/)

<p>Given two positive integers <code>n</code> and <code>k</code>.</p>

<p>A factor of an integer <code>n</code> is defined as an integer <code>i</code> where <code>n % i == 0</code>.</p>

<p>Consider a list of all factors of <code>n</code>&nbsp;sorted in <strong>ascending order</strong>, return <em>the </em><code>kth</code><em> factor</em> in this list or return <strong>-1</strong> if <code>n</code> has less than&nbsp;<code>k</code> factors.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 12, k = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 7, k = 2
<strong>Output:</strong> 7
<strong>Explanation:</strong> Factors list is [1, 7], the 2nd factor is 7.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 4, k = 4
<strong>Output:</strong> -1
<strong>Explanation:</strong> Factors list is [1, 2, 4], there is only 3 factors. We should return -1.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 1, k = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> Factors list is [1], the 1st factor is 1.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> n = 1000, k = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong> Factors list is [1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 125, 200, 250, 500, 1000].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 1000</code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/the-kth-factor-of-n/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int kthFactor(int n, int k) {
        for (int i = 1; i <= n / 2; i++)
            if (n % i == 0 && --k == 0) return i;

        return k == 1 ? n : -1;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/the-kth-factor-of-n/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/the-kth-factor-of-n/discuss/708099/C%2B%2BJava-Straightforward-%2B-Sqrt(n)
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 1;
        for (; i * i <= n; i++)
            if (n % i == 0 && --k == 0)
                return i;
        if (--i * i == n) i--;
        for (; i >= 1; i--)
            if (n % i == 0 && --k == 0)
                return n / i;
        
        return -1;
    }
};
```
