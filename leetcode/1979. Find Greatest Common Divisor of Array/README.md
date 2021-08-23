# [1979. Find Greatest Common Divisor of Array (Easy)](https://leetcode.com/problems/find-greatest-common-divisor-of-array/)

<p>Given an integer array <code>nums</code>, return<strong> </strong><em>the <strong>greatest common divisor</strong> of the smallest number and largest number in </em><code>nums</code>.</p>

<p>The <strong>greatest common divisor</strong> of two numbers is the largest positive integer that evenly divides both numbers.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,5,6,9,10]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [7,5,6,8,3]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
The smallest number in nums is 3.
The largest number in nums is 8.
The greatest common divisor of 3 and 8 is 1.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong>
The smallest number in nums is 3.
The largest number in nums is 3.
The greatest common divisor of 3 and 3 is 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


**Similar Questions**:
* [Greatest Common Divisor of Strings (Easy)](https://leetcode.com/problems/greatest-common-divisor-of-strings/)
* [Number of Different Subsequences GCDs (Hard)](https://leetcode.com/problems/number-of-different-subsequences-gcds/)
* [Three Divisors (Easy)](https://leetcode.com/problems/three-divisors/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        return gcd(mx, mn);
    }
    int gcd(int a, int b){
        if (b == 0) return a;
        return (gcd(b, a % b));
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        int ans;
        for (int i = 1; i <= mn; i++){
            if (mn % i == 0 && mx % i == 0)
                ans = i;
        }
        return ans;
    }
};
```
