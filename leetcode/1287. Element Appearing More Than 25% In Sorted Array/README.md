# [1287. Element Appearing More Than 25% In Sorted Array (Easy)](https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/)

<p>Given an&nbsp;integer array&nbsp;<strong>sorted</strong> in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time.</p>

<p>Return that integer.</p>

<p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> arr = [1,2,2,6,6,6,6,7,10]
<strong>Output:</strong> 6
</pre>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> arr = [1,1]
<strong>Output:</strong> 1
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)



## Solution 1. Binary Search

```cpp
// OJ: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int sz = arr.size();
        int candidates[3] = {arr[sz/4], arr[sz/2], arr[sz*3/4]};
        for (auto cand: candidates){
            auto st = lower_bound(arr.begin(), arr.end(), cand);
            auto ed = upper_bound(arr.begin(), arr.end(), cand);
            if (distance(st, ed) * 4 > sz)
                return cand;
        }
        return -1;
    }
};
```


## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), part = n / 4;
        for (int i = 0; i < N - part; ++i) {
            if (A[i] == A[i + part]) return A[i];
        }
        return -1;
    }
};
```
