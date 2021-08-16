# [303. Range Sum Query - Immutable (Easy)](https://leetcode.com/problems/range-sum-query-immutable/)

<p>Given an integer array <code>nums</code>, handle multiple queries of the following type:</p>

<ul>
  <li>Calculate the <b>sum</b> of the elements of <code>nums</code> between indices <code>left</code> and <code>right</code> <b>inclusive</b> where <code>left <= right</code>.</li>
</ul>

 
<p>Implement the <code>NumArray</code> class:</p>

<ul>
  <li><code>NumArray(int[] nums)</code> Initializes the object with the integer array <code>nums</code>.</li>
  <li><code>int sumRange(int left, int right)</code> Returns the sum of the elements of <code>nums</code> between indices <code>left</code> and <code>right</code> inclusive (i.e. <code>nums[left] + nums[left + 1] + ... + nums[right]</code>).</li>
</ul>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> 
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
<strong>Output:</strong> 
[null, 1, -1, -3]
<strong>Explanation:</strong> 
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
  <li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
  <li><code>0 &lt;= left &lt;= right &lt; nums.length</code></li>
  <li>At most <code>10<sup>4</sup></code> calls will be made to <code>sumRange</code>.</li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Design](https://leetcode.com/tag/design/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)


## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/range-sum-query-immutable/
// Author: github.com/punkfulw
// Time: O(N) for build partial_sum
//       O(1) for calling SumRange
// Space: O(N)
class NumArray {
public:
    vector<int> cnt;
    NumArray(vector<int>& nums) : cnt(nums.size()+1, 0){
        partial_sum(nums.begin(), nums.end(), cnt.begin()+1);
    }
    
    int sumRange(int left, int right) {
        return cnt[right+1] - cnt[left];
    }
};
```
