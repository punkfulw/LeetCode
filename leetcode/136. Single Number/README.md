# [136. Single Number (Easy)](https://leetcode.com/problems/single-number/)

<p>Given a <strong>non-empty</strong>&nbsp;array of integers, every element appears <em>twice</em> except for one. Find that single one.</p>

<p>You must implement a solution with a linear runtime complexity and use only constant extra space.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [2,2,1]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [4,1,2,1,2]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> [1]
<strong>Output:</strong> 1
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
  <li><code>-3 * 10<sup>4</sup> &lt;= nums[i] &lt;= 3 * 10<sup>4</sup></code></li>
  <li>Each element in the array appears twice except for one element which appears only once.</li>
</ul>

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1. XOR

```cpp
// OJ: https://leetcode.com/problems/single-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i: nums)
            ans ^= i;
        return ans;
    }
};
```

## Solution 2.  Hash Table

```cpp
// OJ: https://leetcode.com/problems/single-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> cnt;
        int ans = 0;
        
        for (int i: nums){
            if (cnt.count(i) == 0){
                cnt.insert(i);
                ans += i;
            }
            else
                ans -= i;
        }
        return ans;
    }
};
```
