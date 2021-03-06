# [905. Sort Array By Parity (Easy)](https://leetcode.com/problems/sort-array-by-parity/)

<p>Given an array <code>A</code> of non-negative integers, return an array consisting of all the even elements of <code>A</code>, followed by all the odd elements of <code>A</code>.</p>

<p>You may return any answer array that satisfies this condition.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[3,1,2,4]</span>
<strong>Output: </strong><span id="example-output-1">[2,4,3,1]</span>
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 5000</code></li>
	<li><code>0 &lt;= A[i] &lt;= 5000</code></li>
</ol>
</div>

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/sort-array-by-parity/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        size_t i = 0;
        size_t j = A.size()-1;
        vector<int> ans = A;
        
        for (int num: A){
            (num % 2) ? ans[j--] = num : ans[i++] = num;
        }
        return ans;        
    }
};
```


## Solution 2.  In place

```cpp
// OJ: https://leetcode.com/problems/sort-array-by-parity/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        
        for (int i = 0, j = 0; j < n; j++)
            if (nums[j] % 2 == 0)
                swap(nums[i++], nums[j]);
        return nums;
    }
};
```

## Solution 2.  In place -py

```python3
# OJ: https://leetcode.com/problems/sort-array-by-parity/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        i = 0
        for j, num in enumerate(nums):
            if num % 2 == 0:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
        return nums
```
