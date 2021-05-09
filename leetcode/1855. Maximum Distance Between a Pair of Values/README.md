# [1855. Maximum Distance Between a Pair of Values (Medium)](https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/)

<p>You are given two <b>non-increasing 0-indexed</b> integer arrays <code>nums1</code> and <code>ums2</code>.</p>

<p>A pair of indices <code>(i, j)</code>, where <code>0 <= i < nums1.length</code> and <code>0 <= j < nums2.length</code>,
  is <b>valid</b> if both <code>i <= j</code> and <code>nums1[i] <= nums2[j]</code>.
  The <b>distance</b> of the pair is <code>j - i</code>.</p>

<p>Return <em>the <b>maximum distance</b> of any </b>valid</b> pair </em><code>(i, j)</code>.<em> If there are no valid pairs, return</em> <code>0</code>.</p>

<p>An array <code>arr</code> is <b>non-increasing</b> if <code> arr[i-1] >= arr[i]</code> for every <code> 1 <= i < arr.length</code>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
<strong>Output:</strong> 2
<strong>Explanation: </strong>The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
The maximum distance is 2 with pair (2,4).
</pre>


<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [2,2,2], nums2 = [10,10,1]
<strong>Output:</strong> 1
<strong>Explanation: </strong>The valid pairs are (0,0), (0,1), and (1,1).
The maximum distance is 1 with pair (0,1).
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
<strong>Output:</strong> 2
<strong>Explanation: </strong>The valid pairs are (2,2), (2,3), (2,4), (3,3), and (3,4).
The maximum distance is 2 with pair (2,4).
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums1 = [5,4], nums2 = [3,2]
<strong>Output:</strong> 0
<strong>Explanation: </strong>There are no valid pairs, so return 0.
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums1.length &lt;= 10<sup>5</sup></code></li>
  <li><code>1 &lt;= nums2.length &lt;= 10<sup>5</sup></code></li>
  <li><code>1 &lt;= nums1[i], nums2[j] &lt;= 10<sup>5</sup></code></li>
  <li>Both <code>nums1</code> and <code>nums2</code> are <b>non-increasing</b>.</li>
</ul>


**Related Topics**:  
[Two Pointer](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/), [Greedy](https://leetcode.com/tag/greedy/)



## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
// Author: github.com/punkfulw
// Time: O(N+M)
// Space: O(1)
class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
        int i = 0, j = 0, res = 0;
        int n = A.size();
        int m = B.size();
        
        while (i < n && j < m){
            if (A[i] > B[j]){
                i++;
            }
            else{
                res = max(res, j - i);
                j++;
            }
        }
        return res;
    }
};
```
