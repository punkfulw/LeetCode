# [658. Find K Closest Elements (Medium)](https://leetcode.com/problems/find-k-closest-elements/)

<p>Given a <strong>sorted</strong> integer array <code>arr</code>, two integers <code>k</code> and <code>x</code>, return the <code>k</code> closest integers to <code>x</code> in the array. The result should also be sorted in ascending order.</p>

<p>An integer <code>a</code> is closer to <code>x</code> than an integer <code>b</code> if:</p>

<ul>
	<li><code>|a - x| &lt; |b - x|</code>, or</li>
	<li><code>|a - x| == |b - x|</code> and <code>a &lt; b</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> arr = [1,2,3,4,5], k = 4, x = 3
<strong>Output:</strong> [1,2,3,4]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> arr = [1,2,3,4,5], k = 4, x = -1
<strong>Output:</strong> [1,2,3,4]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= arr.length</code></li>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>4</sup></code></li>
	<li><code>arr</code> is sorted in <strong>ascending</strong> order.</li>
	<li><code>-10<sup>4</sup> &lt;= arr[i], x &lt;= 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Guess Number Higher or Lower (Easy)](https://leetcode.com/problems/guess-number-higher-or-lower/)
* [Guess Number Higher or Lower II (Medium)](https://leetcode.com/problems/guess-number-higher-or-lower-ii/)
* [Find K-th Smallest Pair Distance (Hard)](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-k-closest-elements/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/find-k-closest-elements/discuss/106426/JavaC%2B%2BPython-Binary-Search-O(log(N-K)-%2B-K)
// Time: O(log(N - K))
// Space: O(1)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size()-k;
        while (left < right){
            int mid = (left + right) / 2;
            if (x - arr[mid] > arr[mid+k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int> (arr.begin() + left, arr.begin() + left + k);
    }
};
```

## Solution 2. Two Pointer

```cpp
// OJ: https://leetcode.com/problems/find-k-closest-elements/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        arr.insert(arr.begin(), INT_MIN);
        arr.push_back(INT_MAX);
        auto r = upper_bound(arr.begin(), arr.end(), x), l = r - 1;
        
        while (r - l <= k){
            if (r == arr.end() - 1)
                l--;
            else if (l == arr.begin())
                r++;
            else {
                if (abs(*r - x) < abs(*l - x))
                    r++;
                else
                    l--;
            }
        }
        return vector<int> (l + 1, r);
    }
};
```

