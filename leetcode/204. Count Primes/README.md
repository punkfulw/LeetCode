# [204. Count Primes (Easy)](https://leetcode.com/problems/count-primes/)

<p>Count the number of prime numbers less than a non-negative number, <code>n</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 10
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 0
<strong>Output:</strong> 0
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 5 * 10<sup>6</sup></code></li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Ugly Number (Easy)](https://leetcode.com/problems/ugly-number/)
* [Ugly Number II (Medium)](https://leetcode.com/problems/ugly-number-ii/)
* [Perfect Squares (Medium)](https://leetcode.com/problems/perfect-squares/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/count-primes/
// Author: github.com/punkfulw
// Time: O(NloglogN)
// Space: O(N)
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrimes(n, true);
        for (int i = 2; i * i < n; i++){
            if (!isPrimes[i])
                continue;
            for (int j = i * i; j < n; j += i){
                isPrimes[j] = false;
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; i++){
            if (isPrimes[i])
                cnt++;
        }
        return cnt;
    }
};
```
