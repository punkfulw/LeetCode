# [1175. Prime Arrangements (Easy)](https://leetcode.com/problems/prime-arrangements/)

<p>Return the number of permutations of 1 to <code>n</code> so that prime numbers are at prime indices (1-indexed.)</p>

<p><em>(Recall that an integer&nbsp;is prime if and only if it is greater than 1, and cannot be written as a product of two positive integers&nbsp;both smaller than it.)</em></p>

<p>Since the answer may be large, return the answer <strong>modulo <code>10^9 + 7</code></strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 5
<strong>Output:</strong> 12
<strong>Explanation:</strong> For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5 is at index 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 100
<strong>Output:</strong> 682289015
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/prime-arrangements/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    bool isPrime(int n){
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }
    int numPrimeArrangements(int n) {
        if (n <= 2) return 1;
        int mod = 1e9 + 7, ans = 1, cnt = 0;
        for (int i = 2; i <= n; i++)
            cnt += isPrime(i);
        long pnum = cnt ? 1 : 0, notP = n - cnt, npnum = notP ? 1 : 0;
        while (cnt)
            pnum = (pnum * cnt--) % mod;
        while (notP)
            npnum = (npnum * notP--) % mod;
        return (pnum * npnum) % mod;
    }
};
```
