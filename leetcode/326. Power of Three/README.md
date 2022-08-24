# [326. Power of Three (Easy)](https://leetcode.com/problems/power-of-three/)

<p>Given an integer <code>n</code>, return <em><code>true</code> if it is a power of three. Otherwise, return <code>false</code></em>.</p>

<p>An integer <code>n</code> is a power of three, if there exists an integer <code>x</code> such that <code>n == 3<sup>x</sup></code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> n = 27
<strong>Output:</strong> true
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> n = 0
<strong>Output:</strong> false
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> n = 9
<strong>Output:</strong> true
</pre><p><strong>Example 4:</strong></p>
<pre><strong>Input:</strong> n = 45
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you solve it without loops/recursion?

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Power of Two (Easy)](https://leetcode.com/problems/power-of-two/)
* [Power of Four (Easy)](https://leetcode.com/problems/power-of-four/)
* [Check if Number is a Sum of Powers of Three (Medium)](https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/power-of-three/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        while (n != 1){
            if (n % 3)
                return false;
            n /= 3;
        }
        return true;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/power-of-three/solution/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/power-of-three/discuss/77872/Without-log-and-O(1).
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int const Max3PowerInt = 1162261467; // 3^19, 3^20 = 3486784401 > MaxInt32
    int const MaxInt32 = 2147483647; // 2^31 - 1
    bool isPowerOfThree(int n) {
        if (n <= 0 || n > Max3PowerInt) return false;
        return Max3PowerInt % n == 0;
    }
};
```
