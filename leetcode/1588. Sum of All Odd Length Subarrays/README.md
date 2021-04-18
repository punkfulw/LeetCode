# [1588. Sum of All Odd Length Subarrays (Easy)](https://leetcode.com/problems/sum-of-all-odd-length-subarrays/)

<p>Given an array of positive integers&nbsp;<code>arr</code>, calculate the sum of all possible odd-length subarrays.</p>

<p>A subarray is a contiguous&nbsp;subsequence of the array.</p>

<p>Return&nbsp;<em>the sum of all odd-length subarrays of&nbsp;</em><code>arr</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,4,2,5,3]
<strong>Output:</strong> 58
<strong>Explanation: </strong>The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,2]
<strong>Output:</strong> 3
<b>Explanation: </b>There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [10,11,12]
<strong>Output:</strong> 66
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 100</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 1000</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
// Author: github.com/punkfulw
// Time: O(N^3)
// Space: O(1)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int size = arr.size();
        int ans = accumulate(arr.begin(), arr.end(), 0);

        for (int i = 0; i < size; i++){
            if (i + 2 > size)
                break;
            int j = i + 2;
            while (j < size){
                for (int u = i; u <= j; u++){
                    ans += arr[u];
                }
                j += 2;
            }
        }
        return ans;
    }
};
```


## Solution 2. Count contribution of `A[i]`

How many subarrays that contain `A[i]`?

Count the subarrays that start with `A[i]`, i.e. `i + 1` .

Then count the subarray that end with `A[i]`, i.e. `N - i` .

So there are in total `k = (i + 1) * (N - i)` subarrays containing `A[i]`.

How many of them are of odd length?

So the pattern is that the odd count is `ceil(k / 2) = (k + 1) / 2`.

Thus `A[i]` will be counted `((i + 1) * (N - i) + 1) / 2` times.


```cpp
// OJ: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
// Ref: https://www.youtube.com/watch?v=J5IIH35EBVE
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int N = arr.size();
        int ans {};
        
        for (int i = 0; i < N; i++){
            int end = i + 1;
            int start = N - i;
            int total = end * start;
            int odd = (total + 1) / 2;
            
            ans += arr[i] * odd;
        }
        return ans;
    }
};
```
