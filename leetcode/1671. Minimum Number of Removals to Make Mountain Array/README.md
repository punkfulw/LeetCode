# [1671. Minimum Number of Removals to Make Mountain Array (Hard)](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/)

<p>You may recall that an array <code>arr</code> is a <strong>mountain array</strong> if and only if:</p>

<ul>
	<li><code>arr.length &gt;= 3</code></li>
	<li>There exists some index <code>i</code> (<strong>0-indexed</strong>) with <code>0 &lt; i &lt; arr.length - 1</code> such that:
	<ul>
		<li><code>arr[0] &lt; arr[1] &lt; ... &lt; arr[i - 1] &lt; arr[i]</code></li>
		<li><code>arr[i] &gt; arr[i + 1] &gt; ... &gt; arr[arr.length - 1]</code></li>
	</ul>
	</li>
</ul>

<p>Given an integer array <code>nums</code>​​​, return <em>the <strong>minimum</strong> number of elements to remove to make </em><code>nums<em>​​​</em></code><em> </em><em>a <strong>mountain array</strong>.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The array itself is a mountain array so we do not need to remove any elements.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,1,1,5,6,2,3,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [4,3,2,1,1,2,3,1]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4,4,3,2,1]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>It is guaranteed that you can make a mountain array out of <code>nums</code>.</li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)
* [Longest Mountain in Array (Medium)](https://leetcode.com/problems/longest-mountain-in-array/)
* [Peak Index in a Mountain Array (Easy)](https://leetcode.com/problems/peak-index-in-a-mountain-array/)
* [Valid Mountain Array (Easy)](https://leetcode.com/problems/valid-mountain-array/)
* [Find in Mountain Array (Hard)](https://leetcode.com/problems/find-in-mountain-array/)

## Solution 1. Find peak


```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    void build(vector<int> &arr, int i, int end, int dir, vector<int> &nums){
        vector<int> stk;
        while (i != end){
            if (stk.empty() || nums[i] > stk.back()){
                stk.push_back(nums[i]);
                arr[i] = stk.size() - 1;
            }
            else{
                auto it = lower_bound(stk.begin(), stk.end(), nums[i]);
                arr[i] = it - stk.begin();
                *it = nums[i];
            } 
            i += dir;
        }
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX / 2;
        vector<int> left(n), right(n);
        
        build(left, 0, n, 1, nums);
        build(right, n - 1, -1, -1, nums);
        
        for (int i = 0; i < n; i++){
            if (left[i] == 0 || right[i] == 0) continue;
            int cur = (i - left[i]) + ((n - i - 1) - right[i]);
            ans = min(ans, cur);
        }
        
        return ans;        
    }
};
```
