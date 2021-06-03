# [476. Number Complement (Easy)](https://leetcode.com/problems/number-complement/)

<p>Given a <b>positive</b> integer <code>num</code>., output its complement number. The complement strategy is to flip the bits of its binary representation.</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> num = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> num = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The given integer <code>num</code> is guaranteed to fit within the range of a 32-bit signed integer.</li>
  <li><code>1 &lt;= num</code></li>
  <li>You could assume no leading zero bit in the integer’s binary representation.</li>
  <li>This question is the same as 1009: <code>https://leetcode.com/problems/complement-of-base-10-integer/</code></li>
</ul>


**Companies**:  
[Cloudera](https://leetcode.com/company/cloudera)

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-complement/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask ^ num;
    }
};
```
