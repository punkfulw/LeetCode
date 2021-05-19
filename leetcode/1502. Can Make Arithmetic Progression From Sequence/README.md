# [1502. Can Make Arithmetic Progression From Sequence (Easy)](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/)

<p>A sequence of numbers is called an <b>arithmetic</b> progression if the difference between any two consecutive elements is the same.</p>

<p>Given an array of numbers <code>arr</code>, return <code>true</code> <em>if the array can be rearranged to form an <b>arithmetic progression</b>. Otherwise, return</em> <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [3,5,1]
<strong>Output:</strong> true
<strong>Explanation: </strong>We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,4]
<strong>Output:</strong> false
<strong>Explanation: </strong>There is no way to reorder the elements to obtain an arithmetic progression.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>-10^6 &lt;= arr[i] &lt;= 10^6</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sort](https://leetcode.com/tag/sort/)

## Solution 1. sort

```cpp
// OJ: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int dif = arr[1] - arr[0];
        for (int i = 0; i < arr.size()-1; i++){
            if (arr[i+1] - arr[i] != dif)
                return false;
        }
        return true;
    }
};
```

## Solution 2. count difference

```cpp
// OJ: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/discuss/722307/C%2B%2B-oror-Without-Sort-oror-Set-oror-Easy-to-understand
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        unordered_set<int> s (arr.begin(), arr.end());
        int max = *max_element(arr.begin(), arr.end());
        int min = *min_element(arr.begin(), arr.end());
        int dif = (max - min) / (arr.size()-1);
        for (int i = 1; i < arr.size(); i++){
            if (!s.count(min + i * dif))
                return false;
        }
        return true;
    }
};

```
