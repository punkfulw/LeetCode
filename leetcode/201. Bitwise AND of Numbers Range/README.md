# [201. Bitwise AND of Numbers Range (Medium)](https://leetcode.com/problems/bitwise-and-of-numbers-range/)

<p>Given two integers <code>left</code> and <code>right</code> that represent the range <code>[left, right]</code>, return <em>the bitwise AND of all numbers in this range, inclusive</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> left = 5, right = 7
<strong>Output:</strong> 4
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> left = 0, right = 0
<strong>Output:</strong> 0
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> left = 1, right = 2147483647
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= left &lt;= right &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1. Recusion

```cpp
// OJ: https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Author: github.com/punkfulw
// Time: O(logN) 
// Space: O(logN)
class Solution {
public:
    int sol(int n){
        int ans = 0;
        while (n){
            ans++;
            n >>= 1;
        }
        return ans;
    }
    int rangeBitwiseAnd(int left, int right) {
        int a = sol(left), b = sol(right);
        if (a == 0 || b == 0) return 0;
        int highestBit = pow(2, a - 1);
        if (a == b)
            return highestBit + rangeBitwiseAnd(left - highestBit, right - highestBit);
        return 0;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Author: github.com/punkfulw
// Time: O(logN) 
// Space: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int recover = 0;
        while (left != right){
            recover++;
            left >>= 1;
            right >>= 1;
        }
        return left << recover;
    }
};
```
