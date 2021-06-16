# [169. Majority Element (Easy)](https://leetcode.com/problems/majority-element/)

<p>Given an array <code>nums</code> of size <code>n</code>, return <em>the majority element.</em></p>

<p>The majority element is the element that appears more than <code>⌊n / 2⌋</code> times. You may assume that the majority element always exists in the array.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [3,2,3]
<strong>Output:</strong> 3</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [2,2,1,1,1,2,2]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>n == nums.length</code></li>
  <li><code>-1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
  <li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1. Hash Table

```cpp
// OJ: https://leetcode.com/problems/majority-element/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++){
            mp[nums[i]]++;
            if (i >= n / 2 && mp[nums[i]] > n/2)
                return nums[i];
        }
        return 0;
    }
};
```

## Solution 2. Moore's voting algorithm

```cpp
// OJ: https://leetcode.com/problems/majority-element/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityIndex = 0;
        for (int i = 1, count = 1; i < nums.size(); i++){
            nums[majorityIndex] == nums[i] ? count++ : count--;
            if (count == 0){
                majorityIndex = i;
                count = 1;
            }
        }
        return nums[majorityIndex];
    }
};
```
