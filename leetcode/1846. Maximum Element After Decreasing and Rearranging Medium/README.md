# [1846. Maximum Element After Decreasing and Rearranging (Medium)](https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/)

<p>You are given an array of positive integers <code>arr</code>. Perform some operations (possibly none) on <code>arr</code> so that it satisfies these conditions:</p>

<ul>
  <li>The value of the <b>first</b> element in <code>arr</code> must be <code>1</code>.</li>
  <li>The absolute difference between any 2 adjacent elements must be <b>less than or equal to</b> <code>1</code>. In other words,
 <code>abs(arr[i] - arr[i - 1]) <= 1</code> for each <code>i</code> where <code>1 <= i < arr.length </code>(<b>0-indexed</b>).
   <code>abs(x)</code> is the absolute value of <code>x.</code></li>
</ul>

<p>There are 2 types of operations that you can perform any number of times:</p>

<ul>
  <li><b>Decrease</b> the value of any element of arr to a <b>smaller positive integer</b>.</li>
  <li><b>Rearrange</b> the elements of <code>arr</code> to be in any order.</li>
</ul>

<p>Return <em>the <b>maximum</b> possible value of an element in</em> <code>arr</code> <em>after performing the operations to satisfy the conditions.</em></p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [2,2,1,2,1]
<strong>Output:</strong> 2
<strong>Explanation: </strong>
We can satisfy the conditions by rearranging arr so it becomes [1,2,2,2,1].
The largest element in arr is 2.
</pre>


<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [100,1,1000]
<strong>Output:</strong> 3
<strong>Explanation: </strong>
One possible way to satisfy the conditions is by doing the following:
1. Rearrange arr so it becomes [1,100,1000].
2. Decrease the value of the second element to 2.
3. Decrease the value of the third element to 3.
Now arr = [1,2,3], which satisfies the conditions.
The largest element in arr is 3.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,3,4,5]
<strong>Output:</strong> 5
<strong>Explanation: </strong>The array already satisfies the conditions, and the largest element is 5.
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
  <li><code>1 &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
</ul>

1 <= arr.length <= 105
1 <= arr[i] <= 109

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/), [Sort](https://leetcode.com/tag/sort/)



## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        int ans = 1, i = 1;
        
        for (int num: arr){
            ans = min(i, num);
            if (num >= i)
                i++;
        }
        return ans;
    }
};
```
