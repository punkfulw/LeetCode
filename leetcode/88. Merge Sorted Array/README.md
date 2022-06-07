# [88. Merge Sorted Array (Easy)](https://leetcode.com/problems/merge-sorted-array/)

<p>Given two sorted integer arrays <code>nums1</code> and <code>nums2</code>, merge <code>nums2</code> into <code>nums1</code> as one sorted array.</p>

<p>The number of elements initialized in <code>nums1</code> and <code>nums2</code> are <code>m</code> and <code>n</code> respectively. You may assume that <code>nums1</code> has enough space (size that is&nbsp;equal to <code>m + n</code>) to hold additional elements from <code>nums2</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
<strong>Output:</strong> [1,2,2,3,5,6]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums1 = [1], m = 1, nums2 = [], n = 0
<strong>Output:</strong> [1]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n, m &lt;= 200</code></li>
	<li><code>1 &lt;= n + m &lt;= 200</code></li>
	<li><code>nums1.length == m + n</code></li>
	<li><code>nums2.length == n</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums1[i], nums2[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Merge Two Sorted Lists (Easy)](https://leetcode.com/problems/merge-two-sorted-lists/)
* [Squares of a Sorted Array (Easy)](https://leetcode.com/problems/squares-of-a-sorted-array/)
* [Interval List Intersections (Medium)](https://leetcode.com/problems/interval-list-intersections/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/merge-sorted-array/
// Author: github.com/punkfulw
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m-1, q = n-1, i = n+m-1;
        while (p >= 0 && q >= 0){
            if (nums1[p] > nums2[q])
                nums1[i--] = nums1[p--];
            else
                nums1[i--] = nums2[q--];
        }
        while (q >= 0)
            nums1[i--] = nums2[q--];
    }
};
```

## Solution 1. -py
```python3
# OJ: https://leetcode.com/problems/merge-sorted-array/
# Author: github.com/punkfulw
# Time: O(M + N)
# Space: O(1)
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        p = m - 1
        q = n - 1
        i = m + n - 1
        while p >= 0 and q >= 0:
            if nums1[p] >= nums2[q]:
                nums1[i] = nums1[p]
                p -= 1
            else:
                nums1[i] = nums2[q]
                q -= 1
            i -= 1
        while q >= 0:
            nums1[i] = nums2[q]
            q -= 1
            i -= 1
```

## Solution 1. -2022

```cpp
// OJ: https://leetcode.com/problems/merge-sorted-array/
// Author: github.com/punkfulw
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, idx = n + m - 1;
        while (i >= 0 || j >= 0){
            if (i >= 0 && j >= 0)
                nums1[idx--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
            else if (i >= 0)
                nums1[idx--] = nums1[i--];
            else
                nums1[idx--] = nums2[j--];
        }
        return;
    }
};
```
