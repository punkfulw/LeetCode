# [2161. Partition Array According to Given Pivot (Medium)](https://leetcode.com/problems/partition-array-according-to-given-pivot/)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> and an integer <code>pivot</code>. Rearrange <code>nums</code> such that the following conditions are satisfied:</p>

<ul>
	<li>Every element less than <code>pivot</code> appears <strong>before</strong> every element greater than <code>pivot</code>.</li>
	<li>Every element equal to <code>pivot</code> appears <strong>in between</strong> the elements less than and greater than <code>pivot</code>.</li>
	<li>The <strong>relative order</strong> of the elements less than <code>pivot</code> and the elements greater than <code>pivot</code> is maintained.
	<ul>
		<li>More formally, consider every <code>p<sub>i</sub></code>, <code>p<sub>j</sub></code> where <code>p<sub>i</sub></code> is the new position of the <code>i<sup>th</sup></code> element and <code>p<sub>j</sub></code> is the new position of the <code>j<sup>th</sup></code> element. For elements less than <code>pivot</code>, if <code>i &lt; j</code> and <code>nums[i] &lt; pivot</code> and <code>nums[j] &lt; pivot</code>, then <code>p<sub>i</sub> &lt; p<sub>j</sub></code>. Similarly for elements greater than <code>pivot</code>, if <code>i &lt; j</code> and <code>nums[i] &gt; pivot</code> and <code>nums[j] &gt; pivot</code>, then <code>p<sub>i</sub> &lt; p<sub>j</sub></code>.</li>
	</ul>
	</li>
</ul>

<p>Return <code>nums</code><em> after the rearrangement.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [9,12,5,10,14,3,10], pivot = 10
<strong>Output:</strong> [9,5,3,10,10,12,14]
<strong>Explanation:</strong> 
The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [-3,4,3,2], pivot = 2
<strong>Output:</strong> [-3,2,4,3]
<strong>Explanation:</strong> 
The element -3 is less than the pivot so it is on the left side of the array.
The elements 4 and 3 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [-3] and [4, 3] are the respective orderings.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>6</sup> &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>pivot</code> equals to an element of <code>nums</code>.</li>
</ul>


**Similar Questions**:
* [Partition List (Medium)](https://leetcode.com/problems/partition-list/)
* [Rearrange Array Elements by Sign (Medium)](https://leetcode.com/problems/rearrange-array-elements-by-sign/)

## Solution 1. 2 Pass 3 Pointers

```cpp
// OJ: https://leetcode.com/problems/partition-array-according-to-given-pivot/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {
        int n = nums.size(), small = 0, equal = 0, big = 0;
        
        for (auto &i: nums){
            if (i > p) big++;
            else if (i == p) equal++;
            else small++;
        }
        int pos_s = 0, pos_e = small, pos_b = small + equal;
        vector<int> ans(n);
        for (int i = 0; i < n; i++){
            if (nums[i] < p)
                ans[pos_s++] = nums[i];
            else if (nums[i] == p)
                ans[pos_e++] = nums[i];
            else
                ans[pos_b++] = nums[i];  
        }
        
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/partition-array-according-to-given-pivot/discuss/1746999

The above post was hidden for no reason...

https://leetcode.com/problems/partition-array-according-to-given-pivot/discuss/1747363
