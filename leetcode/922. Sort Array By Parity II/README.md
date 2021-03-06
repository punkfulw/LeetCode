# [922. Sort Array By Parity II (Easy)](https://leetcode.com/problems/sort-array-by-parity-ii/)

<p>Given an array <code>A</code>&nbsp;of non-negative integers, half of the integers in A are odd, and half of the integers are even.</p>

<p>Sort the array so that whenever <code>A[i]</code> is odd, <code>i</code> is odd; and whenever <code>A[i]</code> is even, <code>i</code> is even.</p>

<p>You may return any answer array that satisfies this condition.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[4,2,5,7]</span>
<strong>Output: </strong><span id="example-output-1">[4,5,2,7]</span>
<strong>Explanation: </strong>[4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>2 &lt;= A.length &lt;= 20000</code></li>
	<li><code>A.length % 2 == 0</code></li>
	<li><code>0 &lt;= A[i] &lt;= 1000</code></li>
</ol>

<div>
<p>&nbsp;</p>
</div>


## Solution 1. Two Pointers
```cpp
// OJ: https://leetcode.com/problems/sort-array-by-parity-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0, j = 1; i < n; i += 2, j += 2){
            while (i < n && nums[i] % 2 == 0)
                i += 2;
            while (j < n && nums[j] % 2 != 0)
                j += 2;
            if (i < n)
                swap(nums[i], nums[j]);
        }
        return nums;
    }
};
```
