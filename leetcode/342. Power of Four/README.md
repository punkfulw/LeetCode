# [342. Power of Four (Easy)](https://leetcode.com/problems/power-of-four/)

<p>Given an integer (signed 32 bits), write a function to check whether it is a power of 4.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">16</span>
<strong>Output: </strong><span id="example-output-1">true</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">5</span>
<strong>Output: </strong><span id="example-output-2">false</span></pre>
</div>

<p><b>Follow up</b>: Could you solve it without loops/recursion?</p>

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Power of Two (Easy)](https://leetcode.com/problems/power-of-two/)
* [Power of Three (Easy)](https://leetcode.com/problems/power-of-three/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/power-of-four/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isPowerOfFour(long n) {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        if ((n ^ (n - 1)) == (n << 1) - 1 && __builtin_popcount(n - 1) % 2 == 0)
            return true;
        return false;
    }
};
```
