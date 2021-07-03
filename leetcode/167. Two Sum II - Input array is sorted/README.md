# [167. Two Sum II - Input array is sorted (Easy)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

<p>Given an array of integers <code>numbers</code> that is already <b><em>sorted in non-decreasing order</b></em>, 
  find two numbers such that they add up to a specific <code>target</code> number.</p>

<p>Return <em>the indices of the two numbers (<b>1-indexed</b>) as an integer array </em><code>answer</code><em> of size </em><code>2</code>, 
 <em>where</em> <code>1 <= answer[0] < answer[1] <= numbers.length</code>.</p>

<p>The tests are generated such that there is <b>exactly one solution</b>. You <b>may not</b> use the same element twice.</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> numbers = [2,7,11,15], target = 9
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> numbers = [2,3,4], target = 6
<strong>Output:</strong> [1,3]
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> numbers = [-1,0], target = -1
<strong>Output:</strong> [1,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>2 &lt;= numbers.length &lt;= 3 * 10<sup>4</sup></code></li>
  <li><code>-1000 &lt;= numbers[i] &lt;= 1000</code></li>
  <li><code>numbers</code> is sorted in <b>non-decreasing order</b>.</li>
  <li><code>-1000 &lt;= target &lt;= 1000</code></li>
  <li>The tests are generated such that there is <b>exactly one solution</b>.</li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/)


## Solution 1. map

```cpp
// OJ: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++){
            if (mp[nums[i]])
                return {mp[nums[i]], i+1};
            else
                mp[target - nums[i]] = i+1;
        }
        return {};
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while (nums[l] + nums[r] != target){
            if (nums[l] + nums[r] > target)
                r--;
            else
                l++;
        }
        return {l+1, r+1};
    }
};
```
