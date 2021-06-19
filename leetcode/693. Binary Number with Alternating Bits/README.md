# [693. Binary Number with Alternating Bits (Easy)](https://leetcode.com/problems/binary-number-with-alternating-bits/)

<p>Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> n = 5
<b>Output:</b> True
<b>Explanation:</b>
The binary representation of 5 is: 101
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> n = 7
<b>Output:</b> False
<b>Explanation:</b>
The binary representation of 7 is: 111.
</pre>
<p></p>

<p><b>Example 3:</b><br>
</p><pre><b>Input:</b> n = 11
<b>Output:</b> False
<b>Explanation:</b>
The binary representation of 11 is: 1011.
</pre>
<p></p>

<p><b>Example 4:</b><br>
</p><pre><b>Input:</b> n = 10
<b>Output:</b> True
<b>Explanation:</b>
The binary representation of 10 is: 1010.
</pre>
<p></p>

<p><b>Example 5:</b><br>
</p><pre><b>Input:</b> n = 3
<b>Output:</b> false
</pre>
<p></p>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= n &lt;= 2<sup>31</sup>-1</code></li>
</ul>



**Companies**:  
[Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Number of 1 Bits (Easy)](https://leetcode.com/problems/number-of-1-bits/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/binary-number-with-alternating-bits/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        n = n ^ (n >> 2);
        return !(n & n-1);
    }
};
```
