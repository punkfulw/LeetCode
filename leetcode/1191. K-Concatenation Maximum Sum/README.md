# [1191. K-Concatenation Maximum Sum (Medium)](https://leetcode.com/problems/k-concatenation-maximum-sum/)

<p>Given an integer array <code>arr</code> and an integer <code>k</code>, modify the array by repeating it <code>k</code> times.</p>

<p>For example, if <code>arr = [1, 2]</code> and <code>k = 3 </code>then the modified array will be <code>[1, 2, 1, 2, 1, 2]</code>.</p>

<p>Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be <code>0</code> and its sum in that case is <code>0</code>.</p>

<p>As the answer can be very large, return the answer <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,2], k = 3
<strong>Output:</strong> 9
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,-2,1], k = 5
<strong>Output:</strong> 2
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [-1,-2], k = 7
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= arr[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. pre + suf or sub

```cpp
// OJ: https://leetcode.com/problems/k-concatenation-maximum-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int MOD = 1e9 + 7, n = arr.size();
        int pre = 0, suf = 0, sub = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0; 
        for (int i = 0; i < n; i++){
            cnt1 += arr[i];
            cnt2 += arr[n - 1 - i];
            cnt3 += arr[i];
            if (cnt3 < 0) cnt3 = 0;
            pre = max(pre, cnt1);
            suf = max(suf, cnt2);
            sub = max(sub, cnt3);
        }
        if (k == 1) 
            return sub % MOD;
        if (cnt1 > 0) 
            return ((k - 2) * (long long)cnt1 % MOD + pre + suf) % MOD;
        return max(sub, suf + pre) % MOD;
    }
};
```
