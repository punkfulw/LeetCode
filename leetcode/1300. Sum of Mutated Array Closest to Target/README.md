# [1300. Sum of Mutated Array Closest to Target (Medium)](https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/)

<p>Given an integer array&nbsp;<code>arr</code> and a target value <code>target</code>, return&nbsp;the integer&nbsp;<code>value</code>&nbsp;such that when we change all the integers&nbsp;larger than <code>value</code>&nbsp;in the given array to be equal to&nbsp;<code>value</code>,&nbsp;the sum of the array gets&nbsp;as close as possible (in absolute difference) to&nbsp;<code>target</code>.</p>

<p>In case of a tie, return the minimum such integer.</p>

<p>Notice that the answer is not neccesarilly a number from <code>arr</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [4,9,3], target = 10
<strong>Output:</strong> 3
<strong>Explanation:</strong> When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [2,3,5], target = 10
<strong>Output:</strong> 5
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [60864,25176,27249,21296,20204], target = 56803
<strong>Output:</strong> 11361
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^4</code></li>
	<li><code>1 &lt;= arr[i], target &lt;= 10^5</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Binary Search

```cpp
// OJ: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findBestValue(vector<int>& arr, int tar) {
        int n = arr.size(), ans = INT_MAX, dif = INT_MAX, l = 0, r = *max_element(arr.begin(), arr.end());
        
        while (l <= r){
            int m = (l + r) / 2, cnt = 0;
            for (auto &i: arr)
                cnt += i > m ? m : i;
            
            if (abs(cnt - tar) <= dif){
                if (abs(cnt - tar) == dif)
                    ans = min(ans, m);
                else
                    ans = m;
                dif = abs(cnt - tar);
            }
            if (cnt - tar >= 0)
                r = m - 1;
            else
                l = m + 1;
        }
        return ans;
    }
};
```


## Solution 3. 

https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/discuss/463268/JavaC%2B%2B-4ms-binary-search-short-readable-code-%2B-sorting-solution
