# [263. Ugly Number (Easy)](https://leetcode.com/problems/ugly-number/)

<p>An <b>ugly number</b> is a positive integer whose prime factors are limited to <code>2</code>, <code>3</code>, and <code>5</code>.</p>

<p>Given an integer <code>n</code>, return <code>true</code> <em>if</em> <code>n</code><em> is an <b>ugly number</b>.</em></p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> n = 6
<strong>Output:</strong> true
<strong>Explanation:</strong> 6 = 2 × 3
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> n = 8
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> 8 = 2 × 2 × 2
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> n = 14
<strong>Output:</strong> false
<strong>Explanation:</strong> 14 is not ugly since it includes the prime factor 7.
</pre>

<p><strong>Example 4:</strong></p>
<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> true
<strong>Explanation:</strong> 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>



**Related Topics**:  
[Math](https://leetcode.com/tag/math/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/ugly-number/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isUgly(int n) {
        if (n < 1)
            return false;
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;
        return n == 1;
    }
};
```

