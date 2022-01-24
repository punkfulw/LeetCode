# [2148. Count Elements With Strictly Smaller and Greater Elements  (Easy)](https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/)

<p>Given an integer array <code>nums</code>, return <em>the number of elements that have <strong>both</strong> a strictly smaller and a strictly greater element appear in </em><code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [11,7,2,15]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The element 7 has the element 2 strictly smaller than it and the element 11 strictly greater than it.
Element 11 has element 7 strictly smaller than it and element 15 strictly greater than it.
In total there are 2 elements having both a strictly smaller and a strictly greater element appear in <code>nums</code>.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [-3,3,3,90]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The element 3 has the element -3 strictly smaller than it and the element 90 strictly greater than it.
Since there are two elements with the value 3, in total there are 2 elements having both a strictly smaller and a strictly greater element appear in <code>nums</code>.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Find Smallest Letter Greater Than Target (Easy)](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)




## Solution 1. Exclude Smallest and Greatest Elements

```cpp
// OJ: https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        sort(nums.begin(), nums.end());
        
        if (n == 1 || nums[l] == nums[r])
            return 0;
        while (nums[l+1] == nums[l])
            l++;
        while (nums[r-1] == nums[r])
            r--;
        return max(0, r - l - 1);
    }
};
```

