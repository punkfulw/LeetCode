# [367. Valid Perfect Square (Easy)](https://leetcode.com/problems/valid-perfect-square/)

<p>Given a positive integer <i>num</i>, write a function which returns True if <i>num</i> is a perfect square else False.</p>

<p><b>Note:</b> <b>Do not</b> use any built-in library function such as <code>sqrt</code>.</p>

<p><strong>Example 1:</strong></p>

<div>
<pre><strong>Input: </strong><span id="example-input-1-1">16</span>
<strong>Output: </strong><span id="example-output-1">true</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">14</span>
<strong>Output: </strong><span id="example-output-2">false</span>
</pre>
</div>
</div>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Sqrt(x) (Easy)](https://leetcode.com/problems/sqrtx/)
* [Sum of Square Numbers (Easy)](https://leetcode.com/problems/sum-of-square-numbers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/valid-perfect-square/
// Author: github.com/punkfulw
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    bool isPerfectSquare(int num) {
        for (long i = 1; i * i <= num; i++)
            if (i * i == num)
                return true;
        return false;
    }
};
```
