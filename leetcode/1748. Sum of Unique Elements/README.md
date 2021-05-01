# [1748. Sum of Unique Elements (Easy)](https://leetcode.com/problems/sum-of-unique-elements/)

<p>You are given an integer array <code>nums</code>. The unique elements of an array are the elements that appear <b>exactly once</b> in the array.</p>

<p>Return <em>the <b>sum</b> of all the unique elements of</em> <code>nums</code>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1,1,1]
<strong>Output:</strong> 4
<strong>Explanation: </strong> The unique elements are [1,3], and the sum is 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1,1,1]
<strong>Output:</strong> 0
<strong>Explanation: </strong> There are no unique elements, and the sum is 0.
</pre>


<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4,5]
<strong>Output:</strong> 15
<strong>Explanation: </strong> The unique elements are [1,2,3,4,5], and the sum is 15.
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums.length &lt;= 100</code></li>
  <li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

1 <= nums.length <= 100
1 <= nums[i] <= 100

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sum-of-unique-elements/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans {};
        unordered_map<int, int> m {};
        
        for(int i: nums){
            int cnt = ++m[i];
            ans += cnt == 1 ? i : 0;
            ans += cnt == 2 ? -i : 0;
        }
        return ans;
    }
};
```
