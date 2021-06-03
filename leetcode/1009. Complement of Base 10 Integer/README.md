# [1009. Complement of Base 10 Integer (Easy)](https://leetcode.com/problems/complement-of-base-10-integer/)

<p>Every non-negative integer <code>n</code> has a binary representation. 
  For example, <code>5</code> can be represented as <code>"101"</code> in binary, <code>11</code> as <code>"1011"</code> in binary, and so on. 
  Note that except for <code>n = 0</code>, there are no leading zeroes in any binary representation.</p>

<p>The <em>complement</em> of a binary representation is the number in binary you get when changing every <code>1</code> to a <code>0</code> and <code>0</code> to a <code>1</code>. 
  For example, the complement of <code>"101"</code> in binary is <code>"010"</code> in binary.</p>

<p>For a given number <code>n</code> in base-10, return the complement of it's binary representation as a base-10 integer.</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> n = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> n = 7
<strong>Output:</strong> 0
<strong>Explanation:</strong> 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
</pre>

<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> n = 10
<strong>Output:</strong> 5
<strong>Explanation:</strong> 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>0 &lt;= n &lt;= 10<sup>9</sup></code></li>
  <li>This question is the same as 476: <code>https://leetcode.com/problems/number-complement/</code></li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/complement-of-base-10-integer/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;
        while (n > mask)
            mask = mask * 2 + 1;
        return mask ^ n; 
    }
};
```


## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/complement-of-base-10-integer/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        unsigned mask = ~0;
        if (n == 0)
            return 1;
        while (n & mask)
            mask <<= 1;
        return ~mask ^ n;
    }
};
```
