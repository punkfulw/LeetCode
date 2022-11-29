# [7. Reverse Integer (Easy)](https://leetcode.com/problems/reverse-integer/)

<p>Given a 32-bit signed integer, reverse digits of an integer.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 123
<strong>Output:</strong> 321
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> -123
<strong>Output:</strong> -321
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> 120
<strong>Output:</strong> 21
</pre>

<p><strong>Note:</strong><br>
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2<sup>31</sup>,&nbsp; 2<sup>31&nbsp;</sup>− 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.</p>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [String to Integer (atoi) (Medium)](https://leetcode.com/problems/string-to-integer-atoi/)
* [Reverse Bits (Easy)](https://leetcode.com/problems/reverse-bits/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reverse-integer/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int reverse(int x) {
        int ans = 0, limit1 = INT_MAX / 10, limit2 = INT_MIN / 10, remain1 = INT_MAX % 10, remain2 = INT_MIN % 10;
        while (x){
            if (ans > limit1 || ans < limit2)
                return 0;
            if (ans == limit1 && x % 10 == remain1)
                return 0;
            if (ans == limit2 && x % 10 == remain2)
                return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};
```
