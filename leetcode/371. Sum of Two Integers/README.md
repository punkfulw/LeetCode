# [371. Sum of Two Integers (Medium)](https://leetcode.com/problems/sum-of-two-integers/)

<p>Given two integers <code>a</code> and <code>b</code>, return <em>the sum of the two integers without using the operators</em> <code>+</code> <em>and</em> <code>-</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> a = 1, b = 2
<strong>Output:</strong> 3
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> a = 2, b = 3
<strong>Output:</strong> 5
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-1000 &lt;= a, b &lt;= 1000</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Add Two Numbers (Medium)](https://leetcode.com/problems/add-two-numbers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sum-of-two-integers/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary%3A-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (unsigned int)(a & b) << 1);
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/sum-of-two-integers/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int carry =  (unsigned int)(a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
```
