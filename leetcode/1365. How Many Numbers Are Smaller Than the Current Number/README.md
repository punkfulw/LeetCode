# [1365. How Many Numbers Are Smaller Than the Current Number (Easy)](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/)

<p>Given the array <code>nums</code>, for each <code>nums[i]</code> find out how many numbers in the array are smaller than it. 
  That is, for each <code>nums[i]</code> you have to count the number of valid <code>j's</code> such that <code>j != i</code> <b>and</b> <code>nums[j]</code> < <code>nums[i]</code>.</p>

<p>Return the answer in an array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [8,1,2,2,3]
<strong>Output:</strong> [4,0,1,1,3]
<strong>Explanation: </strong> 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
</pre>

<p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [6,5,4,8]
<strong>Output:</strong> [2,1,0,3]
</pre>


<p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [7,7,7,7]
<strong>Output:</strong> [0,0,0,0]
</pre>

2 <= nums.length <= 500
0 <= nums[i] <= 100


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 500</code></li>
  <li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/)
[Hash Table](https://leetcode.com/tag/hash-table/)



## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(M) M = number of different int
// Ref: https://leetcode.com/problems/number-of-days-between-two-dates/discuss/517605/Similar-to-day-of-the-year
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> values;
        vector<int> numsCopy = nums;
        int numsSize = nums.size();
        sort(numsCopy.begin(), numsCopy.end(), greater<int>());
        for(int i = 0 ; i < numsSize; i++){
            values[numsCopy[i]] = ((numsSize-1) - i);
        }
        for(int i = 0; i < numsSize; i++) {
            nums[i] = values[nums[i]];
        }
        return nums;     
    }
};
```
