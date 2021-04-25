# [1837. Sum of Digits in Base K (Easy)](https://leetcode.com/problems/sum-of-digits-in-base-k/)

<p>Given an integer <code>n</code> (in base <code>10</code>) and a base <code>k</code>, <em>return the <b>sum</b> of the digits of </em><code>n</code><em>
  <b>after</b> converting</em> <code>n</code> <em>from base</em> <code>10</code> <em>to base</em> <code>k</code></em>.</p>

<p>After converting, each digit should be interpreted as a base <code>10</code> number, and the sum should be returned in base <code>10</code>.</p>

nput: n = 34, k = 6
Output: 9
Explanation: 34 (base 10) expressed in base 6 is 54. 5 + 4 = 9.
Example 2:

Input: n = 10, k = 10
Output: 1
Explanation: n is already in base 10. 1 + 0 = 1.
 

Constraints:

1 <= n <= 100
2 <= k <= 10


<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 34, k = 6
<strong>Output:</strong> 9
<strong>Explanation:</strong> 34 (base 10) expressed in base 6 is 54. 5 + 4 = 9.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 10, k = 10
<strong>Output:</strong> 1
<strong>Explanation:</strong> n is already in base 10. 1 + 0 = 1.
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>2 &lt;= k &lt;= 10</code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/) [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/sum-of-digits-in-base-k/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1) 
class Solution {
public:
    int sumBase(int n, int k) {
        int ans {};
        
        while (n >= k){
            int add = n % k;
            n /= k;
            ans += add; 
        }
        return ans + n;
    }
};
```
