# [762. Prime Number of Set Bits in Binary Representation (Easy)](https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/)

<p>Given two integers <code>left</code> and <code>right</code>, find the count of numbers in the range <code>[left, right]</code> (inclusive) having a prime number of set bits in their binary representation.</p>

<p>(Recall that the number of set bits an integer has is the number of <code>1</code>s present when written in binary.  For example, <code>21</code> written in binary is <code>10101</code> which has 3 set bits.  Also, 1 is not a prime.)</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> left = 6, right = 10
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)
</pre>


<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> left = 10, right = 15
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
</pre>

<p><b>Note:</b><br></p><ol>
<li><code>left, right</code> will be integers <code>left &lt;= right</code> in the range <code>[1, 10^6]</code>.</li>
<li><code>right - left</code> will be at most 10000.</li>
</ol><p></p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Number of 1 Bits (Easy)](https://leetcode.com/problems/number-of-1-bits/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++){
            int cur = 0, num = i;
            while (num > 0){
                cur = cur + num % 2;
                num /= 2;
            }
            if (isPrime(cur))
                ans++;
        }
        return ans;
    }
    
    bool isPrime(int n){
        if (n == 2) return true;
        if (n == 1 || n % 2 == 0) return false;
        for (int i = 3; i <= sqrt(n); i += 2){
            if (n % i == 0)
                return false;
        }
        return true;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        set<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for (int i = left; i <= right; i++){
            int cur = 0, num = i;
            while (num > 0){
                cur = cur + num % 2;
                num /= 2;
            }
            if (p.count(cur))
                ans++;
        }
        return ans;
    }
};
```
