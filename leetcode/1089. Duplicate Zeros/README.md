# [1089. Duplicate Zeros (Easy)](https://leetcode.com/problems/duplicate-zeros/)

<p>Given a fixed length&nbsp;array <code>arr</code> of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.</p>

<p>Note that elements beyond the length of the original array are not written.</p>

<p>Do the above modifications to the input array <strong>in place</strong>, do not return anything from your function.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[1,0,2,3,0,4,5,0]</span>
<strong>Output: </strong>null
<strong>Explanation: </strong>After calling your function, the <strong>input</strong> array is modified to: <span id="example-output-1">[1,0,0,2,3,0,0,4]</span>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[1,2,3]</span>
<strong>Output: </strong>null
<strong>Explanation: </strong>After calling your function, the <strong>input</strong> array is modified to: <span id="example-output-2">[1,2,3]</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= arr.length &lt;= 10000</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 9</code></li>
</ol>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1. insert

```cpp
// OJ: https://leetcode.com/problems/duplicate-zeros/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++){
            if (arr[i])
                continue;
            arr.pop_back();
            arr.insert(arr.begin() + i, 0);
            i++;
        }
        return;
    }
};
```

## Solution 2. two pointer

```cpp
// OJ: https://leetcode.com/problems/duplicate-zeros/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/duplicate-zeros/discuss/312727/C%2B%2BJava-Two-Pointers-Space-O(1)
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void duplicateZeros(vector<int>& A) {
        int n = A.size(), j = n + count(A.begin(), A.end(), 0);
        for (int i = n - 1; i >= 0; --i) {
            if (--j < n)
                A[j] = A[i];
            if (A[i] == 0 && --j < n)
                A[j] = 0;
        }
    }
};
```
