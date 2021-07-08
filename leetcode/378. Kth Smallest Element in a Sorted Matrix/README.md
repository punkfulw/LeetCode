# [378. Kth Smallest Element in a Sorted Matrix (Medium)](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)

<p>Given an <code>n x n</code> <code>matrix</code> where each of the rows and columns are sorted in ascending order, return <em>the</em> <code>k<sup>th</sup></code> <em>smallest element in the matrix</em>.</p>

<p>Note that it is the <code>k<sup>th</sup></code> smallest element <strong>in the sorted order</strong>, not the <code>k<sup>th</sup></code> <strong>distinct</strong> element.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
<strong>Output:</strong> 13
<strong>Explanation:</strong> The elements in the matrix are [1,5,9,10,11,12,13,<u><strong>13</strong></u>,15], and the 8<sup>th</sup> smallest number is 13
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> matrix = [[-5]], k = 1
<strong>Output:</strong> -5
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 300</code></li>
	<li><code>-10<sup>9</sup> &lt;= matrix[i][j] &lt;= 10<sup>9</sup></code></li>
	<li>All the rows and columns of <code>matrix</code> are <strong>guaranteed</strong> to be sorted in <strong>non-decreasing order</strong>.</li>
	<li><code>1 &lt;= k &lt;= n<sup>2</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Find K Pairs with Smallest Sums (Medium)](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)
* [Kth Smallest Number in Multiplication Table (Hard)](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/)
* [Find K-th Smallest Pair Distance (Hard)](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)
* [K-th Smallest Prime Fraction (Hard)](https://leetcode.com/problems/k-th-smallest-prime-fraction/)

## Solution 1. Burte Force

```cpp
// OJ: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> cnt;
        
        for (auto vec: matrix)
            for (int i: vec)
                cnt.push_back(i);
        
        sort(cnt.begin(), cnt.end());
        return cnt[k-1];
    }
};
```

## Solution 2. Binary Search

```cpp
// OJ: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Author: github.com/punkfulw
//Reference: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/378.%20Kth%20Smallest%20Element%20in%20a%20Sorted%20Matrix/README.md
// Time: O(Nlog(max(A)))
// Space: O(1)
class Solution {
    int rank(vector<vector<int>> &A, int num) {
        int N = A.size(), cnt = 0, j = N - 1;
        for (int i = 0; i < N; ++i) {
            while (j >= 0 && A[i][j] > num) --j;
            cnt += j + 1;
        }
        return cnt;
    }
public:
    int kthSmallest(vector<vector<int>>& A, int k) {
        int N = A.size(), L = A[0][0], R = A[N - 1][N - 1];
        while (L < R) {
            int M = (L + R) / 2;
            if (rank(A, M) < k) L = M + 1;
            else R = M;
        }
        return L;
    }
};
```
